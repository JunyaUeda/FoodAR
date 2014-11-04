#include "xmlReader.h"
#include <QString>
#include "../Utils/xmlUtils.h"


XmlReader::XmlReader(QDomDocument document) {
	_document = document;
}

bool XmlReader::read(QDomDocument document) {
	readExtractColorSpace();
}

void XmlReader::readExtractColorSpace() {
	QString colorSpace_txt = XmlUtils::getAttr(_document, "ExtractColorSpace", "value");

    if(colorSpace_txt == "BGR") {
        _extractParamManager.setExtractColorSpace(0);
    } else if (colorSpace_txt == "HSV") {
        _extractParamManager.setExtractColorSpace(1);
    }
}