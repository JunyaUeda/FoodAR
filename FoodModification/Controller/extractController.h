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
	cv::Mat dstImg, std::vector<std::vector<cv::Point>>& dstContours, cv::Mat* BGRChannels);
    void extractByColor(cv::Mat srcBGRImg, cv::Mat srcHSVImg, cv::Mat dstImg);
    void extractByContour(cv::Mat srcGrayImg, cv::Mat dstImg);
private:    
    void fillContours(cv::Mat filledImg, std::vector<std::vector<cv::Point> >& contours, int minSize);
    void calcurateCenter(std::vector<std::vector<cv::Point>>& contours, std::vector<cv::Point>& mCenters);
    void getROI(cv::Size size, cv::Rect rect, cv::Rect roi, double scaleRatio);
    
};

#endif // EXTRACTCONTROLLER_H
