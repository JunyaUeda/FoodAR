#include "extractController.h"
#include "../Utils/opencvUtils.h"

#define LINK_EIGHT 8
#define LINK_FOUR 4
#define LINK_CVAA CV_AA

ExtractController::ExtractController(ExtractParamManager *extractParamManager) {

    this->extractParamManager = extractParamManager;

}

void ExtractController::extract(cv::Mat srcBGRImg, cv::Mat srcHSVImg, cv::Mat srcYCrCbImg, cv::Mat srcGrayImg,
	cv::Mat dstImg,std::vector<std::vector<cv::Point>>& dstContours, cv::Mat* BGREdges) {

    cv::Mat colorExtractedImg;
    colorExtractedImg = dstImg.clone();
    this->extractByColor(srcBGRImg, srcHSVImg, colorExtractedImg);
    cv::imshow("extractByColor",colorExtractedImg);

    //縮退膨張処理    
    cv::Point ANCHOR = cv::Point(-1,-1);//構造要素内のアンカー位置。デフォルト値の(-1,-1)はアンカーが構造要素の中心にあることを意味する
    int ITERATIONS = 1;
    //cv::erode(colorExtractedImg, colorExtractedImg, cv::Mat(), ANCHOR, ITERATIONS);
    //cv::imshow("after erode",colorExtractedImg);
    cv::dilate(colorExtractedImg, colorExtractedImg, cv::Mat(), ANCHOR, ITERATIONS);//element = cv::Mat()の場合　3×3の矩形構造要素が使われる
    cv::imshow("after dilate",colorExtractedImg);

    //cv::cvtColor(colorExtractedImg, colorExtractedImg, CV_BGR2GRAY);

    std::vector<std::vector<cv::Point>> colorExtractedContours;
    cv::findContours(colorExtractedImg, colorExtractedContours, CV_RETR_LIST, CV_CHAIN_APPROX_NONE);

    int MINSIZE = 200; int lineType = LINK_EIGHT;
    fillContours(colorExtractedImg, colorExtractedContours, MINSIZE);
    cv::imshow("after drawContours",colorExtractedImg);

    std::vector< std::vector<cv::Point> > contours2;
    cv::findContours(colorExtractedImg, contours2, CV_RETR_LIST, CV_CHAIN_APPROX_NONE);

    //色による抽出領域の面積を求める
    std::vector<double> areas(contours2.size());
    for(int i=0; i<contours2.size(); i++) {
        areas[i] = cv::contourArea(contours2[i]);
    }

    //色による抽出領域の重心を求める
    std::vector<cv::Point> mCenters(contours2.size());
    calcurateCenter(contours2,mCenters);
    
    //エッジ画像を取得する
    cv::Mat dstEdgeImg;
    dstEdgeImg.create(srcBGRImg.size(), CV_8UC1);
    this->edgeService->extractEdge(BGREdges,dstEdgeImg);


    cv::Mat dstEdgeImg2;
    dstEdgeImg2= cv::Mat::zeros(dstEdgeImg.size(), dstEdgeImg.type());

    std::vector<cv::Rect> rois(contours2.size());

    for(int i=0; i<contours2.size(); i++) {
        cv::Rect rect = cv::boundingRect(contours2[i]);
        double SCALE_RATIO = 1.2;
        getROI(dstEdgeImg.size(), rect, rois[i], SCALE_RATIO);
        
        //色による抽出領域の近辺だけエッジを残す
        for(int y=rois[i].y; y<rois[i].y+rois[i].height; y++){     
            for(int x=rois[i].x; x<rois[i].x+rois[i].width; x++){ 
                if(L(dstEdgeImg,x,y) == 255) {
                    L(dstEdgeImg2,x,y) = 255;
                }
            }
        }

        //残ったエッジ画像と色による抽出画像を合成する
        cv::drawContours(dstEdgeImg2, contours2, i, cv::Scalar(255, 255, 255), CV_FILLED, lineType);
    }
    cv::imshow("dstEdgeImg2",dstEdgeImg2);
    
    std::vector< std::vector<cv::Point> > contours3;
    cv::findContours(dstEdgeImg2, contours3,CV_RETR_LIST, CV_CHAIN_APPROX_NONE);//手を近づけるとruntimeエラーになる
    for(int i=0; i<contours3.size(); i++) {
        cv::drawContours(dstEdgeImg2, contours3, i, cv::Scalar(255, 255, 255), CV_FILLED, lineType);
    }
    cv::imshow("dstEdgeImg2_2",dstEdgeImg2);

    std::vector<std::vector<cv::Point> > contours4;
    for(int i=0; i<contours3.size(); ++i) {
        size_t count = contours3[i].size();
        if(count < 400) {
            continue;
        } else {
            for(int j=0; j<contours2.size(); j++) {
                if(cv::pointPolygonTest(contours3[i],mCenters[j], false)) {
                    contours4.push_back(contours3[i]);
                    // if(areas[j] < cv::contourArea(contours3[i])) {
                    //     contours4.push_back(contours3[i]);
                    // }
                }
            }
            
        }
        
    }

    cv::Mat dstEdgeColorImg;
    dstEdgeColorImg = cv::Mat::zeros(dstImg.size(), dstImg.type());
    


    if(contours4.size() > 0) {
        for(int i=0; i<contours4.size(); i++) {
            size_t count = contours4[i].size();
            cv::drawContours(dstEdgeColorImg, contours4, i, cv::Scalar(255, 255, 255), CV_FILLED, lineType);        
        } 
    } 
    cv::imshow("filled only contours with color centers", dstEdgeColorImg);
    
    cv::Mat dstEdgeImg3;
    dstEdgeImg3 = dstEdgeImg.clone();
    for(int y=0; y<dstEdgeImg3.rows; y++){
        for(int x=0; x<dstEdgeImg3.cols; x++) {
            if(L(dstEdgeImg3,x,y) == 255) {
                L(dstEdgeColorImg,x,y) = 0;
            }
        }
    }

    // for(int i=0; i<contours2.size(); i++) {
    //     cv::circle(dstEdgeColorImg, mCenters[i], 20, cv::Scalar(255,255,255), 5, lineType, 0);
    // }
    cv::imshow("draw Edge with black and draw centers", dstEdgeColorImg);
    std::vector<std::vector<cv::Point>> contours5;
    cv::findContours(colorExtractedImg, contours5, CV_RETR_LIST, CV_CHAIN_APPROX_NONE);
    if(contours5.size() > 0) {
        for(int i=0; i<contours4.size(); i++) {
            cv::drawContours(dstEdgeColorImg, contours5, i, cv::Scalar(255, 255, 255), CV_FILLED, lineType);        
        } 
    } 
    dstEdgeColorImg.copyTo(dstImg);
    cv::findContours(dstEdgeColorImg, dstContours,CV_RETR_LIST, CV_CHAIN_APPROX_NONE);
    qDebug() << "last contours size" << dstContours.size();
    cv::imshow("fill last", dstEdgeColorImg);
   


}

