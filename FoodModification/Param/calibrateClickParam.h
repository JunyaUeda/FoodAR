#ifndef CALIBRATECLICKPARAM_H
#define CALIBRATECLICKPARAM_H
#include "../Utils/opencvUtils.h"

class CalibrateClickParam {

public:
    vector<vector<Point> > clickedPoints;
    int leftClickedCounts = 0;
    int rightClickedCounts = 0; 
    Mat srcBGRImg;
    Mat srcHSVImg;
    Mat refImg;
public:
    CalibrateClickParam();
    void setImgsByBGRImg(Mat srcBGRImg);

};

#endif // CALIBRATECLICKPARAM_H
