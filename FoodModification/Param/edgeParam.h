#ifndef EDGEPARAM_H
#define EDGEPARAM_H
#include "./cannyThreshold.h"
#include "../Utils/opencvUtils.h"
#include "../definition.h"

class EdgeParam {

public:
	EdgeParam();

	//getter setter
	map<int, CannyThreshold *> channelThresholdMap() const;
	void setChannelThresholdMap(const map<int, CannyThreshold *> &channelThresholdMap);

	//mainwindowから呼ばれる
	void changeCannyThreshold(int channelIndex, CannyThreshold* novel);

private:
	map<int, CannyThreshold*> _channelThresholdMap;

};

#endif // EDGEPARAM_H
