#ifndef PROPERTYCONTROLLER_H
#define PROPERTYCONTROLLER_H
#include <QString>
#include <QDomElement>
#include "extractParamManager.h"
#include "Param\\colorCriterion.h"

class PropertyController
{
private:
    ExtractParamManager * extractParamManager;
    QDomDocument document; //create a document to write XML
    QDomElement domRoot;

public:

private:
    int getColorCriterionNum();
    int getIntParamByTagName(QString tag, QDomElement inElement);
public:
    PropertyController(QString filePath);
    bool readParameters();
    void setColorCriterion(QDomElement root, ColorCriterion* criterion);
    ExtractParamManager* getExtractParamManager();
 };

#endif // PROPERTYCONTROLLER_H
