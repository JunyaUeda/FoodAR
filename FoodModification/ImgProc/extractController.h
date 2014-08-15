#ifndef EXTRACTCONTROLLER_H
#define EXTRACTCONTROLLER_H
#include "opencvBase.h"
#include "..\\extractParamManager.h"
#include "colorExtractService.h"
#include ".\\Service\\contourService.h"

class ExtractController
{
private:
    ColorExtractService *extractService;
    ExtractParamManager *extractParamManager;
    ContourService* contourService;
public:
    ExtractController(ExtractParamManager *extractParamManager);
    void extractByColor(cv::Mat bgrImg, cv::Mat hsvImg, cv::Mat yCrCvImg);
    void extractByContour(cv::Mat grayImg, cv::Mat extractedImg);
};

#endif // EXTRACTCONTROLLER_H
