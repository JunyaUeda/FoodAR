#include "colorThreshold.h"

ColorThreshold::ColorThreshold() {
    _channelThresholds = ChannelThreshold::createAllChannelThreshold();
    // _usedChannelThresholds.push_back(_channelThresholds[3]);
    // _usedChannelThresholds.push_back(_channelThresholds[4]);
    // _usedChannelThresholds.push_back(_channelThresholds[5]);

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
    _luminance = _channelThresholds[5].average();
}

void ColorThreshold::addUsedChannelThreshold(ChannelThreshold threshold) {
	_usedChannelThresholds.push_back(threshold);
}

bool ColorThreshold::isWithinThreshold(MatSet& matSet, Point point) {

	for(ChannelThreshold thr : _usedChannelThresholds) {
		if(!thr.isWithinThreshold(matSet, point)) {
			return  false;
		}
	}
	return true;
	
}

void ColorThreshold::updateUsedChannels(QList<ChannelType> channelTypes) {
    for(ChannelType type : channelTypes) {
        switch(type) {
            case ChannelType::blue :
            break;
            case ChannelType::green :
            break;
            case ChannelType::red :
            break;
            case ChannelType::hue :
            addUsedChannelThreshold(_channelThresholds[3]);
            break;
            case ChannelType::saturation :
            addUsedChannelThreshold(_channelThresholds[4]);
            break;
            case ChannelType::value :
            addUsedChannelThreshold(_channelThresholds[5]);
            break;
            case ChannelType::y :
            break;
            case ChannelType::cr :
            break;
            case ChannelType::cb :
            break;
        }
    }
}

int ColorThreshold::luminance() {
    return _luminance;
}