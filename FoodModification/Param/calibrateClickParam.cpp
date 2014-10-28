#include "calibrateClickParam.h"

CalibrateClickParam::CalibrateClickParam() {

    vector<vector<Point> > points(2);
	clickedPoints = points;
	
}

void CalibrateClickParam::setImgsByBGRImg(Mat srcBGRImg) {

	this->srcBGRImg = srcBGRImg.clone();
    this->refImg = srcBGRImg.clone();
    cvtColor(srcBGRImg, this->srcHSVImg, CV_BGR2HSV);

}
