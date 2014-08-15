#include "extractController.h"


ExtractController::ExtractController(ExtractParamManager *extractParamManager)
{
   // this->extractService = new ColorExtractService;
    this->extractParamManager = extractParamManager;
   // this->contourService = new ContourService;
}

void ExtractController::extractByColor(cv::Mat bgrImg, cv::Mat hsvImg, cv::Mat yCrCbImg) {
    this->extractService->extract(bgrImg, hsvImg, yCrCbImg, extractParamManager);
}

void ExtractController::extractByContour(cv::Mat grayImg, cv::Mat extractedImg) {

        this->contourService->extractByContour(grayImg, extractedImg);
}
