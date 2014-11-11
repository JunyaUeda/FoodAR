#include "valueType.h"

ValueType::ValueType() {
}

int ValueType::value(Mat img, int x, int y) {
	return R(img, x, y);
}

int ValueType::value(MatSet* matSet, int x, int y) {
	return value(matSet->hsv(),x,y);
}