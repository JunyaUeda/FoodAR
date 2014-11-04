#ifndef THRESHOLD_H
#define THRESHOLD_H

#include "./channelThreshold.h"
#include "../../Utils/xmlUtils.h"

class Threshold {

/*property*/
private:
	int _channelNum = 3;
	ChannelThreshold _channelThreshold0 = ChannelThreshold(ChannelType::H);
	ChannelThreshold _channelThreshold1 = ChannelThreshold(ChannelType::S);
	ChannelThreshold _channelThreshold2 = ChannelThreshold(ChannelType::V);

/*method*/
public:
    Threshold();
    void loadThreshold(QDomElement element);

private:
	void loadAverage(QDomElement element);
};

#endif // THRESHOLD_H
