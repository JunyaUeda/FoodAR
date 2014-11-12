#ifndef CHANNELTHRESHOLD_H
#define CHANNELTHRESHOLD_H

#include "./channelType/channelType.h"
#include "../../Utils/xmlUtils.h"
#include "./channelType/blueType.h"
#include "./channelType/greenType.h"
#include "./channelType/redType.h"
#include "./channelType/hueType.h"
#include "./channelType/saturationType.h"
#include "./channelType/valueType.h"
#include "./channelType/yType.h"
#include "./channelType/crType.h"
#include "./channelType/cbType.h"


class ChannelThreshold {

/*property*/
private:
	ChannelType _channelType;
	int _average;
	int _tolerance;
	int _upper;
	int _under;

/*method*/
public:
    ChannelThreshold();
    ChannelThreshold(ChannelType type);
    bool loadAverage(QDomElement element);
    void setThreshold(int average, int tolerance);
    static QList<ChannelThreshold> createAllChannelThreshold();
    //getter setter
    ChannelType channelType() const;
    int average() const;
    void setAverage(int average);
    int tolerance() const;
    void setTolerance(int tolerance);
    int upper() const;
    void setUpper(int upper);
    int under() const;
    void setUnder(int under);

};

#endif // CHANNELTHRESHOLD_H
