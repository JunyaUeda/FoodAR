#include "extractController.h"
#include "../Utils/opencvUtils.h"

#define LINK_EIGHT 8
#define LINK_FOUR 4
#define LINK_CVAA CV_AA

ExtractController::ExtractController(ExtractParamManager *extractParamManager) {

    this->extractParamManager = extractParamManager;

}

void ExtractController::extract(Mat srcBGRImg, Mat srcHSVImg, Mat srcYCrCbImg, Mat srcGrayImg,
	Mat dstImg, vector<vector<Point>>& dstContours, Mat* BGREdges) {

    Mat colorExtractedImg;
    colorExtractedImg = dstImg.clone();
    this->extractByColor(srcBGRImg, srcHSVImg, colorExtractedImg);
   // imshow("extractByColor",colorExtractedImg);

    //縮退膨張処理    
    Point ANCHOR = Point(-1,-1);//構造要素内のアンカー位置。デフォルト値の(-1,-1)はアンカーが構造要素の中心にあることを意味する
    int ITERATIONS = 1;
    //erode(colorExtractedImg, colorExtractedImg, cv::Mat(), ANCHOR, ITERATIONS);
    //imshow("after erode",colorExtractedImg);
    dilate(colorExtractedImg, colorExtractedImg, Mat(), ANCHOR, ITERATIONS);//element = cv::Mat()の場合　3×3の矩形構造要素が使われる
    imshow("after dilate",colorExtractedImg);


    vector<vector<Point>> colorExtractedContours;
    findContours(colorExtractedImg, colorExtractedContours, CV_RETR_LIST, CV_CHAIN_APPROX_NONE);

    int MINSIZE = 200; int lineType = LINK_EIGHT;
    fillContours(colorExtractedImg, colorExtractedContours, lineType, MINSIZE);
   // imshow("after drawContours",colorExtractedImg);

    vector< vector<Point> > contours2;
    findContours(colorExtractedImg, contours2, CV_RETR_LIST, CV_CHAIN_APPROX_NONE);

    vector<double> areas(contours2.size());
    vector<Point> mCenters(contours2.size());
    getAreaAndCenters(contours2, areas, mCenters);
    
    Mat dstEdgeImg, dstFilledEdgeImg;
    dstEdgeImg = Mat::zeros(dstImg.size(), CV_8UC1);
    dstFilledEdgeImg = Mat::zeros(dstImg.size(), CV_8UC1);
    compAndFill(dstFilledEdgeImg, dstEdgeImg, BGREdges, contours2, lineType, MINSIZE);
    imshow("dstFilledEdgeImg",dstFilledEdgeImg);
    
    

    // vector<vector<Point> > selectedContours;
    // selectContoursWithPoints(dstFilledEdgeImg, selectedContours, mCenters, 200);
    // qDebug() << "selectedContours" << selectedContours.size();

    // Mat extractedImg;
    // extractedImg = Mat::zeros(dstImg.size(), CV_8UC1);
    // fillContours(extractedImg, selectedContours, lineType, MINSIZE);
    // imshow("fillContours", extractedImg);

    // drawEdge(extractedImg, dstEdgeImg, 0);
    // imshow("draw Edge with black", extractedImg);

    // vector<vector<Point>> contours5;
    // findContours(extractedImg, contours5, CV_RETR_LIST, CV_CHAIN_APPROX_NONE);
    // fillContours(extractedImg, contours5, lineType, MINSIZE);
  
    dstFilledEdgeImg.copyTo(dstImg);
    findContours(dstFilledEdgeImg, dstContours,CV_RETR_LIST, CV_CHAIN_APPROX_NONE);


  //   qDebug() << "last contours size" << dstContours.size();
  //   imshow("fill last", dstEdgeColorImg);
   
}

void ExtractController::drawEdge(Mat srcImg, Mat edgeImg, int luminace) {

    for(int y=0; y<srcImg.rows; y++){
        for(int x=0; x<srcImg.cols; x++) {
            if(L(edgeImg,x,y) == 255) {
                L(srcImg,x,y) = luminace;
            }
        }
    }

}

void ExtractController::selectContoursWithPoints(Mat srcImg, vector<vector<Point> >& selectedContours, vector<Point>& points, int minSize ) {

    vector<vector<Point>> srcContours;
    findContours(srcImg, srcContours, CV_RETR_LIST, CV_CHAIN_APPROX_NONE);

    for(int i=0; i<srcContours.size(); ++i) {
        size_t count = srcContours[i].size();
        if(count < minSize) {
            continue;
        } else {
            for(int j=0; j<points.size(); j++) {
                if(pointPolygonTest(srcContours[i], points[j], false)) {
                    selectedContours.push_back(srcContours[i]);
                   
                }
            }
            
        }
        
    }

}

