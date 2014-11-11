#include "saturationType.h"

SaturationType::SaturationType() {
}

int SaturationType::value(Mat img, int x, int y) {
	return G(img, x, y);
}


int SaturationType::value(MatSet* matSet, int x, int y) {
	return value(matSet->hsv(),x,y);
}