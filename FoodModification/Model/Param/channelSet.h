#ifndef CHANNELSET_H
#define CHANNELSET_H

#include "../TypeDef.h"
#include "../SDK/opencv/opencvApi.h"
#include "./matSet.h"

class ChannelSet {

/*method*/
public:
	ChannelSet();
    ChannelSet(MatSet& srcSet) {

        split(srcSet.blur(), _bgrChannels);
        split(srcSet.hsv(), _hsvChannels);
        split(srcSet.ycrcb(), _ycrcbChannels);

        _channelMats.insert( map<ChannelType,Mat>::value_type(ChannelType::blue, _bgrChannels[0]) );
        _channelMats.insert( map<ChannelType,Mat>::value_type(ChannelType::green, _bgrChannels[1]) );
        _channelMats.insert( map<ChannelType,Mat>::value_type(ChannelType::red, _bgrChannels[2]) );

        _channelMats.insert( map<ChannelType,Mat>::value_type(ChannelType::hue, _hsvChannels[0]) );
        _channelMats.insert( map<ChannelType,Mat>::value_type(ChannelType::saturation, _hsvChannels[1]) );
        _channelMats.insert( map<ChannelType,Mat>::value_type(ChannelType::value, _hsvChannels[2]) );  
     
   
        _channelMats.insert( map<ChannelType,Mat>::value_type(ChannelType::y, _ycrcbChannels[0]) );
        _channelMats.insert( map<ChannelType,Mat>::value_type(ChannelType::cr, _ycrcbChannels[1]) );
        _channelMats.insert( map<ChannelType,Mat>::value_type(ChannelType::cb, _ycrcbChannels[2]) );
    }

    Mat& getChannelMat(ChannelType type) {
        return _channelMats[type];
    }
    Mat& bMat() {
        return _bgrChannels[0];
    }
    Mat& gMat() {
        return _bgrChannels[1];
    }
    Mat& rMat() {
        return _bgrChannels[2];
    }
    Mat& hMat() {
        return _hsvChannels[0];
    }
    Mat& sMat() {
        return _hsvChannels[1];
    }
    Mat& vMat() {
        return _hsvChannels[2];
    }
    Mat& yMat() {
        return _ycrcbChannels[0];
    }
    Mat& crMat() {
        return _ycrcbChannels[1];
    }
    Mat& cbMat() {
        return _ycrcbChannels[2];
    }
private:

/*property*/
private:
    map<ChannelType, Mat> _channelMats;
    Mat _bgrChannels[3];
    Mat _hsvChannels[3];
    Mat _ycrcbChannels[3];
};

#endif // CHANNELSET_H
