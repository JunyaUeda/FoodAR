#ifndef EDGEPARAM_H
#define EDGEPARAM_H
#include "./cannyThreshold.h"
#include "../Utils/opencvBase.h"

class EdgeParam {

public:
	EdgeParam();

	vector<CannyThreshold *> cannyThresholds() const;
	void setCannyThresholds(const vector<CannyThreshold *> &cannyThresholds);

	//mainwindowから呼ばれる
	void changeCannyThreshold(int channelIndex, CannyThreshold* novel);

private:
	vector<CannyThreshold*> _cannyThresholds;

};

#endif // EDGEPARAM_H
