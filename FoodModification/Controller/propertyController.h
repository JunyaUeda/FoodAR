#ifndef PROPERTYCONTROLLER_H
#define PROPERTYCONTROLLER_H
#include <QString>
#include <QDomElement>
#include "../extractParamManager.h"
#include "../Param/colorCriterion.h"
#include "../Param/colorExtractTolerance.h"

class PropertyController {
    
public:
    static PropertyController& getInstance();
    void readFile();
    bool readParameters();
    void setColorCriterion(QDomElement root, ColorCriterion* criterion);
    void setColorExtractTolerance(QDomElement root, ColorExtractTolerance* tolerance);
    ExtractParamManager* getExtractParamManager();
    QString getStringParamByTagName(QString tag, QDomElement inElement);
    void readExtractColorSpace(QDomElement root);


private:
    ExtractParamManager& extractParamManager = ExtractParamManager::getInstance();
    QDomDocument document; //create a document to write XML
    QDomElement domRoot;

    PropertyController();
    PropertyController(const PropertyController&);
    int getColorCriterionNum();
    int getIntParamByTagName(QString tag, QDomElement inElement);


 };

#endif // PROPERTYCONTROLLER_H
