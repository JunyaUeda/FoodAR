#include "convertController.h"
#include <QDebug>

ConvertController::ConvertController() {
	
}

ConvertController& ConvertController::getInstance() {
	static ConvertController instance;
	return instance;
}

void ConvertController::convert(Mat srcBGRImg, Mat srcHSVImg, Mat dstBGRImg, Mat maskImg, vector<Rect>& rects, TextureParam* textureParam) {

	if(!textureParam->isNoTexture()) {
		const double ALPHA = textureParam->getAlpha();
    	overlapTexture(dstBGRImg, maskImg, textureParam->getImg(), rects, ALPHA);
	} 
	

	if(_illuminationParam->intensityChange()) {
		convertHSVAndIllumination(dstBGRImg, maskImg, rects, textureParam, _illuminationParam->intensityFactor());
	} else {
		convertHSV(dstBGRImg, srcHSVImg, maskImg, rects, textureParam);
	}

	if(_illuminationParam->ZChange()) {
		convertZ(dstBGRImg, _illuminationParam->ZFactor());
	}

}

void ConvertController::overlapTexture(Mat srcBGRImg, Mat maskImg, Mat textureImg, vector<Rect>& rects, double alpha) {

	for(int i=0; i<rects.size(); i++) {

		for(int y=rects[i].y; y<(rects[i].y+rects[i].height); y++) {
			for(int x=rects[i].x; x<(rects[i].x+rects[i].width); x++){
				if(L(maskImg,x,y) == 255) {
					B(srcBGRImg,x,y) = alpha*B(srcBGRImg,x,y) + (1-alpha)*B(textureImg,x,y);
					G(srcBGRImg,x,y) = alpha*G(srcBGRImg,x,y) + (1-alpha)*G(textureImg,x,y);
					R(srcBGRImg,x,y) = alpha*R(srcBGRImg,x,y) + (1-alpha)*R(textureImg,x,y);
				}
			}
		}

	}

}

void ConvertController::convertHSV(Mat srcBGRImg, Mat srcHSVImg, Mat maskImg, vector<Rect>& rects, TextureParam* textureParam) {

	
	Mat dstHSVImg;
	cvtColor(srcBGRImg, dstHSVImg, CV_BGR2HSV);
	for(int i=0; i<rects.size(); i++) {
		for(int y=rects[i].y; y<(rects[i].y+rects[i].height); y++) {
			for(int x=rects[i].x; x<(rects[i].x+rects[i].width); x++){
				if(L(maskImg,x,y) == 255) {
					H(dstHSVImg,x,y) = H(dstHSVImg,x,y) + textureParam->getH_shift();
					S(dstHSVImg,x,y) = S(dstHSVImg,x,y) + textureParam->getS_shift();
					V(dstHSVImg,x,y) = V(srcHSVImg,x,y) + textureParam->getV_shift();
				}
			}
		}
	}
	cvtColor(dstHSVImg, srcBGRImg, CV_HSV2BGR);

}

void ConvertController::convertHSVAndIllumination(Mat srcBGRImg, Mat maskImg, vector<Rect>& rects, TextureParam* textureParam, double intensityFactor) {

	
	Mat dstHSVImg;
	cvtColor(srcBGRImg, dstHSVImg, CV_BGR2HSV);
	for(int i=0; i<rects.size(); i++) {
		for(int y=rects[i].y; y<(rects[i].y+rects[i].height); y++) {
			for(int x=rects[i].x; x<(rects[i].x+rects[i].width); x++){
				if(L(maskImg,x,y) == 255) {
					H(dstHSVImg,x,y) = H(dstHSVImg,x,y) + textureParam->getH_shift();
					S(dstHSVImg,x,y) = S(dstHSVImg,x,y) + textureParam->getS_shift();
					V(dstHSVImg,x,y) = V(dstHSVImg,x,y) + textureParam->getV_shift();
				}
			}
		}
	}

	for(int y=0; y<srcBGRImg.rows; y++) {
		for(int x=0; x<srcBGRImg.cols; x++) {
			V(dstHSVImg,x,y) = changeIllumination(V(dstHSVImg,x,y), intensityFactor);
		}
	}
	cvtColor(dstHSVImg, srcBGRImg, CV_HSV2BGR);

}


int ConvertController::changeIllumination(int currentValue, double intensityFactor) {

	if(currentValue * intensityFactor > 255) {
		return 255;
	} else {
		return (int)currentValue * intensityFactor;
	}

}

void ConvertController::convertZ(Mat srcBGRImg, double ZFactor) {

	Mat dstXYZImg;
	cvtColor(srcBGRImg, dstXYZImg, CV_BGR2XYZ);
	for(int y=0; y<srcBGRImg.rows; y++) {
		for(int x=0; x<srcBGRImg.cols; x++) {
			if(V(dstXYZImg,x,y) * ZFactor > 255) {
				V(dstXYZImg,x,y) =  255;
			} else {
				V(dstXYZImg,x,y) = V(dstXYZImg,x,y) * ZFactor;
			}
		}
	}
	cvtColor(dstXYZImg, srcBGRImg, CV_XYZ2BGR);
}


void ConvertController::changeIntensityParam(bool change, int intensityFactor) {

	double d_IntensityFactor = (double)intensityFactor/100.0;
	_illuminationParam->setIntensityChange(change);
	_illuminationParam->setIntensityFactor(d_IntensityFactor);

}

void ConvertController::changeZParam(bool change, int ZFactor) {

	double d_ZFactor = (double)ZFactor/100.0;
	_illuminationParam->setZChange(change);
	_illuminationParam->setZFactor(d_ZFactor);

}