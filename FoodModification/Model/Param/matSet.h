#ifndef MATSET_H
#define MATSET_H

#include "../SDK/opencv/opencvApi.h"
#include "../TypeDef.h"

class MatSet {
/*property*/
private:
	Mat _bgr;
	Mat _hsv;
	Mat _ycrcb;
	Mat _gray;
	map<ChannelType, Mat> _channelImgs;
	int _width;
	int _height;
/*method*/
public:
	MatSet();
	MatSet(const Mat &bgr);
	Mat bgr() const;
	void setBgr(const Mat &bgr);
	Mat hsv() const;
	Mat ycrcb() const;
	Mat gray() const;
	int width() const;
	int height() const;
	Size size() const;
	map<ChannelType, Mat> channelImgs();
	void addChannelImgs(SpaceType type);
};

#endif // MATSET_H
