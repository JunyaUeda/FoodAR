#include "edgeThreshold.h"

EdgeThreshold::EdgeThreshold() {
}

EdgeThreshold::EdgeThreshold(ChannelFunc* type) : _channelFunc(type) {
    _upper = 40;
    _under = 20;
}

int EdgeThreshold::upper() const {
    return _upper;
}
int EdgeThreshold::under() const {
    return _under;
}
void EdgeThreshold::setUpper(const int value) {
    _upper = value;
}
void EdgeThreshold::setUnder(const int value) {
    _under = value;
}

map<ChannelType, EdgeThreshold> EdgeThreshold::createAllEdgeThreshold() {
    map<ChannelType, EdgeThreshold> edgeThresholds;

    EdgeThreshold th0(new BlueFunc());
    EdgeThreshold th1(new GreenFunc());
    EdgeThreshold th2(new RedFunc());
    EdgeThreshold th3(new HueFunc());
    EdgeThreshold th4(new SaturationFunc());
    EdgeThreshold th5(new ValueFunc());
    EdgeThreshold th6(new YFunc());
    EdgeThreshold th7(new CrFunc());
    EdgeThreshold th8(new CbFunc());
    edgeThresholds.insert(pair<ChannelType, EdgeThreshold>(ChannelType::blue, th0));
    edgeThresholds.insert(pair<ChannelType, EdgeThreshold>(ChannelType::green, th1));
    edgeThresholds.insert(pair<ChannelType, EdgeThreshold>(ChannelType::red, th2));
    edgeThresholds.insert(pair<ChannelType, EdgeThreshold>(ChannelType::hue, th3));
    edgeThresholds.insert(pair<ChannelType, EdgeThreshold>(ChannelType::saturation, th4));
    edgeThresholds.insert(pair<ChannelType, EdgeThreshold>(ChannelType::value, th5));
    edgeThresholds.insert(pair<ChannelType, EdgeThreshold>(ChannelType::y, th6));
    edgeThresholds.insert(pair<ChannelType, EdgeThreshold>(ChannelType::cr, th7));
    edgeThresholds.insert(pair<ChannelType, EdgeThreshold>(ChannelType::cb, th8));

    return edgeThresholds;
}