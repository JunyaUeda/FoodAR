#ifndef DOMPARSER_H
#define DOMPARSER_H
#include <QXmlStreamReader>
#include <QXmlStreamWriter>
#include <QString>
#include <QtXml/QDomElement>
class DomParser
{
public:
    DomParser();
    
public:
    void parseElements(QDomElement root, QString tag, QString attribute);
};

#endif // DOMPARSER_H
