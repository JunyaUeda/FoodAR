#include "extractController.h"

#define LINK_EIGHT 8
#define LINK_FOUR 4
#define LINK_CVAA CV_AA

ExtractController::ExtractController(ExtractParamManager *extractParamManager) {
    this->extractParamManager = extractParamManager;
}

void ExtractController::extract(cv::Mat srcBGRImg, cv::Mat srcHSVImg, cv::Mat srcYCrCbImg, cv::Mat srcGrayImg,
	cv::Mat dstImg) {
	//this.extractByColor(srcBGRImg, srcHSVImg, srcYCrCbImg);
    this->targetParam->setContours(contourService->getTargetContours(srcGrayImg));
    cv::Scalar color;
    color = cv::Scalar(255, 255, 255);
    int lineType = LINK_EIGHT;
    int index = contourService->getMaxAreaContourIndex(targetParam->getContours());
    cv::drawContours(dstImg, targetParam->getContours(), index, color, CV_FILLED, lineType);
	//this->extractByContour(srcGrayImg, dstImg);
}

void ExtractController::extractByColor(cv::Mat srcBGRImg, cv::Mat srcHSVImg, cv::Mat srcYCrCbImg) {
    this->extractService->extract(srcBGRImg, srcHSVImg, srcYCrCbImg, extractParamManager);
}

void ExtractController::extractByContour(cv::Mat srcGrayImg, cv::Mat dstImg) {
}
