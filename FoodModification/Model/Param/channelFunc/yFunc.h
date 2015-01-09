#ifndef YFUNC_H
#define YFUNC_H

#include "./channelFunc.h"
#include "../matSet.h"

class YFunc : public ChannelFunc {
public:
    YFunc();
    int value(Mat& img, int x, int y) {
        return B(img, x, y);
    }

    int value(MatSet& matSet, int x, int y) {
        return B(matSet.ycrcb(),x,y);
    }

    using ChannelFunc::value;
    int value(MatSet& matSet, Point point) {
        return value(matSet, point.x, point.y);
    }
    QString getChannelName() {
        return "y";
    }

};

#endif // YFUNC_H
