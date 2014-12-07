#ifndef MATSET_H
#define MATSET_H

#include "../SDK/opencv/opencvApi.h"
#include "../TypeDef.h"

class MatSet {

/*method*/
public:
	MatSet();
	MatSet(Mat bgr);


	void setBgr(Mat bgr) {
		_bgr = bgr;
		boxFilter(_bgr, _blur, 8, Size(3,3));
		cvtColor(_blur, _hsv, CV_BGR2HSV);
    	cvtColor(_blur, _ycrcb, CV_BGR2YCrCb);
    	cvtColor(_blur, _gray, CV_BGR2GRAY);
    	_width = bgr.cols;
    	_height = bgr.rows;
	}

	Mat bgr() const {
		return _bgr;
	}
	Mat hsv() const {
		return _hsv;
	}
	Mat ycrcb() const {
		return _ycrcb;
	}
	Mat gray() const {
		return _gray;
	}
	Mat blur() const {
		return _blur;
	}
	int width() const {
		return _width;
	}
	int height() const {
		return _height;
	}
	Size size() const {
		return Size(_width, _height);
	}


/*property*/
private:
	Mat _bgr;
	Mat _hsv;
	Mat _ycrcb;
	Mat _gray;
	Mat _blur;
	int _width;
	int _height;

};

#endif // MATSET_H
