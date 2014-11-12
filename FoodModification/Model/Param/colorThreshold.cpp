#include "colorThreshold.h"

ColorThreshold::ColorThreshold() {
    _channelThresholds = ChannelThreshold::createAllChannelThreshold();
}

void ColorThreshold::updateThresholds(QVi averages, QVi tolerances) {
    for(int i=0; i<averages.size(); i++) {
        _channelThresholds[i].setThreshold(averages[i], tolerances[i]);
    }
}