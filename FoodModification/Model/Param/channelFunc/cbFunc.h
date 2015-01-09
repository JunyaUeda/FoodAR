#ifndef CBFUNC_H
#define CBFUNC_H

#include "./channelFunc.h"
#include "../matSet.h"

class CbFunc : public ChannelFunc {
public:
    CbFunc();
    int value(Mat& img, int x, int y) {
        return R(img, x, y);
    }

    int value(MatSet& matSet, int x, int y) {
        return R(matSet.ycrcb(),x,y);;
    }

    using ChannelFunc::value;
    int value(MatSet& matSet, Point point) {
        return value(matSet, point.x, point.y);
    }
    QString getChannelName() {
        return "cb";
    }
};

#endif // CBFUNC_H
