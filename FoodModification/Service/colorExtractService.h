#ifndef COLOREXTRACTSERVICE_H
#define COLOREXTRACTSERVICE_H

#include "../Utils/opencvBase.h"
#include "../extractParamManager.h"

class ColorExtractService : public OpenCVBase {

public:
    ColorExtractService();
    void extract(Mat bgrImg, Mat hsvImg,Mat yCrCbImg, ExtractParamManager* extractParamManager);
    void extractByBGR(Mat bgrImg, Mat dstImg, ExtractParamManager* extractParamManager);
    void extractByHSV(Mat srcImg, Mat dstImg, ExtractParamManager* extractParamManager);

private:
    void discriminate(int x, int y, Mat srcBGRImg, Mat srcHSVImg, Mat srcYCrCbImg, ColorCriterion* colorCriterion, ColorExtractTolerance* extractTolerance);
    bool isNearNormalPointA(int x, int y, Mat hsvImg, ColorCriterion* colorCriterion) ;
    int getIndexOfNearCriterion(int x, int y, Mat diffMap);
    int ColorExtractService::getIndexOfNearCriterionByValue(int x, int y, Mat diffMap);
    Mat getBGRDifferenceMap(Mat srcImg, ColorCriterion* criterion);
    Mat getHSVDifferenceMap(Mat srcImg, ColorCriterion* criterion);
    void classifyByBGR(int x, int y, Mat bgrImg, Mat dstImg, ExtractParamManager* extractParamManager, Mat diffMap);
    void classifyByHSV(int x, int y, Mat srcImg, Mat dstImg, ExtractParamManager* extractParamManager, Mat diffMap);
    int getHSVCriterionIndex(int x, int y, Mat srcImg, ExtractParamManager* extractParamManager);
};

#endif // COLOREXTRACTSERVICE_H
