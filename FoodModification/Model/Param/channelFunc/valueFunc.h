#ifndef VALUEFUNC_H
#define VALUEFUNC_H

#include "./channelFunc.h"
#include "../matSet.h"

class ValueFunc : public ChannelFunc {
public:
    ValueFunc();
    int value(Mat& img, int x, int y) {
        return R(img, x, y);
    }

    int value(MatSet& matSet, int x, int y) {
        return R(matSet.hsv(),x,y);
    }

    using ChannelFunc::value;//for warning: *** hides overloaded virtual function [-Woverloaded-virtual]
    int value(MatSet& matSet, Point point) {
        return ValueFunc::value(matSet, point.x, point.y);
    }
    
    QString getChannelName() {
        return "value";
    }
};

#endif // VALUEFUNC_H
