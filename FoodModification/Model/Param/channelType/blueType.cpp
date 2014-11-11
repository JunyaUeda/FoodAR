#include "blueType.h"

BlueType::BlueType() {
}

int BlueType::value(Mat img, int x, int y) {
	return B(img, x, y);
}

int BlueType::value(MatSet* matSet, int x, int y) {
	return value(matSet->bgr(),x,y);
}