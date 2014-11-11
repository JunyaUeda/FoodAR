#include "cbType.h"

CbType::CbType() {
}

int CbType::value(Mat img, int x, int y) {
	return R(img, x, y);
}

int CbType::value(MatSet* matSet, int x, int y) {
	return value(matSet->ycrcb(),x,y);;
}