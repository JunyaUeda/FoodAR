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
//void EdgeController::changeCannyThreshold(int channelIndex, CannyThreshold* novel) {

//}

//void EdgeController::addEdgeChannel(int channelIndex, CannyThreshold* threshold) {

//}
