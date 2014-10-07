#include "edgeParam.h"

EdgeParam::EdgeParam() {
	_channelThresholdMap.insert( make_pair(JU_S, new CannyThreshold()) );
	_channelThresholdMap.insert( make_pair(JU_Cr, new CannyThreshold()) );
	_channelThresholdMap.insert( make_pair(JU_V, new CannyThreshold()) );
}

map<int, CannyThreshold *> EdgeParam::channelThresholdMap() const {
	return _channelThresholdMap;
}

void EdgeParam::setChannelThresholdMap(const map<int, CannyThreshold *> &channelThresholdMap) {
	_channelThresholdMap = channelThresholdMap;
}

void EdgeParam::changeCannyThreshold(int channelIndex, CannyThreshold* novel) {
	map<int, CannyThreshold*>::iterator it = _channelThresholdMap.find(channelIndex);
	(*it).second = novel;
}