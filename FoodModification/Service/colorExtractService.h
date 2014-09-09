#ifndef COLOREXTRACTSERVICE_H
#define COLOREXTRACTSERVICE_H

#include "../Utils/opencvBase.h"
#include "..\\extractParamManager.h"

class ColorExtractService : public OpenCVBase {

public:
    ColorExtractService();
    void extract(cv::Mat bgrImg, cv::Mat hsvImg,cv::Mat yCrCbImg, ExtractParamManager* extractParamManager);
    void extractByBGR(cv::Mat bgrImg, cv::Mat dstImg, ExtractParamManager* extractParamManager);
    void extractByHSV(cv::Mat srcImg, cv::Mat dstImg, ExtractParamManager* extractParamManager);

private:
    void discriminate(int x, int y, cv::Mat srcBGRImg, cv::Mat srcHSVImg, cv::Mat srcYCrCbImg,ColorCriterion* colorCriterion, ColorExtractTolerance* extractTolerance);
    bool isNearNormalPointA(int x, int y, cv::Mat hsvImg, ColorCriterion* colorCriterion) ;
    int getIndexOfNearCriterion(int x, int y, cv::Mat diffMap);
    int ColorExtractService::getIndexOfNearCriterionByValue(int x, int y, cv::Mat diffMap);
    cv::Mat getBGRDifferenceMap(cv::Mat srcImg, ColorCriterion* criterion);
    cv::Mat getHSVDifferenceMap(cv::Mat srcImg, ColorCriterion* criterion);
    void classifyByBGR(int x, int y, cv::Mat bgrImg, cv::Mat dstImg, ExtractParamManager* extractParamManager, cv::Mat diffMap);
    void classifyByHSV(int x, int y, cv::Mat srcImg, cv::Mat dstImg, ExtractParamManager* extractParamManager, cv::Mat diffMap);

};

#endif // COLOREXTRACTSERVICE_H
