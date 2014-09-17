#ifndef EXTRACTCONTROLLER_H
#define EXTRACTCONTROLLER_H
#include "../Utils/opencvBase.h"
#include "../extractParamManager.h"
#include "../Service/colorExtractService.h"
#include "../Service/contourService.h"
#include "../Param/targetParam.h"
#include "../Service/edgeService.h"

class ExtractController {

private:
    ExtractParamManager* extractParamManager;
    ColorExtractService* extractService;
    EdgeService* edgeService;
    ContourService* contourService;
    TargetParam* targetParam;

public:
    ExtractController(ExtractParamManager *extractParamManager);
    void ExtractController::extract(cv::Mat srcBGRImg, cv::Mat srcHSVImg, cv::Mat srcYCrCbImg, cv::Mat srcGrayImg,
	cv::Mat dstImg, cv::Mat* BGRChannels);
    void extractByColor(cv::Mat srcBGRImg, cv::Mat srcHSVImg, cv::Mat dstImg);
    void extractByContour(cv::Mat srcGrayImg, cv::Mat dstImg);
    
};

#endif // EXTRACTCONTROLLER_H
