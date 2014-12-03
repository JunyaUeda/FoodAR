#include "redFunc.h"

RedFunc::RedFunc() {
}

int RedFunc::value(Mat img, int x, int y) {
	return R(img, x, y);
}

int RedFunc::value(MatSet& matSet, int x, int y) {
	return value(matSet.bgr(),x,y);
}

int RedFunc::value(MatSet& matSet, Point point) {
	return value(matSet, point.x, point.y);
}

QString RedFunc::getChannelName() {
    return "red";
}