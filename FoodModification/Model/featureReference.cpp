#include "featureReference.h"

FeatureReference::FeatureReference() {
    _colorThresholds.push_back((*new ColorThreshold()));
    vector<ChannelType> types;
    types.push_back(ChannelType::cr);
    types.push_back(ChannelType::value);
    types.push_back(ChannelType::green);
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

void FeatureReference::updateEngagedChannels(const vector<ChannelType> list, const int thresholdIndex) {
    _colorThresholds[thresholdIndex].updateEngagedChannels(list);
}


void FeatureReference::updateChannelThresholdValue(int degree, ChannelType type, int index) {
    //ほんとはindexによって分けたい。そのためにはUIでいじれるようにすることと
    //Modelの中でcolorThresholdの区別をつけなければいけない
    _colorThresholds[0].updateChannelThresholdValue(degree, type);
    _colorThresholds[1].updateChannelThresholdValue(degree, type);
}


