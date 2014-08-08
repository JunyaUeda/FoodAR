#include "propertyController.h"
#include <QtCore>
#include <QtXml>
#include "domParser.h"

PropertyController::PropertyController(ExtractParamManager *extractParamManager)
{
    this->extractParamManager = extractParamManager;
}

bool PropertyController::readParameters(QString filePath) {

     //Create a document to write XML
    QDomDocument document;

     // Open a file for reading
     QFile file(filePath);
    if(!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qDebug() << "Failed to open the file for reading1.";
        return false;
    } else {
        //loding
         if (!document.setContent(&file)) {
            qDebug() << "Failed to load the file for readingi2.";
            return false;
        }
        file.close();
    }

     //Getting root element
    QDomElement root = document.firstChildElement();

     //parse
    DomParser *domParser = new DomParser;
    
    setColorCriterion(root, extractParamManager->criterion[0]);

    return true;
    
}

int PropertyController::getIntParamByTagName(QString tag, QDomElement inElement) {

    QDomElement element = inElement.firstChildElement(tag);
    QString text = element.text();

    return text.toInt();

}

void PropertyController::setColorCriterion(QDomElement root, ColorCriterion *criterion) {
    
    QDomNodeList nodes = root.elementsByTagName("Criterion");
    for(int i =0;  i<nodes.count(); i++ ) {
        QDomNode node = nodes.at(i);
        if (node.hasChildNodes()) {
            QDomElement element = node.toElement();
            criterion->setHue( getIntParamByTagName("hue", element));
            criterion->setSaturation( getIntParamByTagName("saturation", element));
            criterion->setValue(getIntParamByTagName("value", element));
        }
        criterion++;
    }
}
