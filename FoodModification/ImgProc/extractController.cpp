#include "extractController.h"
#include "opencvUtils.h"

#define LINK_EIGHT 8
#define LINK_FOUR 4
#define LINK_CVAA CV_AA

ExtractController::ExtractController(ExtractParamManager *extractParamManager) {
    this->extractParamManager = extractParamManager;
}

void ExtractController::extract(cv::Mat srcBGRImg, cv::Mat srcHSVImg, cv::Mat srcYCrCbImg, cv::Mat srcGrayImg,
	cv::Mat dstImg, cv::Mat* BGREdges) {
	//this.extractByColor(srcBGRImg, srcHSVImg, srcYCrCbImg);
	std::vector<std::vector<cv::Point>> contours = contourService->getTargetContours(srcGrayImg);
	if(contours.size() >0 ) {
		qDebug() << "contours != null" << contours.size();
		//targetParam->setContours(&contours);
	}
    
    cv::Scalar color;
    color = cv::Scalar(255, 255, 255);
    int lineType = LINK_EIGHT;
    int indexOfMaxAreaContour = contourService->getMaxAreaContourIndex(contours);
    //cv::drawContours(dstImg, contours, indexOfMaxAreaContour, color, CV_FILLED, lineType);
    //int indexOfMaxAreaContour = contourService->getMaxAreaContourIndex(targetParam->getContours());
    //cv::drawContours(dstImg, targetParam->getContours(), indexOfMaxAreaContour, color, CV_FILLED, lineType);

    //std::vector<std::vector<cv::Point>> contours = targetParam->getContours();
    //cv::Rect cannyRect = cv::boundingRect(contours[indexOfMaxAreaContur]);
    // cv::imshow("blue", BGRChannels[0]);
    // cv::imshow("green", BGRChannels[1]);
    // cv::imshow("red", BGRChannels[2]);
    // for(int i=0; i<40; i++) {
    //     qDebug() << BGREdges[0].at<unsigned char>(i, i)+BGREdges[1].at<unsigned char>(i, i)+BGREdges[2].at<unsigned char>(i, i);
    // }
    cv::Mat single;
    single = cv::Mat::zeros(srcBGRImg.size(), CV_8UC1);
    for(int y=0; y<single.rows; y++) {
    	for(int x=0; x<single.cols; x++) {
    			VALUE(single, x,y) = VALUE(BGREdges[0], x,y);
    	}
    }
    cv::imshow("single",single);

    cv::Mat total;
    //total.create(srcBGRImg.size(), CV_8UC1);
    total = cv::Mat::zeros(srcBGRImg.size(), CV_8UC1);
    for(int y=0; y<total.rows; y++) {
    	for(int x=0; x<total.cols; x++) {
    		int sum = VALUE(BGREdges[0], x,y) + VALUE(BGREdges[1], x,y) + VALUE(BGREdges[2], x,y);
    		if(sum > 250) {
    			VALUE(total, x,y) = 255;
    		}
    	}
    }
    //cv::imshow("total",total);
    std::vector<std::vector<cv::Point>> contours2 = contourService->getTargetContours(total);
    //cv::findContours(total, contours2, CV_RETR_LIST, CV_CHAIN_APPROX_NONE);
    int indexOfMaxAreaContour2 = contourService->getMaxAreaContourIndex(contours2);
    cv::drawContours(dstImg, contours2, indexOfMaxAreaContour2, color, CV_FILLED, lineType);
    cv::imshow("dstImg",dstImg);
}

void ExtractController::extractByColor(cv::Mat srcBGRImg, cv::Mat srcHSVImg, cv::Mat srcYCrCbImg) {
    this->extractService->extract(srcBGRImg, srcHSVImg, srcYCrCbImg, extractParamManager);
}

void ExtractController::extractByContour(cv::Mat srcGrayImg, cv::Mat dstImg) {
}
