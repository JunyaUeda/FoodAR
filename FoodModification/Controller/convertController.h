#ifndef CONVERTCONTROLLER_H
#define CONVERTCONTROLLER_H

#include "../Utils/opencvBase.h"
#include "../Param/textureParam.h"
#include "../Param/illuminationParam.h"

class ConvertController
{	
public:
    static ConvertController& getInstance();
    void convert(Mat srcBGRImg, Mat srcHSVImg, Mat dstBGRImg,  Mat maskImg, vector<Rect>& rects, TextureParam* textureParam);
    void changeIntensityParam(bool change, int intensityFactor);
    void changeZParam(bool change, int ZFactor);

private:
    IlluminationParam* _illuminationParam = new IlluminationParam();
	ConvertController();
	ConvertController(const ConvertController&);
	void overlapTexture(Mat srcBGRImg, Mat maskImg, Mat textureImg, vector<Rect>& rects, double alpha);
    void convertHSV(Mat srcBGRImg, Mat maskImg, vector<Rect>& rects, TextureParam* textureParam);
    int changeIllumination(int currentValue, double intensityFactor);
    void convertHSVAndIllumination(Mat srcBGRImg, Mat maskImg, vector<Rect>& rects, TextureParam* textureParam, double intensityFactor);
    void convertZ(Mat srcBGRImg, double ZFactor);
};

#endif // CONVERTCONTROLLER_H
