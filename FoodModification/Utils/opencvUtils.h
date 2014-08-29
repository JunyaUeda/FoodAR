#ifndef OPENCVUTILS_H
#define OPENCVUTILS_H
#include "opencvBase.h"
#include <QDebug>

// #define B(IMG, X,Y) ((IMG).data[((IMG).step*(Y) + (IMG).channels()*(X)) + 0])
// #define G(IMG, X,Y) ((IMG).data[((IMG).step*(Y) + (IMG).channels()*(X)) + 1])
// #define R(IMG, X,Y) ((IMG).data[((IMG).step*(Y) + (IMG).channels()*(X)) + 2])
// #define I(IMG, X,Y) ((IMG).data[((IMG).step*(Y) + (IMG).channels()*(X))])
#define VALUE(IMG, X,Y) ((IMG).data[(IMG).cols*(Y) + (X)])

class OpenCVUtils : public OpenCVBase
{
public:
    OpenCVUtils();
    static void setPixelValue(cv::Mat img, int x, int y, int value);
};

#endif // OPENCVUTILS_H
