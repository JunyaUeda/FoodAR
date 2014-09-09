#ifndef PROPERTYCONTROLLER_H
#define PROPERTYCONTROLLER_H
#include <QString>
#include <QDomElement>
#include "../extractParamManager.h"
#include "../Param\\colorCriterion.h"
#include "../Param\\colorExtractTolerance.h"

class PropertyController {
    
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
    void setColorExtractTolerance(QDomElement root, ColorExtractTolerance* tolerance);
    ExtractParamManager* getExtractParamManager();
    QString PropertyController::getStringParamByTagName(QString tag, QDomElement inElement);
    void PropertyController::readExtractColorSpace(QDomElement root);

 };

#endif // PROPERTYCONTROLLER_H
