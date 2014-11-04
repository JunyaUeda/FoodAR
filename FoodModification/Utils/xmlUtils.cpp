#include "xmlUtils.h"

XmlUtils::XmlUtils() {
}

QDomDocument XmlUtils::getQDomDoc(QString filePath) {

	QFile file(filePath);
	QDomDocument document;
    if(!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
    //if(!file.open(QFile::ReadOnly | QFile::Text)) {
        qDebug() << "Failed to open the file for reading1.";
    } else {
        QString err;
        int errL, errC;
        if(!document.setContent(&file,false, &err, &errL, &errC)) {
        //if(!document.setContent(&file)) {
            qDebug() << err;
            qDebug() << errL;
            qDebug() << errC;
            qDebug() << "Failed to load the file for reading2.";
        }
        file.close();
    }

    return document;
   
}

int XmlUtils::getInt(QString tag, QDomNode node) {

    QDomElement element = node.firstChildElement(tag);
    QString text = element.text();

    return text.toInt();

}

QString XmlUtils::getQString(QString tag, QDomElement element) {
    
    QDomElement elem = element.firstChildElement(tag);
    QString text = elem.text();

    return text;

}


QString XmlUtils::getAttr(QDomDocument doc, QString tag, QString attrName) {

    QDomElement root = doc.firstChildElement();
    QDomElement element = root.firstChildElement(tag);

    return element.attribute(attrName);

}

QString XmlUtils::getAttr(QDomElement element, QString tag, QString attrName) {

    QDomElement e = element.firstChildElement(tag);
    return e.attribute(attrName);

}

QString XmlUtils::getAttr(QDomElement element, QString attrName) {

    return element.attribute(attrName);

}

void XmlUtils::setAttr(QDomElement element, QString tag, QString attrName, int value) {

    QDomElement e = element.firstChildElement(tag);
    e.setAttribute(attrName, QString::number(value));

}
