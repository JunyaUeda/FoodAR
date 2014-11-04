#include "channelThreshold.h"

ChannelThreshold::ChannelThreshold(ChannelType type) : _channelType(type) {
}

bool ChannelThreshold::loadAverage(QDomElement element) {
        _average = XmlUtils::getAttr(element, _channelType.toString()).toInt();
}

//getter setter
ChannelType ChannelThreshold::channelType() const {
    return _channelType;
}

int ChannelThreshold::average() const {
    return _average;
}

void ChannelThreshold::setAverage(int average) {
    _average = average;
}

int ChannelThreshold::tolerance() const {
    return _tolerance;
}

void ChannelThreshold::setTolerance(int tolerance) {
    _tolerance = tolerance;
}

int ChannelThreshold::upper() const {
    return _upper;
}

void ChannelThreshold::setUpper(int upper) {
    _upper = upper;
}

int ChannelThreshold::under() const {
    return _under;
}

void ChannelThreshold::setUnder(int under) {
    _under = under;
}

