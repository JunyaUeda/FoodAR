#include "extractController.h"
#include "../Utils/opencvUtils.h"

#define LINK_EIGHT 8
#define LINK_FOUR 4
#define LINK_CVAA CV_AA

ExtractController::ExtractController(ExtractParamManager *extractParamManager) {
    this->extractParamManager = extractParamManager;
}

void ExtractController::extract(cv::Mat srcBGRImg, cv::Mat srcHSVImg, cv::Mat srcYCrCbImg, cv::Mat srcGrayImg,
	cv::Mat dstImg, cv::Mat* BGREdges) {
    this->extractByColor(srcBGRImg, dstImg);
    cv::imshow("extractByColor",dstImg);
    // cv::Mat refMat = this->extractParamManager->referenceMat;
    // qDebug() << "rows = " << refMat.rows;
    // int sampledPixelNum = this->extractParamManager->referenceMat.rows;
    // for(int y=0; y<srcBGRImg.rows; y++) {
    //     for(int x=0; x<srcBGRImg.cols; x++) {
    //         int b = B(srcBGRImg,x,y);
    //         for(int i=0; i<sampledPixelNum; i++) {
    //             if(b == BLUE(refMat,i)) {
    //                 qDebug() << "match";
    //             }
    //         }
    //     }
    // }
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

   // std::vector<std::vector<cv::Point>> contours = targetParam->getContours();
    cv::Rect cannyRect = cv::boundingRect(contours[indexOfMaxAreaContour]);
    cannyRect = cv::Rect(cannyRect.x-cannyRect.width*0.2, cannyRect.y-cannyRect.height*0.2, cannyRect.width*1.2, cannyRect.height*1.2);
    int w = srcBGRImg.size().width;
    int h = srcBGRImg.size().height;
    int y_min_canny=0, y_max_canny=h, x_min_canny=0, x_max_canny=w;
	if(cannyRect.x <0) x_min_canny=0;
	else x_min_canny = cannyRect.x;
	if( (cannyRect.x+cannyRect.width) >w) x_max_canny = w;
	else x_max_canny = cannyRect.x+cannyRect.width;
				
	if(cannyRect.y<0) y_min_canny=0;
	else y_min_canny = cannyRect.y;
	if( (cannyRect.y+cannyRect.height) >h) y_max_canny = h;
	else y_max_canny = cannyRect.y+cannyRect.height;

    // cv::imshow("blue", BGRChannels[0]);
    // cv::imshow("green", BGRChannels[1]);
    // cv::imshow("red", BGRChannels[2]);
    // for(int i=0; i<40; i++) {
    //     qDebug() << BGREdges[0].at<unsigned char>(i, i)+BGREdges[1].at<unsigned char>(i, i)+BGREdges[2].at<unsigned char>(i, i);
    // }
    // cv::Mat single;
    // single = cv::Mat::zeros(srcBGRImg.size(), CV_8UC1);
    // for(int y=0; y<single.rows; y++) {
    // 	for(int x=0; x<single.cols; x++) {
    // 			VALUE(single, x,y) = VALUE(BGREdges[0], x,y);
    // 	}
    // }
    // cv::imshow("single",single);

    cv::Mat total;
    //total.create(srcBGRImg.size(), CV_8UC1);
    total = cv::Mat::zeros(srcBGRImg.size(), CV_8UC1);

    for(int y=y_min_canny; y<y_max_canny; y++){		
		for(int x=x_min_canny; x<x_max_canny; x++){	
			int sum = VALUE(BGREdges[0], x,y) + VALUE(BGREdges[1], x,y) + VALUE(BGREdges[2], x,y);
     		if(sum > 250) {
    			VALUE(total, x,y) = 255;
     		}
		}
	}
    // for(int y=0; y<total.rows; y++) {
    // 	for(int x=0; x<total.cols; x++) {
    // 		int sum = VALUE(BGREdges[0], x,y) + VALUE(BGREdges[1], x,y) + VALUE(BGREdges[2], x,y);
    // 		if(sum > 250) {
    // 			VALUE(total, x,y) = 255;
    // 		}
    // 	}
    // }
    cv::imshow("total",total);
    std::vector<std::vector<cv::Point>> contours2 = contourService->getTargetContours(total);
    //cv::findContours(total, contours2, CV_RETR_LIST, CV_CHAIN_APPROX_NONE);
    int indexOfMaxAreaContour2 = contourService->getMaxAreaContourIndex(contours2);
    cv::drawContours(dstImg, contours2, indexOfMaxAreaContour2, color, CV_FILLED, lineType);
    cv::imshow("dstImg",dstImg);
}

void ExtractController::extractByColor(cv::Mat srcBGRImg, cv::Mat dstImg) {
    //this->extractService->extract(srcBGRImg, srcHSVImg, srcYCrCbImg, extractParamManager);
    this->extractService->extractByBGR(srcBGRImg, dstImg, extractParamManager);
}

void ExtractController::extractByContour(cv::Mat srcGrayImg, cv::Mat dstImg) {
}
