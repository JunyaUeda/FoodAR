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
	
	convertHSV(dstBGRImg, maskImg, rects, textureParam);

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

void ConvertController::convertHSV(Mat srcBGRImg, Mat maskImg, vector<Rect>& rects, TextureParam* textureParam) {

	
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
	cvtColor(dstHSVImg, srcBGRImg, CV_HSV2BGR);

}

// /**
// * colorDialogの色の編集によって呼び出される.
// *　@param HSVのシフト量
// */
// void ConvertController::changeShiftValue(int hShift, int sShift, int vShift) {

// 	textureParam->setShift(hShift, sShift, vShift);
	
// }

// void ConvertController::changeShiftValue(int value, int colorIndex) {
	
// 	const int HUE = 0;
// 	const int SATURATION = 1;
// 	const int VALUE = 2;

// 	switch(colorIndex) {
// 		case HUE:
// 			textureParam->setH_shift(value);
// 			break;
// 		case SATURATION:
// 			textureParam->setS_shift(value);
// 			break;
// 		case VALUE:
// 			textureParam->setV_shift(value);
// 			break;
// 	}

// }

// void ConvertController::setAlpha(double value) {

// 	textureParam->setAlpha(value);

// }
