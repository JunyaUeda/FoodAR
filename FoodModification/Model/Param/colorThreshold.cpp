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

void ColorThreshold::addUsedChannelThreshold(ChannelThreshold threshold) {
	_usedChannelThresholds.push_back(threshold);
}

bool ColorThreshold::isWithinThreshold(MatSet* matSet, Point point) {

	for(ChannelThreshold thr : _channelThresholds) {
		if(!thr.isWithinThreshold(matSet, point)) {
			return  false;
		}
	}
	return true;
	
}