#ifndef EXTRACTPARAMMANAGER_H
#define EXTRACTPARAMMANAGER_H
#include <QString>
#include "Param\\colorCriterion.h"
#include "Param\\colorExtractTolerance.h"
#include "Utils/opencvUtils.h"

class ExtractParamManager
{
public:
    int criterionNum;
    ColorCriterion* criterion;
    ColorExtractTolerance* colorExtractTolerance;
    cv::Mat referenceMat;
    int extractColorSpace;

public:
    ExtractParamManager(int criterionNum);
    
    int getExtractColorSpace() const;
    void setExtractColorSpace(int value);
};

#endif // EXTRACTPARAMMANAGER_H
