#ifndef SRCCONTROLLER_H
#define SRCCONTROLLER_H
#include "../Utils/opencvUtils.h"
#include "../Param/srcParam.h"
#include "../definition.h"

class SrcController {
	
public:
	static SrcController& getInstance();
	bool bindSrc();
	void loadSrc(Mat srcBGRImg, Mat srcHSVImg, Mat srcYCrCbImg, Mat srcGrayImg, Mat* splitChannels);
	void loadSrc(Mat srcBGRImg, Mat srcHSVImg, Mat srcYCrCbImg, Mat srcGrayImg, map<int,Mat> *splitChannels);
	
	SrcParam *srcParam() const;
	void setSrcParam(SrcParam *srcParam);

	void setVCaptureSize(Size size);
	void changeTextureImg(String path);
	void changeSplitColorSpace(int colorSpaceIndex);

private:
	VideoCapture _videoCapture_camera;
	VideoCapture _videoCapture_file;
	SrcParam* _srcParam = new SrcParam();
	
	SrcController();
	SrcController(const SrcController&);
	bool isCaptured(Mat srcImg);
};

#endif // SRCCONTROLLER_H
