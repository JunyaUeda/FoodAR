#include "extractParamManager.h"

ExtractParamManager::ExtractParamManager(int criterionNum)
{
    this->criterionNum = criterionNum;
    this->criterion = new ColorCriterion[criterionNum];
    this->colorExtractTolerance = new ColorExtractTolerance[criterionNum];
}

