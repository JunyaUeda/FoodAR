#ifndef CONVERTCONTROLLER_H
#define CONVERTCONTROLLER_H

#include "../Utils/opencvBase.h"
#include "../Param/textureParam.h"

class ConvertController
{	
public:
    static ConvertController& getInstance();
    void convert(Mat srcBGRImg, Mat srcHSVImg, Mat dstBGRImg,  Mat maskImg, vector<Rect>& rects, TextureParam* textureParam);
    // void changeShiftValue(int hShift, int sShift, int vShift);
    // void changeShiftValue(int value, int colorIndex);
    // void setAlpha(double value);
private:
	//TextureParam* textureParam = new TextureParam();
	ConvertController();
	ConvertController(const ConvertController&);
	void overlapTexture(Mat srcBGRImg, Mat maskImg, Mat textureImg, vector<Rect>& rects, double alpha);
    void convertHSV(Mat srcBGRImg, Mat maskImg, vector<Rect>& rects, TextureParam* textureParam);
    
};

#endif // CONVERTCONTROLLER_H
