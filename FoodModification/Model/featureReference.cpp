#include "featureReference.h"

FeatureReference::FeatureReference() {
    _colorThresholds.push_back((*new ColorThreshold()));
    vector<ChannelType> types;
    types.push_back(ChannelType::hue);
    types.push_back(ChannelType::saturation);
    types.push_back(ChannelType::value);
    _colorThresholds[0].updateEngagedChannels(types);
    _colorThresholds.push_back((*new ColorThreshold()));
    _colorThresholds[1].updateEngagedChannels(types);
}

FeatureReference& FeatureReference::getInstance() {
	static FeatureReference instance;
    return instance;
}

void FeatureReference::loadFeaturesFromFile(QDomDocument doc) {

	//loadAverage(doc);
}



void FeatureReference::updateThresholds(QVis averages, QVis tolerances) {

    for(int i=0; i<tolerances.size(); i++) {
        _colorThresholds[i].updateThresholds(averages[i], tolerances[i]);
    }

}

void FeatureReference::displayThreshold() {
    for(ColorThreshold threshold : _colorThresholds) {
        threshold.displayThreshold();
    }
}

inline ColorThreshold* FeatureReference::getColorThreshold(int value) {

    // ColorThreshold* colorThreshold;
    // int minDiff = 256;

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


void FeatureReference::updateEngagedChannels(const vector<ChannelType> list, const int thresholdIndex) {
    _colorThresholds[thresholdIndex].updateEngagedChannels(list);
}


void FeatureReference::updateChannelThresholdValue(int degree, ChannelType type, int index) {
    //ほんとはindexによって分けたい。そのためにはUIでいじれるようにすることと
    //Modelの中でcolorThresholdの区別をつけなければいけない
    _colorThresholds[0].updateChannelThresholdValue(degree, type);
    _colorThresholds[1].updateChannelThresholdValue(degree, type);
}


