#ifndef PROPERTYCONTROLLER_H
#define PROPERTYCONTROLLER_H
#include <QString>
#include <QDomElement>
#include "../extractParamManager.h"
#include "../Param/colorCriterion.h"
#include "../Param/colorExtractTolerance.h"
#include "../Utils/xmlUtils.h"
#include "../Model/featureReference.h"

class PropertyController {
    
public:
    static PropertyController& getInstance();
    void save();

private:
    ExtractParamManager& _extractParamManager = ExtractParamManager::getInstance();
    QDomDocument _document; //create a document to write XML
	FeatureReference&  _featureReference = FeatureReference::getInstance();
    
    PropertyController();
    PropertyController(const PropertyController&);
    void readFile(QString filePath);
    void readColorCriterion();
    void readColorExtractTolerance();
    void readExtractColorSpace();
    void writeColorCriterion(QDomElement* root);
    void writeExtractColorSpace(QDomElement* root);
    void writeColorExtractTolerance(QDomElement* root);
 };

#endif // PROPERTYCONTROLLER_H
