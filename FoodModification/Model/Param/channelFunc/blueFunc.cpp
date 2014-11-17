#include "blueFunc.h"

BlueFunc::BlueFunc() {
}

int BlueFunc::value(Mat img, int x, int y) {
	return B(img, x, y);
}

int BlueFunc::value(MatSet* matSet, int x, int y) {
	return value(matSet->bgr(),x,y);
}

int BlueFunc::value(MatSet* matSet, Point point) {
    value(matSet, point.x, point.y);
}
