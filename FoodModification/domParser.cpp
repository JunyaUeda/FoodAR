#include "domParser.h"
#include <QtXml>
#include <QDebug>
#include <QtCore>

DomParser::DomParser(){

}


//void DomParser::parseElements2ndLevel(QDomElement root, QString tag, QString attribute) {
//
//}

void DomParser::parseElements(QDomElement root, QString tag, QString attribute) {

    QDomNodeList nodes = root.elementsByTagName(tag);

    qDebug() << "# nodes =" << nodes.count();
    for(int i=0; i<nodes.count(); i++) {
        QDomNode element = nodes.at(i);
        if(element.isElement()) {
            QDomElement e = element.toElement();
            qDebug() << e.attribute(attribute);
        }
    }

}

