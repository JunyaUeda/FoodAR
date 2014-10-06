#ifndef EXTRACTPARAMMANAGER_H
#define EXTRACTPARAMMANAGER_H
#include <QString>
#include "Param/colorCriterion.h"
#include "Param/colorExtractTolerance.h"
#include "Utils/opencvUtils.h"

class ExtractParamManager {
public:
    int criterionNum;
    ColorCriterion* criterion;
    ColorExtractTolerance* colorExtractTolerance;
    Mat referenceMat;
    int extractColorSpace;

    static ExtractParamManager& getInstance();
    int getExtractColorSpace() const;
    void setExtractColorSpace(int value);

    int getCriterionNum() const;
    void setCriterionNum(int value);

	vector<int> toleranceShift() const;
	void setToleranceShift(const vector<int> &toleranceShift);

private:
	vector<int> _toleranceShift;
	ExtractParamManager();
	ExtractParamManager(const ExtractParamManager&);

};

#endif // EXTRACTPARAMMANAGER_H
