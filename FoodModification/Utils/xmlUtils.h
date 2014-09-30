#ifndef XMLUTILS_H
#define XMLUTILS_H
#include <QtCore>
#include <QtXml>
#include <QDomElement>

class XmlUtils
{
public:
    XmlUtils();
    static QDomDocument getQDomDoc(QString filePath);
    static int getInt(QString tag, QDomNode node);
    static QString getQString(QString tag, QDomElement element);
    static QString getAttr(QDomDocument doc, QString tag, QString attrName);
    static QString getAttr(QDomElement element, QString tag, QString attrName);
    static QString getAttr(QDomElement element, QString attrName);
    static void setAttr(QDomElement element, QString tag, QString attrName, int value);
};

#endif // XMLUTILS_H
