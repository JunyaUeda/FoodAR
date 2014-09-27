#ifndef EXTRACTPARAMMANAGER_H
#define EXTRACTPARAMMANAGER_H
#include <QString>
#include "Param/colorCriterion.h"
#include "Param/colorExtractTolerance.h"
#include "Utils/opencvUtils.h"

class ExtractParamManager
{
public:
    int criterionNum;
    ColorCriterion* criterion;
    ColorExtractTolerance* colorExtractTolerance;
    cv::Mat referenceMat;
    int extractColorSpace;

    static ExtractParamManager& getInstance();
    int getExtractColorSpace() const;
    void setExtractColorSpace(int value);

private:
	ExtractParamManager();
	ExtractParamManager(const ExtractParamManager&);

};

#endif // EXTRACTPARAMMANAGER_H
