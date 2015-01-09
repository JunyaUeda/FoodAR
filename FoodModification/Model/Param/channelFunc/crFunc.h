#ifndef CRFUNC_H
#define CRFUNC_H

#include "./channelFunc.h"
#include "../matSet.h"

class CrFunc : public ChannelFunc {
public:
    CrFunc();
    int value(Mat& img, int x, int y) {
        return G(img, x, y);
    }

    int value(MatSet& matSet, int x, int y) {
        return G(matSet.ycrcb(),x,y);
    }

    using ChannelFunc::value;
    int value(MatSet& matSet, Point point) {
        return value(matSet, point.x, point.y);
    }
    QString getChannelName() {
        return "cr";
    }
};

#endif // CRFUNC_H
