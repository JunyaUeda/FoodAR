#ifndef CONVERTCONTROLLER_H
#define CONVERTCONTROLLER_H

#include "../Utils/opencvBase.h"

class ConvertController
{
public:
    ConvertController();
    void convert(Mat srcBGRImg, Mat srcHSVImg, Mat dstBGRImg, Mat textureImg, Mat maskImg, vector<Rect>& rects);
private:
	void overlapTexture(Mat srcBGRImg, Mat maskImg, Mat textureImg, vector<Rect>& rects, double alpha);
    void convertHSV(Mat srcBGRImg, Mat maskImg, vector<Rect>& rects);
};

#endif // CONVERTCONTROLLER_H
