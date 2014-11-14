#ifndef MATSET_H
#define MATSET_H

#include "../SDK/opencv/opencvApi.h"

class MatSet {
/*property*/
private:
	Mat _bgr;
	Mat _hsv;
	Mat _ycrcb;
	Mat _gray;
	int _width;
	int _height;
/*method*/
public:
	MatSet(const Mat &bgr);
	Mat bgr() const;
	void setBgr(const Mat &bgr);
	Mat hsv() const;
	Mat ycrcb() const;
	Mat gray() const;
	int width() const;
	int height() const;
};

#endif // MATSET_H
