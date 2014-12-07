#include "matSet.h"

MatSet::MatSet() {

}

MatSet::MatSet(const Mat bgr) {
	_bgr = bgr;
    boxFilter(_bgr, _blur, 8, Size(3,3));
	cvtColor(_blur, _hsv, CV_BGR2HSV);
    cvtColor(_blur, _ycrcb, CV_BGR2YCrCb);
    cvtColor(_blur, _gray, CV_BGR2GRAY);
    
    _width = bgr.cols;
    _height = bgr.rows;
}

