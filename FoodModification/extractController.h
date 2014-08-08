#ifndef EXTRACTCONTROLLER_H
#define EXTRACTCONTROLLER_H
#include "opencvBase.h"
#include "extractParamManager.h"
#include "colorExtractService.h"

class ExtractController
{
private:
    ColorExtractService *extractService;
    ExtractParamManager *extractParamManager;
public:
    ExtractController(ExtractParamManager *extractParamManager);
    void extractByColor(cv::Mat bgrImg, cv::Mat hsvImg, cv::Mat yCrCvImg);
};

#endif // EXTRACTCONTROLLER_H
