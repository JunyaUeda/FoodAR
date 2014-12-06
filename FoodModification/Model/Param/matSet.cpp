#include "matSet.h"

MatSet::MatSet() {

}

MatSet::MatSet(const Mat bgr) {
	_bgr = bgr;
	cvtColor(_bgr, _hsv, CV_BGR2HSV);
    cvtColor(_bgr, _ycrcb, CV_BGR2YCrCb);
    cvtColor(_bgr, _gray, CV_BGR2GRAY);
    boxFilter(_bgr, _blur, 8, Size(3,3));
    _width = bgr.cols;
    _height = bgr.rows;
}

