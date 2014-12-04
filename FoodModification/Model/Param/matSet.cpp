#include "matSet.h"

MatSet::MatSet() {

}

MatSet::MatSet(const Mat bgr) {
	_bgr = bgr;
	cvtColor(_bgr, _hsv, CV_BGR2HSV);
    cvtColor(_bgr, _ycrcb, CV_BGR2YCrCb);
    cvtColor(_bgr, _gray, CV_BGR2GRAY);
    _width = bgr.cols;
    _height = bgr.rows;
}

map<ChannelType, Mat> MatSet::channelImgs() {
    return _channelImgs;
}

void MatSet::addChannelImgs(SpaceType type) {
    Mat channels[3];
    switch(type) {
        case SpaceType::bgr :
            split(_bgr, channels);
            _channelImgs.insert( map<ChannelType,Mat>::value_type(ChannelType::blue, channels[0]) );
            _channelImgs.insert( map<ChannelType,Mat>::value_type(ChannelType::green, channels[1]) );
            _channelImgs.insert( map<ChannelType,Mat>::value_type(ChannelType::red, channels[2]) );
            break;
        case SpaceType::hsv :
            split(_hsv, channels);
            _channelImgs.insert( map<ChannelType,Mat>::value_type(ChannelType::hue, channels[0]) );
            _channelImgs.insert( map<ChannelType,Mat>::value_type(ChannelType::saturation, channels[1]) );
            _channelImgs.insert( map<ChannelType,Mat>::value_type(ChannelType::value, channels[2]) );
            break;
        case SpaceType::ycrcb :
            split(_ycrcb, channels);
            _channelImgs.insert( map<ChannelType,Mat>::value_type(ChannelType::y, channels[0]) );
            _channelImgs.insert( map<ChannelType,Mat>::value_type(ChannelType::cr, channels[1]) );
            _channelImgs.insert( map<ChannelType,Mat>::value_type(ChannelType::cb, channels[2]) );
            break;

    }
}
