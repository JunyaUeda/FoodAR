#include "colorThreshold.h"

ColorThreshold::ColorThreshold() {
    _channelThresholds = ChannelThreshold::createAllChannelThreshold();
}

QList<ChannelThreshold> ColorThreshold::channelThresholds() const {
    return _channelThresholds;
}

void ColorThreshold::setChannelThresholds(const QList<ChannelThreshold> &channelThresholds) {
    _channelThresholds = channelThresholds;
}

void ColorThreshold::updateThresholds(QVi averages, QVi tolerances) {
    for(int i=0; i<averages.size(); i++) {
        _channelThresholds[i].setThreshold(averages[i], tolerances[i]);
    }
}

bool ColorThreshold::isWithinThreshold(int h, int s, int v) {
	if(_channelThresholds[3].under() > h || h > _channelThresholds[3].upper() ) {
		return false;
	}
	if(_channelThresholds[4].under() > s || s > _channelThresholds[4].upper()) {
		return false;
	}
	if(_channelThresholds[5].under() > v || v > _channelThresholds[5].upper()) {
		return false;
	}
	return true;
}