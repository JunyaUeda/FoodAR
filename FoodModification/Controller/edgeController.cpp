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

void EdgeController::changeThreshold(int value_1, int value_2) {
	_edgeParam->setCannyThreshold_1(value_1);
	_edgeParam->setCannyThreshold_2(value_2);
}

void EdgeController::calculateEdges(Mat* channels, Mat* dstEdges) {
	int threshold1 = _edgeParam->cannyThreshold_1();
	int threshold2 = _edgeParam->cannyThreshold_2();
	Canny(channels[0], dstEdges[0], threshold1, threshold2, APERTURE_SIZE, L2_GRADIENT);
    Canny(channels[1], dstEdges[1], threshold1, threshold2, APERTURE_SIZE, L2_GRADIENT);
    Canny(channels[2], dstEdges[2], threshold1, threshold2, APERTURE_SIZE, L2_GRADIENT);
}