#include "edgeParam.h"

EdgeParam::EdgeParam() {
	for(int i=0; i<3; i++) {
		_cannyThresholds.push_back(new CannyThreshold());
	}
}

vector<CannyThreshold *> EdgeParam::cannyThresholds() const {
	return _cannyThresholds;
}

void EdgeParam::setCannyThresholds(const vector<CannyThreshold *> &cannyThresholds) {
	_cannyThresholds = cannyThresholds;
}

void EdgeParam::changeCannyThreshold(int channelIndex, CannyThreshold* novel) {
	_cannyThresholds[channelIndex] = novel;

}