void ExtractController::compAndFill(Mat dstImg, Mat dstEdgeImg, Mat *Edges, vector<vector<Point> >& contours, int lineType, int minSize) {

    getIntegratedImage(dstImg, dstEdgeImg, Edges, contours);

    fillContours(dstImg, contours, lineType,  minSize);

}

void ExtractController::getAreaAndCenters(vector<vector<Point> >& contours, vector<double>& areas, vector<Point>& mCenters){

    if(contours.size() == areas.size() && contours.size() == mCenters.size()) {
        return;
    }

    //色による抽出領域の面積を求める
    for(int i=0; i<contours.size(); i++) {
        areas[i] = contourArea(contours[i]);
    }

    //色による抽出領域の重心を求める
    calcurateCenter(contours,mCenters);

}

void ExtractController::getIntegratedImage(Mat dstImg, Mat dstEdgeImg, Mat *Edges, vector<vector<Point> >& contours) {

    //エッジ画像を取得する
    this->edgeService->extractEdge(Edges,dstEdgeImg);

    int lineType = LINK_EIGHT;

    vector<Rect> rois(contours.size());
    for(int i=0; i<contours.size(); i++) {
        Rect rect = boundingRect(contours[i]);
        double SCALE_RATIO = 1.2;
        getROI(dstImg.size(), rect, rois[i], SCALE_RATIO);
        
        //色による抽出領域の近辺だけエッジを残す
        for(int y=rois[i].y; y<rois[i].y+rois[i].height; y++){     
            for(int x=rois[i].x; x<rois[i].x+rois[i].width; x++){ 
                if(L(dstEdgeImg,x,y) == 255) {
                    L(dstImg,x,y) = 255;
                }
            }
        }

        //残ったエッジ画像と色による抽出画像を合成する
        drawContours(dstImg, contours, i, Scalar(255, 255, 255), CV_FILLED, lineType);
    }

}

void ExtractController::fillContours(Mat filledImg, vector<vector<Point> >& contours, int lineType, int minSize) {

    if(!contours.empty()) {
        return;
    }

    for(int i=0; i<contours.size(); ++i) {

        size_t count = contours[i].size();
        if(count < minSize) {
            drawContours(filledImg, contours, i, Scalar(0, 0, 0), CV_FILLED, lineType);
        } else {
            drawContours(filledImg, contours, i, Scalar(255, 255, 255), CV_FILLED, lineType);
        }
        
    }

}


void ExtractController::calcurateCenter(vector<vector<Point> >& contours, vector<Point> &mCenters) {

    if(contours.size() != mCenters.size()) {

    }

    vector<Moments> mu(contours.size());
    for(int i=0; i<contours.size(); i++) {
        mu[i] = moments(contours[i], false);
    }
    //std::vector<cv::Point> mCenters(contours2.size());
    for(int i=0; i<contours.size(); i++) {
        mCenters[i] = Point(mu[i].m10/mu[i].m00, mu[i].m01/mu[i].m00);
    }

}

void ExtractController::getROI(Size size, Rect rect, Rect roi, double scaleRatio) {

    int x = (int)rect.x-(rect.width/2.0)*(scaleRatio-1.0);
    int y = (int)rect.y-(rect.height/2.0)*(scaleRatio-1.0);
    int w = rect.width*scaleRatio;
    int h = rect.height*scaleRatio;

    Rect scaleRect = Rect(x, y, w, h);

    int roi_x=0, roi_y=0, roi_w=0, roi_h=0;

    if(scaleRect.x < 0) roi_x=0;
    else roi_x = scaleRect.x;

    if( (scaleRect.x+scaleRect.width) > size.width ) roi_w = size.width - scaleRect.x;
    else roi_w = scaleRect.width;
                
    if(scaleRect.y<0) roi_y=0;
    else roi_y = scaleRect.y;

    if( (scaleRect.y+scaleRect.height) > size.height ) roi_h = size.height - scaleRect.y;
    else roi_h = scaleRect.height;

    rect = Rect(roi_x, roi_y, roi_w, roi_h);

}

void ExtractController::extractByColor(Mat srcBGRImg, Mat srcHSVImg, Mat dstImg) {

    //this->extractService->extract(srcBGRImg, srcHSVImg, srcYCrCbImg, extractParamManager);
    int extractColorSpace = extractParamManager->getExtractColorSpace();

    if(extractColorSpace == 0) {
        this->extractService->extractByBGR(srcBGRImg, dstImg, extractParamManager);
    } else if(extractColorSpace == 1) {
        this->extractService->extractByHSV(srcHSVImg, dstImg, extractParamManager);
    }
    
}

void ExtractController::extractByContour(Mat srcGrayImg, Mat dstImg) {

}
