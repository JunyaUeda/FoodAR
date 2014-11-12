#include "propertyController.h"
#include <QtCore>
#include <QtXml>

#define FILEPATH "../FoodModification/ExtractParam.xml"

PropertyController::PropertyController() {

    readFile(FILEPATH);

}

PropertyController& PropertyController::getInstance() {

    static PropertyController instance;
    return instance;

}

void PropertyController::readFile(QString filePath) {

    _document = XmlUtils::getQDomDoc(filePath);
    qDebug() << "start to loadFromFile";
	_featureReference.loadFeaturesFromFile(_document);
    readExtractColorSpace();
    readColorCriterion();
    readColorExtractTolerance();
    
}

void PropertyController::readExtractColorSpace() {
 
    QString colorSpace_txt = XmlUtils::getAttr(_document, "ExtractColorSpace", "value");

    if(colorSpace_txt == "BGR") {
        _extractParamManager.setExtractColorSpace(0);
    } else if (colorSpace_txt == "HSV") {
        _extractParamManager.setExtractColorSpace(1);
    }
    
}

void PropertyController::readColorCriterion() {
    
    QDomElement root = _document.firstChildElement();
    ColorCriterion* criterion = _extractParamManager.criterion;

    QDomNodeList nodes = root.elementsByTagName("Criterion");

    for(int i =0;  i<nodes.count(); i++ ) {

        QDomElement element = nodes.at(i).toElement();

        criterion[i].setHue(XmlUtils::getAttr(element, "hue").toInt());
        criterion[i].setSaturation(XmlUtils::getAttr(element, "saturation").toInt());
        criterion[i].setValue(XmlUtils::getAttr(element, "value").toInt());
        criterion[i].setBlue(XmlUtils::getAttr(element, "blue").toInt());
        criterion[i].setGreen(XmlUtils::getAttr(element, "green").toInt());
        criterion[i].setRed(XmlUtils::getAttr(element, "red").toInt());
        criterion[i].setY(XmlUtils::getAttr(element, "Y").toInt());
        criterion[i].setCr(XmlUtils::getAttr(element, "Cr").toInt());
        criterion[i].setCb(XmlUtils::getAttr(element, "Cb").toInt());

    }

 }

void PropertyController::readColorExtractTolerance() {

    QDomElement root = _document.firstChildElement();
    ColorExtractTolerance* tolerance = _extractParamManager.colorExtractTolerance;

    QDomNodeList nodes = root.elementsByTagName("ColorExtractTolerance");

    for(int i=0; i<nodes.count(); i++) {

        QDomElement element = nodes.at(i).toElement();
        
        tolerance[i].setHueHighTolerance(XmlUtils::getAttr(element, "hue", "high").toInt());
        tolerance[i].setSaturationHighTolerance(XmlUtils::getAttr(element, "saturation", "high").toInt());
        tolerance[i].setValueHighTolerance(XmlUtils::getAttr(element, "value", "high").toInt());
        tolerance[i].setHueLowTolerance(XmlUtils::getAttr(element, "hue", "low").toInt());
        tolerance[i].setSaturationLowTolerance(XmlUtils::getAttr(element, "saturation", "low").toInt());
        tolerance[i].setValueLowTolerance(XmlUtils::getAttr(element, "value", "low").toInt());

        tolerance[i].setBlueHighTolerance(XmlUtils::getAttr(element, "blue", "high").toInt());
        tolerance[i].setGreenHighTolerance(XmlUtils::getAttr(element, "green", "high").toInt());
        tolerance[i].setRedHighTolerance(XmlUtils::getAttr(element, "red", "high").toInt());
        tolerance[i].setBlueLowTolerance(XmlUtils::getAttr(element, "blue", "low").toInt());
        tolerance[i].setGreenLowTolerance(XmlUtils::getAttr(element, "green", "low").toInt());
        tolerance[i].setRedLowTolerance(XmlUtils::getAttr(element, "red", "low").toInt());

    }

}




void PropertyController::save() {
    
    QFile file(FILEPATH);
    if (file.open(QFile::WriteOnly| QFile::Truncate)) {

        QDomDocument dstDoc = _document.cloneNode(true).toDocument(); 
        QDomElement root = dstDoc.firstChildElement();

        writeExtractColorSpace(&root);
        writeColorCriterion(&root);
        writeColorExtractTolerance(&root);
        
        QTextStream out(&file);
        const int Indent = 4;
        dstDoc.save(out, Indent);
    } else {
        qDebug() << "not Open";
        
    }

}

void PropertyController::writeExtractColorSpace(QDomElement* root) {

    int colorSpace_int = _extractParamManager.getExtractColorSpace();
    QDomElement element = (*root).firstChildElement("ExtractColorSpace");
    if(colorSpace_int == 0) {
        element.setAttribute("value", "BGR");
    } else if (colorSpace_int == 1) {
        element.setAttribute("value", "HSV");
    }
    
}

void PropertyController::writeColorCriterion(QDomElement* root) {

    QDomNodeList nodes = (*root).elementsByTagName("Criterion");
    ColorCriterion* criterion = _extractParamManager.criterion;

    for(int i =0;  i<nodes.count(); i++ ) {
        QDomElement element = nodes.at(i).toElement();
        element.setAttribute("hue", QString::number(criterion[i].getHue()));
        element.setAttribute("saturation", QString::number(criterion[i].getSaturation()));
        element.setAttribute("value", QString::number(criterion[i].getValue()));
        element.setAttribute("blue", QString::number(criterion[i].getBlue()));
        element.setAttribute("green", QString::number(criterion[i].getGreen()));
        element.setAttribute("red", QString::number(criterion[i].getRed()));
        element.setAttribute("Y", QString::number(criterion[i].getY()));
        element.setAttribute("Cr", QString::number(criterion[i].getCr()));
        element.setAttribute("Cb", QString::number(criterion[i].getCb()));

    }

}

void PropertyController::writeColorExtractTolerance(QDomElement* root) {

    ColorExtractTolerance* tolerance = _extractParamManager.colorExtractTolerance;

    QDomNodeList nodes = (*root).elementsByTagName("ColorExtractTolerance");

    for(int i=0; i<nodes.count(); i++) {

        QDomElement element = nodes.at(i).toElement();
        
        XmlUtils::setAttr(element, "hue", "high", tolerance[i].getHueHighTolerance() );
        XmlUtils::setAttr(element, "saturation", "high", tolerance[i].getSaturationHighTolerance() );
        XmlUtils::setAttr(element, "value", "high", tolerance[i].getValueHighTolerance() );
        XmlUtils::setAttr(element, "hue", "low", tolerance[i].getHueLowTolerance() );
        XmlUtils::setAttr(element, "saturation", "low", tolerance[i].getSaturationLowTolerance() );
        XmlUtils::setAttr(element, "value", "low", tolerance[i].getValueLowTolerance() );
        XmlUtils::setAttr(element, "blue", "high", tolerance[i].getBlueHighTolerance() );
        XmlUtils::setAttr(element, "green", "high", tolerance[i].getGreenHighTolerance() );
        XmlUtils::setAttr(element, "red", "high", tolerance[i].getRedHighTolerance() );
        XmlUtils::setAttr(element, "blue", "low", tolerance[i].getBlueLowTolerance() );
        XmlUtils::setAttr(element, "green", "low", tolerance[i].getGreenLowTolerance() );
        XmlUtils::setAttr(element, "red", "low", tolerance[i].getRedLowTolerance() );
    }

}
