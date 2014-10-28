#ifndef COLOREXTRACTSERVICE_H
#define COLOREXTRACTSERVICE_H

#include "../Utils/opencvBase.h"
#include "../extractParamManager.h"
#include "../definition.h"

class ColorExtractService : public OpenCVBase {

public:
    ColorExtractService();
    void extractByBGR(Mat bgrImg, Mat dstImg, ExtractParamManager* extractParamManager);
    void extractByHSV(Mat srcImg, Mat dstImg, ExtractParamManager* extractParamManager);
    void dilate_erode(Mat src, Mat dst, vector<int> combinations);

private:
    int getIndexOfNearCriterion(int x, int y, Mat diffMap);
    int getIndexOfNearCriterionByValue(int x, int y, Mat diffMap);
    Mat getBGRDifferenceMap(Mat srcImg, ColorCriterion* criterion);
    Mat getHSVDifferenceMap(Mat srcImg, ColorCriterion* criterion);
    void classifyByBGR(int x, int y, Mat bgrImg, Mat dstImg, ExtractParamManager* extractParamManager, Mat diffMap);
    void classifyByHSV(int x, int y, Mat srcImg, Mat dstImg, ExtractParamManager* extractParamManager, Mat diffMap);
    int getHSVCriterionIndex(int x, int y, Mat srcImg, ExtractParamManager* extractParamManager);

};

#endif // COLOREXTRACTSERVICE_H
