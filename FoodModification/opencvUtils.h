#ifndef OPENCVUTILS_H
#define OPENCVUTILS_H
#include "opencvBase.h"
class OpenCVUtils : public OpenCVBase
{
public:
    OpenCVUtils();
    static void setPixelValue(cv::Mat img, int x, int y, int value);
};

#endif // OPENCVUTILS_H
