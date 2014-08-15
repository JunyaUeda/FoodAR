#ifndef EXTRACTPARAMMANAGER_H
#define EXTRACTPARAMMANAGER_H
#include <QString>
#include "Param\\colorCriterion.h"
#include "Param\\colorExtractTolerance.h"

class ExtractParamManager
{
public:
    int criterionNum;
    ColorCriterion* criterion;
    ColorExtractTolerance* colorExtractTolerance;
public:
    ExtractParamManager(int criterionNum);

};

#endif // EXTRACTPARAMMANAGER_H
