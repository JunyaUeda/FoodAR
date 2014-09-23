#ifndef CALIBRATECLICKPARAM_H
#define CALIBRATECLICKPARAM_H
#include "../Utils/opencvUtils.h"

class CalibrateClickParam
{
public:
    cv::Point clickedPoints[2][30];
    int leftClickedCounts = 0;
    int rightClickedCounts = 0; 
    cv::Mat img;
    Mat RGBImg;
public:
    CalibrateClickParam();
};

#endif // CALIBRATECLICKPARAM_H
