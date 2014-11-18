#include "greenFunc.h"

GreenFunc::GreenFunc() {
}

int GreenFunc::value(Mat img, int x, int y) {
	return G(img, x, y);
}

int GreenFunc::value(MatSet& matSet, int x, int y) {
	return value(matSet.bgr(),x,y);
}

int GreenFunc::value(MatSet& matSet, Point point) {
	return value(matSet, point.x, point.y);
}
