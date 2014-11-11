#include "greenType.h"

GreenType::GreenType() {
}

int GreenType::value(Mat img, int x, int y) {
	return G(img, x, y);
}

int GreenType::value(MatSet* matSet, int x, int y) {
	return value(matSet->bgr(),x,y);
}