#include "hueFunc.h"

HueFunc::HueFunc() {
}

int HueFunc::value(Mat img, int x, int y) {
	return B(img, x, y);
}

int HueFunc::value(MatSet& matSet, int x, int y) {
	return value(matSet.hsv(),x,y);
}

int HueFunc::value(MatSet& matSet, Point point) {
	return value(matSet, point.x, point.y);
}
