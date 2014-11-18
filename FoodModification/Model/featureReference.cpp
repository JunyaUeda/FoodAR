#include "featureReference.h"

FeatureReference::FeatureReference() {
    _colorThresholds.push_back((*new ColorThreshold()));
    _colorThresholds.push_back((*new ColorThreshold()));
}

FeatureReference& FeatureReference::getInstance() {
	static FeatureReference instance;
    return instance;
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

void FeatureReference::updateThresholds(QVis averages, QVis tolerances) {

    QList<ChannelType> types;
    types.push_back(ChannelType::hue);
    types.push_back(ChannelType::saturation);
    types.push_back(ChannelType::value);

    for(int i=0; i<tolerances.size(); i++) {
        _colorThresholds[i].updateThresholds(averages[i], tolerances[i]);
        _colorThresholds[i].updateUsedChannels(types);
    }

    

}

inline ColorThreshold* FeatureReference::getColorThreshold(int value) {

    ColorThreshold* colorThreshold;
    int minDiff = 256;

    // for(ColorThreshold c : _colorThresholds) {
    //     int diff = abs(value - c.channelThresholds()[5].average());
    //     if(minDiff > diff) {
    //         minDiff = diff;
    //         colorThreshold = &c;
    //     }
    // }
    //じぶんでluminance持っておいた方がよりはやい
     if(abs(value - _colorThresholds[0].luminance()) > abs(value - _colorThresholds[1].luminance() ) ){
        return  &_colorThresholds[1];
    }

    //return colorThreshold;
    return &_colorThresholds[0];
}
bool FeatureReference::isWithinThreshold(MatSet& matSet, Point point) {

    ColorThreshold* colorThreshold = getColorThreshold( V(matSet.hsv(), point.x, point.y) );
    if(colorThreshold->isWithinThreshold(matSet, point)) {
        return true;
    }
    return false;
}







