#include "channelThreshold.h"

ChannelThreshold::ChannelThreshold() {
}

ChannelThreshold::ChannelThreshold(ChannelType type) : _channelType(type) {
}

//bool ChannelThreshold::loadAverage(QDomElement element) {
//        _average = XmlUtils::getAttr(element, _channelType.toString()).toInt();
//}

void ChannelThreshold::setThreshold(int average, int tolerance) {
    _average   = average;
    _tolerance = tolerance;
    _upper     = average + tolerance;
    _under     = average - tolerance;
}

QList<ChannelThreshold> ChannelThreshold::createAllChannelThreshold() {
    QList<ChannelThreshold> channelThresholds;

    ChannelThreshold th0(*(new BlueType() ));
    ChannelThreshold th1(*(new GreenType() ));
    ChannelThreshold th2(*(new RedType() ));
    ChannelThreshold th3(*(new HueType() ));
    ChannelThreshold th4(*(new SaturationType() ));
    ChannelThreshold th5(*(new ValueType() ));
    ChannelThreshold th6(*(new YType() ));
    ChannelThreshold th7(*(new CrType() ));
    ChannelThreshold th8(*(new CbType() ));
    channelThresholds.push_back(th0);
    channelThresholds.push_back(th1);
    channelThresholds.push_back(th2);
    channelThresholds.push_back(th3);
    channelThresholds.push_back(th4);
    channelThresholds.push_back(th5);
    channelThresholds.push_back(th6);
    channelThresholds.push_back(th7);
    channelThresholds.push_back(th8);

    return channelThresholds;
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

