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
/*method*/
public:
	MatSet(const Mat &bgr);
	Mat bgr() const;
	void setBgr(const Mat &bgr);
	Mat hsv() const;
	Mat ycrcb() const;
	Mat gray() const;
};

#endif // MATSET_H
