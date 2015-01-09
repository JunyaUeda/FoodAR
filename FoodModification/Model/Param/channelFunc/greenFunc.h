#ifndef GREENFUNC_H
#define GREENFUNC_H

#include "./channelFunc.h"
#include "../matSet.h"

class GreenFunc : public ChannelFunc {
public:
    GreenFunc();
    int value(Mat& img, int x, int y) {
        return G(img, x, y);
    }

    int value(MatSet& matSet, int x, int y) {
        return G(matSet.bgr(),x,y);
    }

    using ChannelFunc::value;
    int value(MatSet& matSet, Point point) {
        return value(matSet, point.x, point.y);
    }
    QString getChannelName() {
        return "green";
    }
};

#endif // GREENFUNC_H
