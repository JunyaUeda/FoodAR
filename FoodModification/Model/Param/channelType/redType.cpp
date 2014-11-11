#include "redType.h"

RedType::RedType() {
}

int RedType::value(Mat img, int x, int y) {
	return R(img, x, y);
}

int RedType::value(MatSet* matSet, int x, int y) {
	return value(matSet->bgr(),x,y);
}