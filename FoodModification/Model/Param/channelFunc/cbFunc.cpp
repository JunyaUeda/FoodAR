#include "cbFunc.h"

CbFunc::CbFunc() {
}

int CbFunc::value(Mat img, int x, int y) {
	return R(img, x, y);
}

int CbFunc::value(MatSet& matSet, int x, int y) {
	return value(matSet.ycrcb(),x,y);;
}

int CbFunc::value(MatSet& matSet, Point point) {
	return value(matSet, point.x, point.y);
}
