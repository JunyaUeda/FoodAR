#ifndef XMLREADER_H
#define XMLREADER_H

#include <QtCore>
#include <QtXml>
#include "../extractParamManager.h"
using namespace std;

class XmlReader {

/*property*/
protected:
	QDomDocument _document;
	ExtractParamManager& _extractParamManager = ExtractParamManager::getInstance();

/*method*/
public:
    XmlReader(QDomDocument document);
    bool read(QDomDocument document);
private:
	void readExtractColorSpace();
};

#endif // XMLREADER_H
