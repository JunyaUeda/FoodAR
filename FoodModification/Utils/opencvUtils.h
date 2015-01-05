#ifndef OPENCVUTILS_H
#define OPENCVUTILS_H

#include "opencvBase.h"
#include <map>
#include <QDebug>

#define VALUE(IMG, X,Y) ((IMG).data[(IMG).cols*(Y) + (X)])

class OpenCVUtils : public OpenCVBase {
public:
    OpenCVUtils();
    static void setPixelValue(cv::Mat img, int x, int y, int value);
    static Rect calculateROI(Size imgSize, Rect srcRect, double scaleRatio);
    static Rect scaleRect(Rect srcRect, double scaleRatio);

};

#endif // OPENCVUTILS_H
