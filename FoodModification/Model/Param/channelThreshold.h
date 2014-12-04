#ifndef CHANNELTHRESHOLD_H
#define CHANNELTHRESHOLD_H

#include "./channelFunc/channelFunc.h"
#include "../../Utils/xmlUtils.h"
#include "./channelFunc/blueFunc.h"
#include "./channelFunc/greenFunc.h"
#include "./channelFunc/redFunc.h"
#include "./channelFunc/hueFunc.h"
#include "./channelFunc/saturationFunc.h"
#include "./channelFunc/valueFunc.h"
#include "./channelFunc/yFunc.h"
#include "./channelFunc/crFunc.h"
#include "./channelFunc/cbFunc.h"
#include "./matSet.h"

class ChannelThreshold {

/*method*/
public:
    ChannelThreshold(ChannelFunc* type);
    bool loadAverage(QDomElement element);
    void setThreshold(int average, int tolerance);
    static vector<ChannelThreshold> createAllChannelThreshold();

    bool isWithinThreshold(MatSet& matSet, Point& point) {
        int value = _channelFunc->value(matSet, point);
        if( (value <= _upper) && (value >= _under) ) {
            return true;
        }
        return false;
    }

    //getter setter
    ChannelFunc* channelFunc() const;
    int average() const;
    void setAverage(int average);
    int tolerance() const;
    void setTolerance(int tolerance);
    int upper() const;
    void setUpper(int upper);
    int under() const;
    void setUnder(int under);
    void displayThreshold();

private:
    ChannelThreshold();

/*property*/
private:
    ChannelFunc* _channelFunc;
	int _average;
	int _tolerance;
	int _upper;
	int _under;



};

#endif // CHANNELTHRESHOLD_H
