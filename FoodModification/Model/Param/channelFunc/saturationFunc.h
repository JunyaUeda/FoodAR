#ifndef SATURATIONFUNC_H
#define SATURATIONFUNC_H

#include "./channelFunc.h"
#include "../matSet.h"

class SaturationFunc : public ChannelFunc {
public:
    SaturationFunc();
    int value(Mat& img, int x, int y) {
        return G(img, x, y);
    }

    int value(MatSet& matSet, int x, int y) {
        return value(matSet.hsv(),x,y);
    }

    int value(MatSet& matSet, Point point) {
        return value(matSet, point.x, point.y);
    }
    QString getChannelName() {
        return "saturation";
    }
};

#endif // SATURATIONFUNC_H
