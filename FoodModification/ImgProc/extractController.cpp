#include "extractController.h"


ExtractController::ExtractController(ExtractParamManager *extractParamManager) {
    this->extractParamManager = extractParamManager;
}

void ExtractController::extract(cv::Mat srcBGRImg, cv::Mat srcHSVImg, cv::Mat srcYCrCbImg, cv::Mat srcGrayImg,
	cv::Mat dstImg) {
	//this.extractByColor(srcBGRImg, srcHSVImg, srcYCrCbImg);
    this->targetParam->setContours(contourService->getTargetContours(srcGrayImg));
	this->extractByContour(srcGrayImg, dstImg);
}

void ExtractController::extractByColor(cv::Mat srcBGRImg, cv::Mat srcHSVImg, cv::Mat srcYCrCbImg) {
    this->extractService->extract(srcBGRImg, srcHSVImg, srcYCrCbImg, extractParamManager);
}

void ExtractController::extractByContour(cv::Mat srcGrayImg, cv::Mat dstImg) {

    this->contourService->extractByContour(srcGrayImg, dstImg);
}
