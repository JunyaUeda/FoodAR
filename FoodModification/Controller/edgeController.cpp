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


/**
* mainWindowのエッジの閾値変更によって呼び出される
*　@param 変更するチャンネルindexと新しい閾値
*/
void EdgeController::changeCannyThreshold(int channelIndex, CannyThreshold* novel) {
	 _edgeParam->changeCannyThreshold(channelIndex, novel);
}

void EdgeController::calculateEdges(Mat* channels, Mat* dstEdges) {

	for(int i=0; i<3; i++) { 

		int threshold1 = _edgeParam->cannyThresholds()[i]->value1();
		int threshold2 = _edgeParam->cannyThresholds()[i]->value2();

		Canny(channels[i], dstEdges[i], threshold1, threshold2, APERTURE_SIZE, L2_GRADIENT);
	}
	
}
