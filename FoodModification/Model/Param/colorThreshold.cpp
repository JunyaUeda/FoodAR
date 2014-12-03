#include "colorThreshold.h"

ColorThreshold::ColorThreshold() {
    _channelThresholds = ChannelThreshold::createAllChannelThreshold();
    addEngagedChannelThreshold(_channelThresholds[3]);
    addEngagedChannelThreshold(_channelThresholds[4]);
    addEngagedChannelThreshold(_channelThresholds[5]);
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

bool ColorThreshold::isWithinThreshold(MatSet& matSet, Point point) {

	for(ChannelThreshold* thr : _engagedChannelThresholds) {
		if(!thr->isWithinThreshold(matSet, point)) {
			return  false;
		}
	}
	return true;
	
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

int ColorThreshold::luminance() {
    return _luminance;
}

void ColorThreshold::displayThreshold() {
    for(ChannelThreshold threshold : _channelThresholds) {
        threshold.displayThreshold();
    }
}