#ifndef PROPERTYCONTROLLER_H
#define PROPERTYCONTROLLER_H
#include <QString>
#include <QDomElement>
#include "extractParamManager.h"
#include "colorCriterion.h"

class PropertyController
{
private:
    ExtractParamManager * extractParamManager;

public:

private:
    int getIntParamByTagName(QString tag, QDomElement inElement);

public:
    PropertyController(ExtractParamManager *extractParamManager);
    bool readParameters(QString filePath);
    void setColorCriterion(QDomElement root, ColorCriterion *criterion);
};

#endif // PROPERTYCONTROLLER_H
