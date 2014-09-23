#include "convertController.h"

ConvertController::ConvertController() {

}

void ConvertController::convert(Mat srcBGRImg, Mat srcHSVImg, Mat dstBGRImg, Mat textureImg, Mat maskImg, vector<Rect>& rects) {

	const double ALPHA = 0.9;
	overlapTexture(dstBGRImg, maskImg, textureImg, rects, ALPHA);
	convertHSV(dstBGRImg, maskImg, rects);

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

void ConvertController::convertHSV(Mat srcBGRImg, Mat maskImg, vector<Rect>& rects) {

	Mat dstHSVImg;
	cvtColor(srcBGRImg, dstHSVImg, CV_BGR2HSV);
	for(int i=0; i<rects.size(); i++) {
		for(int y=rects[i].y; y<(rects[i].y+rects[i].height); y++) {
			for(int x=rects[i].x; x<(rects[i].x+rects[i].width); x++){
				if(L(maskImg,x,y) == 255) {
					H(dstHSVImg,x,y) = H(dstHSVImg,x,y) + 10;
					S(dstHSVImg,x,y) = S(dstHSVImg,x,y) + 10;
					V(dstHSVImg,x,y) = V(dstHSVImg,x,y) + 10;
				}
			}
		}
	}
	cvtColor(dstHSVImg, srcBGRImg, CV_HSV2BGR);

}

