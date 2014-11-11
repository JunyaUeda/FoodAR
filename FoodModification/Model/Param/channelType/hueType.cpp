#include "hueType.h"

HueType::HueType() {
}

int HueType::value(Mat img, int x, int y) {
	return B(img, x, y);
}

int HueType::value(MatSet* matSet, int x, int y) {
	return value(matSet->hsv(),x,y);
}