#include "colorThreshold.h"

ColorThreshold::ColorThreshold() {
    _channelThresholds = ChannelThreshold::createAllChannelThreshold();
    addEngagedChannelThreshold(_channelThresholds[6]);
    addEngagedChannelThreshold(_channelThresholds[7]);
    addEngagedChannelThreshold(_channelThresholds[8]);
}

vector<ChannelThreshold> ColorThreshold::channelThresholds() const {
    return _channelThresholds;
}

void ColorThreshold::setChannelThresholds(const vector<ChannelThreshold> &channelThresholds) {
    _channelThresholds = channelThresholds;
}

void ColorThreshold::updateThresholds(QVi averages, QVi tolerances) {
    for(int i=0; i<averages.size(); i++) {
        _channelThresholds[i].setThreshold(averages[i], tolerances[i]);
    }
    _luminance = _channelThresholds[5].average();
}

void ColorThreshold::addEngagedChannelThreshold(ChannelThreshold& threshold) {
	_engagedChannelThresholds.push_back(&threshold);
}


void ColorThreshold::updateEngagedChannels(vector<ChannelType> channelTypes) {
    _engagedChannelThresholds.clear();
    for(ChannelType type : channelTypes) {
        switch(type) {
            case ChannelType::blue :
            addEngagedChannelThreshold(_channelThresholds[0]);
            break;
            case ChannelType::green :
            addEngagedChannelThreshold(_channelThresholds[1]);
            break;
            case ChannelType::red :
            addEngagedChannelThreshold(_channelThresholds[2]);
            break;
            case ChannelType::hue :
            addEngagedChannelThreshold(_channelThresholds[3]);
            break;
            case ChannelType::saturation :
            addEngagedChannelThreshold(_channelThresholds[4]);
            break;
            case ChannelType::value :
            addEngagedChannelThreshold(_channelThresholds[5]);
            break;
            case ChannelType::y :
            addEngagedChannelThreshold(_channelThresholds[6]);
            break;
            case ChannelType::cr :
            addEngagedChannelThreshold(_channelThresholds[7]);
            break;
            case ChannelType::cb :
            addEngagedChannelThreshold(_channelThresholds[8]);
            break;
        }
    }
}

void ColorThreshold::updateChannelThresholdValue(int degree, ChannelType type) {
    int channelNumber = static_cast<int>(type);
    _channelThresholds[channelNumber].updateVariableTolerance(degree);
}

void ColorThreshold::displayThreshold() {
    for(ChannelThreshold threshold : _channelThresholds) {
        threshold.displayThreshold();
    }
}