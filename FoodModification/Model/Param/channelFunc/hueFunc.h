#ifndef HUEFUNC_H
#define HUEFUNC_H

#include "./channelFunc.h"
#include "../matSet.h"

class HueFunc : public ChannelFunc {
public:
    HueFunc();
    int value(Mat& img, int x, int y) {
        return B(img, x, y);
    }

    int value(MatSet& matSet, int x, int y) {
        return value(matSet.hsv(),x,y);
    }

    int value(MatSet& matSet, Point point) {
        return value(matSet, point.x, point.y);
    }

    QString getChannelName() {
        return "hue";
    }
};

#endif // HUEFUNC_H
