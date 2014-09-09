#include "propertyController.h"
#include <QtCore>
#include <QtXml>

PropertyController::PropertyController(QString filePath) {

     QFile file(filePath);
     if(!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qDebug() << "Failed to open the file for reading1.";
        //return false;
     } else {
        if (!this->document.setContent(&file)) {
            qDebug() << "Failed to load the file for readingi2.";
          //  return false;
        }
        file.close();
    }

    this->domRoot = document.firstChildElement();

    this->extractParamManager = new ExtractParamManager(getColorCriterionNum());

     readParameters();

}

int PropertyController::getColorCriterionNum() {

    return getIntParamByTagName("CriterionNum", this->domRoot);

}

bool PropertyController::readParameters() {

    setColorCriterion(this->domRoot,  this->extractParamManager->criterion);
    setColorExtractTolerance(this->domRoot, this->extractParamManager->colorExtractTolerance);
    readExtractColorSpace(this->domRoot);

    return true;

}

int PropertyController::getIntParamByTagName(QString tag, QDomElement inElement) {

    QDomElement element = inElement.firstChildElement(tag);
    QString text = element.text();

    return text.toInt();

}

QString PropertyController::getStringParamByTagName(QString tag, QDomElement inElement) {
    
    QDomElement element = inElement.firstChildElement(tag);
    QString text = element.text();

    return text;

}

void PropertyController::setColorCriterion(QDomElement root, ColorCriterion* criterion) {
    
    QDomNodeList nodes = root.elementsByTagName("Criterion");
    for(int i =0;  i<nodes.count(); i++ ) {
        QDomNode node = nodes.at(i);
        if (node.hasChildNodes()) {
            QDomElement element = node.toElement();
            criterion[i].setHue( getIntParamByTagName("hue", element));
            criterion[i].setSaturation( getIntParamByTagName("saturation", element));
            criterion[i].setValue(getIntParamByTagName("value", element));
            criterion[i].setCr(getIntParamByTagName("cr", element));
        }
       // criterion++;
    }
 }

void PropertyController::setColorExtractTolerance(QDomElement root, ColorExtractTolerance* tolerance) {

    QDomNodeList nodes = root.elementsByTagName("ColorExtractTolerance");
    for(int i=0; i<nodes.count(); i++) {
        QDomNode node = nodes.at(i);
        if(node.hasChildNodes()){
            QDomElement element = node.toElement();
            tolerance[i].setHueHighTolerance(getIntParamByTagName("hueTolerance", element));
            tolerance[i].setSaturationHighTolerance(getIntParamByTagName("saturationTolerance", element));
            tolerance[i].setValueHighTolerance(getIntParamByTagName("valueTolerance", element));
            //tolerance[i].setCrTolerance(getIntParamByTagName("crTolerance", element));
        }
    }

}

ExtractParamManager* PropertyController::getExtractParamManager() {

    return this->extractParamManager;

}

void PropertyController::readExtractColorSpace(QDomElement root) {
 
    QString text = getStringParamByTagName("ExtractColorSpace", root);
    if(text == "BGR") {
        this->extractParamManager->setExtractColorSpace(0);
    } else if (text == "HSV") {
        this->extractParamManager->setExtractColorSpace(1);
    }
    qDebug() << "ExtractColorSpace =" << this->extractParamManager->getExtractColorSpace();

}