#include "featureReference.h"

FeatureReference::FeatureReference() {
}

void FeatureReference::loadFeaturesFromFile(QDomDocument doc) {
	loadExtractColorSpace(doc);
	loadAverage(doc);
}

void FeatureReference::loadExtractColorSpace(QDomDocument doc) {
    QString colorSpace_txt = XmlUtils::getAttr(doc, "ExtractColorSpace", "value");

    if(colorSpace_txt == "BGR") {
    	qDebug() << "colorSpace = BGR";
        _extractParamManager.setExtractColorSpace(0);
    } else if (colorSpace_txt == "HSV") {
    	qDebug() << "colorSpace = HSV";
        _extractParamManager.setExtractColorSpace(1);
    }
}

void FeatureReference::loadAverage(QDomDocument doc) {
	QDomElement root = doc.firstChildElement();
    QDomNodeList nodes = root.elementsByTagName("Average");
    qDebug() << "loadAverage";
    for(int i =0;  i<nodes.count(); i++ ) {

        QDomElement element = nodes.at(i).toElement();

        _threshold->loadThreshold(element);
        qDebug() << "loadThreshold";
    }
}
