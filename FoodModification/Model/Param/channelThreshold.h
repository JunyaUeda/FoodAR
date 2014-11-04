#ifndef CHANNELTHRESHOLD_H
#define CHANNELTHRESHOLD_H

#include "./channelType.h"
#include "../../Utils/xmlUtils.h"

class ChannelThreshold {

/*property*/
private:
	const ChannelType _channelType;
	int _average;
	int _tolerance;
	int _upper;
	int _under;

/*method*/
public:
    ChannelThreshold(ChannelType type);
    bool loadAverage(QDomElement element);
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
