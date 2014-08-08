#include "extractController.h"

ExtractController::ExtractController(ExtractParamManager *extractParamManager)
{
    this->extractService = new ColorExtractService;
    this->extractParamManager = extractParamManager;
}

void ExtractController::extractByColor(cv::Mat bgrImg, cv::Mat hsvImg, cv::Mat yCrCbImg) {
    extractService->extract(bgrImg, hsvImg, yCrCbImg, extractParamManager);
}
