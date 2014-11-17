#include "valueFunc.h"

ValueFunc::ValueFunc() {
}

int ValueFunc::value(Mat img, int x, int y) {
	return R(img, x, y);
}

int ValueFunc::value(MatSet* matSet, int x, int y) {
	return value(matSet->hsv(),x,y);
}

int ValueFunc::value(MatSet* matSet, Point point) {
    value(matSet, point.x, point.y);
}
