#include "edgeController.h"

#define THRESHOLD1 30.0
#define THRESHOLD2 60.0
#define APERTURE_SIZE 3
#define L2_GRADIENT true

EdgeController::EdgeController() {
	
}

EdgeController& EdgeController::getInstance() {
	static EdgeController instance;
	return instance;
}

void EdgeController::calculateEdges(map<int, Mat>* channels, Mat* dstEdges) {

	int i=0;
	for(const auto& elem :  _edgeParam->channelThresholdMap()) { 
		
		int key = elem.first;
		CannyThreshold* threshold = elem.second;
		int threshold1 = threshold->value1();
		int threshold2 = threshold->value2();

		Canny((*channels)[key], dstEdges[i], threshold1, threshold2, APERTURE_SIZE, L2_GRADIENT);
		i++;
	}
	
}

/**
* mainWindowのエッジの閾値変更によって呼び出される
*　@param 変更するチャンネルindexと新しい閾値
*/
void EdgeController::changeCannyThreshold(int channelIndex, CannyThreshold* novel) {
    _edgeParam->changeCannyThreshold(channelIndex, novel);
}

void EdgeController::addEdgeChannel(int channelIndex, CannyThreshold* threshold) {
	 _edgeParam->channelThresholdMap().insert( make_pair(channelIndex, threshold) );
}