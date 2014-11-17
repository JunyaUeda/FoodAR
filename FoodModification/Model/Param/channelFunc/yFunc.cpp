#include "yFunc.h"

YFunc::YFunc() {
}

int YFunc::value(Mat img, int x, int y) {
	return B(img, x, y);
}

int YFunc::value(MatSet* matSet, int x, int y) {
	return value(matSet->ycrcb(),x,y);
}

int YFunc::value(MatSet* matSet, Point point) {
    value(matSet, point.x, point.y);
}
