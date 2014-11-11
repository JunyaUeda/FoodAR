#ifndef SOURCE_H
#define SOURCE_H

#include "../SDK/opencv/opencvApi.h"

class Source {
/*property*/
public:
	Mat bgrImg;
	Mat hsvImg;
	Mat ycrcbImg;
	Mat grayImg;
public:
    Source();
};

#endif // SOURCE_H
