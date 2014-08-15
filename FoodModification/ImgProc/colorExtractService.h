#ifndef COLOREXTRACTSERVICE_H
#define COLOREXTRACTSERVICE_H

#include "opencvBase.h"
#include "..\\extractParamManager.h"

class ColorExtractService : public OpenCVBase
{
public:
    ColorExtractService();
    void extract(cv::Mat bgrImg, cv::Mat hsvImg,cv::Mat yCrCbImg, ExtractParamManager* extractParamManager);
    
private:
    void discriminate(int x, int y, cv::Mat bgrImg, cv::Mat hsvImg, cv::Mat yCrCbImg, ColorCriterion* colorCriterion, ColorExtractTolerance* extractTolerance);
    bool isNearNormalPointA(int x, int y, cv::Mat hsvImg, ColorCriterion* colorCriterion) ;
};

#endif // COLOREXTRACTSERVICE_H
