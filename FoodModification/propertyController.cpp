#include "propertyController.h"
#include <QtCore>
#include <QtXml>
#include "domParser.h"

PropertyController::PropertyController(QString filePath)
{

     // Open a file for reading
     QFile file(filePath);
     if(!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qDebug() << "Failed to open the file for reading1.";
        //return false;
     } else {
        //loding
         if (!this->document.setContent(&file)) {
            qDebug() << "Failed to load the file for readingi2.";
          //  return false;
        }
        file.close();
    }

    //Getting root element
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
    return true;
    
}

int PropertyController::getIntParamByTagName(QString tag, QDomElement inElement) {

    QDomElement element = inElement.firstChildElement(tag);
    QString text = element.text();

    return text.toInt();

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
            tolerance[i].setHueTolerance(getIntParamByTagName("hueTolerance", element));
            tolerance[i].setSaturationTolerance(getIntParamByTagName("saturationTolerance", element));
            tolerance[i].setValueTolerance(getIntParamByTagName("valueTolerance", element));
            tolerance[i].setCrTolerance(getIntParamByTagName("crTolerance", element));
        }
    }
}

ExtractParamManager* PropertyController::getExtractParamManager() {
    return this->extractParamManager;
}

