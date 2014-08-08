#ifndef EXTRACTPARAMMANAGER_H
#define EXTRACTPARAMMANAGER_H
#include <QString>
#include "colorCriterion.h"
#include "colorExtractTolerance.h"

class ExtractParamManager
{
public:
    ColorCriterion *criterion[2];
    ColorExtractTolerance *colorExtractTolerance[2];
public:
    ExtractParamManager();

};

#endif // EXTRACTPARAMMANAGER_H
