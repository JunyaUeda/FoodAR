#ifndef BLUEFUNC_H
#define BLUEFUNC_H

#include "./channelFunc.h"
#include "../../SDK/opencv/opencvApi.h"
#include "../matSet.h"

class BlueFunc : public ChannelFunc {

/*method*/
public:
    BlueFunc();
    int value(Mat& img, int x, int y) {
        return B(img, x, y);
    }

    int value(MatSet& matSet, int x, int y) {
        return B(matSet.bgr(),x,y);
    }

    using ChannelFunc::value;
    int value(MatSet& matSet, Point point) {
        return value(matSet, point.x, point.y);
    }
    QString getChannelName() {
        return "blue";
    }
};

#endif // BLUEFUNC_H
