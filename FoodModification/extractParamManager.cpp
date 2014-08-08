#include "extractParamManager.h"

ExtractParamManager::ExtractParamManager()
{
    this->colorExtractTolerance[2] = new ColorExtractTolerance[2];
    this->criterion[2] = new ColorCriterion[2];
}

