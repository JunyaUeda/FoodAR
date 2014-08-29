#include "opencvUtils.h"

OpenCVUtils::OpenCVUtils()
{
}

void OpenCVUtils::setPixelValue(cv::Mat img, int x, int y, int value) {
    B(img,x,y) = value;
    G(img,x,y) = value;
    R(img,x,y) = value;
}
