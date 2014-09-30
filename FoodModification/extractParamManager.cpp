#include "extractParamManager.h"

ExtractParamManager::ExtractParamManager()
{
	int criterionNum = 2;
    this->criterionNum = criterionNum;
    this->criterion = new ColorCriterion[criterionNum];
    this->colorExtractTolerance = new ColorExtractTolerance[criterionNum];
}

ExtractParamManager& ExtractParamManager::getInstance() {
	static ExtractParamManager instance;
	return instance;
}

int ExtractParamManager::getExtractColorSpace() const
{
    return extractColorSpace;
}

void ExtractParamManager::setExtractColorSpace(int value)
{
    extractColorSpace = value;
}


int ExtractParamManager::getCriterionNum() const
{
    return criterionNum;
}

void ExtractParamManager::setCriterionNum(int value)
{
    criterionNum = value;
}
