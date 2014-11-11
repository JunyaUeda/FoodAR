#include "matSet.h"

MatSet::MatSet(const Mat &bgr) {
	_bgr = bgr;
	cvtColor(_bgr, _hsv, CV_BGR2HSV);
    cvtColor(_bgr, _ycrcb, CV_BGR2YCrCb);
    cvtColor(_bgr, _gray, CV_BGR2GRAY);
}


Mat MatSet::bgr() const {
	return _bgr;
}

void MatSet::setBgr(const Mat &bgr) {
	_bgr = bgr;
	cvtColor(_bgr, _hsv, CV_BGR2HSV);
    cvtColor(_bgr, _ycrcb, CV_BGR2YCrCb);
    cvtColor(_bgr, _gray, CV_BGR2GRAY);
}

Mat MatSet::hsv() const {
	return _hsv;
}

Mat MatSet::ycrcb() const {
	return _ycrcb;
}

Mat MatSet::gray() const {
	return _gray;
}

