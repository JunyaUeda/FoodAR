#include "calibrationService.h"

CalibrationService::CalibrationService() {

}

void CalibrationService::calculateAverage(Mat refImg, Mat maskImg, vector<Rect>& roiRects, ExtractParamManager* extractParamManager) {

	int sum[2][3] = {0};
	int pixelNum[2] = {0};
	for(int i=0; i<roiRects.size(); i++) {
		for(int y=roiRects[i].y; y<(roiRects[i].y+roiRects[i].height); y++) {
			for(int x=roiRects[i].x; x<(roiRects[i].x+roiRects[i].width); x++){
				if(L(maskImg,x,y) == 255) {
					int diff_0 = abs(V(refImg,x,y) - (extractParamManager->criterion+0)->getValue());
					int diff_1 = abs(V(refImg,x,y) - (extractParamManager->criterion+1)->getValue());
					if(diff_0 <= diff_1) {
						pixelNum[0]++;
						sum[0][0] = sum[0][0] + H(refImg,x,y);
						sum[0][1] = sum[0][1] + S(refImg,x,y);
						sum[0][2] = sum[0][2] + V(refImg,x,y);
					} else {
						pixelNum[1]++;
						sum[1][0] = sum[1][0] + H(refImg,x,y);
						sum[1][1] = sum[1][1] + S(refImg,x,y);
						sum[1][2] = sum[1][2] + V(refImg,x,y);
					}
					
				}
			}
		}
	}

	int average[2][3] = {0};
	for(int k=0; k<2; k++) {
		if(pixelNum[k] != 0) {

			for(int m=0; m<3; m++) {
				average[k][m] = (int)sum[k][m]/pixelNum[k];
			}
			
			(extractParamManager->criterion+k)->setHue(average[k][0]);
			(extractParamManager->criterion+k)->setSaturation(average[k][1]);
			(extractParamManager->criterion+k)->setValue(average[k][2]);

		}
	}

}