void ExtractController::fillContours(cv::Mat filledImg, std::vector<std::vector<cv::Point> >& contours, int minSize) {

    int lineType = LINK_EIGHT;
    for(int i=0; i<contours.size(); ++i) {

        size_t count = contours[i].size();
        if(count < minSize) {
            cv::drawContours(filledImg, contours, i, cv::Scalar(0, 0, 0), CV_FILLED, lineType);
        } else {
            cv::drawContours(filledImg, contours, i, cv::Scalar(255, 255, 255), CV_FILLED, lineType);
        }
        
    }

}

void ExtractController::calcurateCenter(std::vector<std::vector<cv::Point> >& contours, std::vector<cv::Point> &mCenters) {

    if(contours.size() != mCenters.size()) {

    }

    std::vector<cv::Moments> mu(contours.size());
    for(int i=0; i<contours.size(); i++) {
        mu[i] = cv::moments(contours[i], false);
    }
    //std::vector<cv::Point> mCenters(contours2.size());
    for(int i=0; i<contours.size(); i++) {
        mCenters[i] = cv::Point(mu[i].m10/mu[i].m00, mu[i].m01/mu[i].m00);
    }

}

void ExtractController::getROI(cv::Size size, cv::Rect rect, cv::Rect roi, double scaleRatio) {

    int x = (int)rect.x-(rect.width/2.0)*(scaleRatio-1.0);
    int y = (int)rect.y-(rect.height/2.0)*(scaleRatio-1.0);
    int w = rect.width*scaleRatio;
    int h = rect.height*scaleRatio;

    cv::Rect scaleRect = cv::Rect(x, y, w, h);

    int roi_x=0, roi_y=0, roi_w=0, roi_h=0;

    if(scaleRect.x < 0) roi_x=0;
    else roi_x = scaleRect.x;

    if( (scaleRect.x+scaleRect.width) > size.width ) roi_w = size.width - scaleRect.x;
    else roi_w = scaleRect.width;
                
    if(scaleRect.y<0) roi_y=0;
    else roi_y = scaleRect.y;

    if( (scaleRect.y+scaleRect.height) > size.height ) roi_h = size.height - scaleRect.y;
    else roi_h = scaleRect.height;

    rect = cv::Rect(roi_x, roi_y, roi_w, roi_h);

}

void ExtractController::extractByColor(cv::Mat srcBGRImg, cv::Mat srcHSVImg, cv::Mat dstImg) {

    //this->extractService->extract(srcBGRImg, srcHSVImg, srcYCrCbImg, extractParamManager);
    int extractColorSpace = extractParamManager->getExtractColorSpace();

    if(extractColorSpace == 0) {
        this->extractService->extractByBGR(srcBGRImg, dstImg, extractParamManager);
    } else if(extractColorSpace == 1) {
        this->extractService->extractByHSV(srcHSVImg, dstImg, extractParamManager);
    }
    
}

void ExtractController::extractByContour(cv::Mat srcGrayImg, cv::Mat dstImg) {

}
