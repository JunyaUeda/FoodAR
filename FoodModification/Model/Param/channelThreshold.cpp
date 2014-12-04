#include "channelThreshold.h"

ChannelThreshold::ChannelThreshold() {
}

ChannelThreshold::ChannelThreshold(ChannelFunc* type) : _channelFunc(type) {

}

void ChannelThreshold::setThreshold(int average, int tolerance) {
    _average   = average;
    _tolerance = tolerance;
    _upper     = average + tolerance;
    _under     = average - tolerance;
}

vector<ChannelThreshold> ChannelThreshold::createAllChannelThreshold() {
    vector<ChannelThreshold> channelThresholds;

    ChannelThreshold th0(new BlueFunc());
    ChannelThreshold th1(new GreenFunc());
    ChannelThreshold th2(new RedFunc());
    ChannelThreshold th3(new HueFunc());
    ChannelThreshold th4(new SaturationFunc());
    ChannelThreshold th5(new ValueFunc());
    ChannelThreshold th6(new YFunc());
    ChannelThreshold th7(new CrFunc());
    ChannelThreshold th8(new CbFunc());
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
ChannelFunc* ChannelThreshold::channelFunc() const {
    return _channelFunc;
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

void ChannelThreshold::displayThreshold() {
    qDebug() << _channelFunc->getChannelName();
	qDebug() << "upper" << _upper << "under" << _under;
}
