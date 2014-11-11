#include "yType.h"

YType::YType() {
}

int YType::value(Mat img, int x, int y) {
	return B(img, x, y);
}

int YType::value(MatSet* matSet, int x, int y) {
	return value(matSet->ycrcb(),x,y);
}