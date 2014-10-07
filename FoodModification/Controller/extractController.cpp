#include "extractController.h"
#include "../Utils/opencvUtils.h"

#define LINK_EIGHT 8
#define LINK_FOUR 4
#define LINK_CVAA CV_AA

ExtractController::ExtractController() {

}

ExtractController& ExtractController::getInstance() {
    static ExtractController instance;
    return instance;
}

void ExtractController::extract(Mat srcBGRImg, Mat srcHSVImg, Mat srcYCrCbImg, Mat srcGrayImg,
	Mat dstImg, vector<vector<Point>>& dstContours, Mat* edgeImgs) {

    Mat colorExtractedImg;
    colorExtractedImg = dstImg.clone();
    extractByColor(srcBGRImg, srcHSVImg, colorExtractedImg);
    imshow("extractByColor",colorExtractedImg);

    //縮退膨張処理
    vector<int> combinations{JU_ERODE, JU_ERODE, JU_ERODE, JU_ERODE};
    _extractService->dilate_erode(colorExtractedImg,colorExtractedImg, combinations);    
    imshow("dilate_erode",colorExtractedImg);

    vector<vector<Point>> colorExtractedContours;
    findContours(colorExtractedImg, colorExtractedContours, CV_RETR_LIST, CV_CHAIN_APPROX_NONE);

    int maxAreaIndex = _contourService->getMaxAreaContourIndex(colorExtractedContours);
    
    int MINSIZE = 200; int lineType = LINK_EIGHT;
    colorExtractedImg = Mat::zeros(dstImg.size(), CV_8UC1);
    // _contourService->fillContours(colorExtractedImg, contours, lineType, MINSIZE);
    // _contourService->fillSpecifiedContour(colorExtractedImg, colorExtractedContours, lineType, MINSIZE, maxAreaIndex);
    drawContours(colorExtractedImg, colorExtractedContours, maxAreaIndex, Scalar(255, 255, 255), CV_FILLED, lineType);
    imshow("find&drawContours",colorExtractedImg);

    vector< vector<Point> > contours2;
    findContours(colorExtractedImg, contours2, CV_RETR_LIST, CV_CHAIN_APPROX_NONE);

    vector<double> areas(contours2.size());
    vector<Point> mCenters(contours2.size());
    _contourService->contourAreasAndCenters(contours2, areas, mCenters);
    
    Mat dstEdgeImg;
    dstEdgeImg       = Mat::zeros(dstImg.size(), CV_8UC1);
    

    getIntegratedImage(colorExtractedImg, dstEdgeImg, edgeImgs, contours2);
    imshow("+Edge",colorExtractedImg);

    vector< vector<Point> > contours3;
    Mat refImg = colorExtractedImg.clone();
    findContours(refImg, contours3, CV_RETR_LIST, CV_CHAIN_APPROX_NONE);
    //Mat dstFilledEdgeImg;
    //dstFilledEdgeImg = Mat::zeros(dstImg.size(), CV_8UC1);
    int minsize = 0;
    _contourService->fillContours(colorExtractedImg, contours3, lineType,  minsize);
    imshow("FilledEdgeImg",colorExtractedImg);
    
    

    // vector<vector<Point> > selectedContours;
    // _contourService->selectContoursWithPoints(dstFilledEdgeImg, selectedContours, mCenters, 200);
    // qDebug() << "selectedContours" << selectedContours.size();

    // Mat extractedImg;
    // extractedImg = Mat::zeros(dstImg.size(), CV_8UC1);
    // fillContours(extractedImg, selectedContours, lineType, MINSIZE);
    // imshow("fillContours", extractedImg);

    // _edgeService->drawEdge(extractedImg, dstEdgeImg, 0);
    // imshow("draw Edge with black", extractedImg);

    // vector<vector<Point>> contours5;
    // findContours(extractedImg, contours5, CV_RETR_LIST, CV_CHAIN_APPROX_NONE);
    // fillContours(extractedImg, contours5, lineType, MINSIZE);
  
    colorExtractedImg.copyTo(dstImg);
    findContours(colorExtractedImg, dstContours,CV_RETR_LIST, CV_CHAIN_APPROX_NONE);


  //   qDebug() << "last contours size" << dstContours.size();
  //   imshow("fill last", dstEdgeColorImg);
   
}


void ExtractController::getIntegratedImage(Mat dstImg, Mat dstEdgeImg, Mat *Edges, vector<vector<Point> >& contours) {

    //エッジ画像を取得する
    _edgeService->extractEdge(Edges,dstEdgeImg);

    int lineType = LINK_EIGHT;

    vector<Rect> rois(contours.size());
    for(int i=0; i<contours.size(); i++) {

        Rect rect = boundingRect(contours[i]);
        double SCALE_RATIO = 1.0;
        rois[i] = OpenCVUtils::calculateROI(dstImg.size(), rect, SCALE_RATIO);
        
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

void ExtractController::extractByColor(Mat srcBGRImg, Mat srcHSVImg, Mat dstImg) {

    int extractColorSpace = extractParamManager.getExtractColorSpace();

    if(extractColorSpace == JU_BGR) {
        _extractService->extractByBGR(srcBGRImg, dstImg, &extractParamManager);
    } else if(extractColorSpace == JU_HSV) {
        _extractService->extractByHSV(srcHSVImg, dstImg, &extractParamManager);
    }
    
}

void ExtractController::extractByContour(Mat srcGrayImg, Mat dstImg) {

}
