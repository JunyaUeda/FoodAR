#ifndef REDFUNC_H
#define REDFUNC_H

#include "./channelFunc.h"
#include "../matSet.h"

class RedFunc : public ChannelFunc {
public:
    RedFunc();
    int value(Mat& img, int x, int y) {
        return R(img, x, y);
    }

    int value(MatSet& matSet, int x, int y) {
        return R(matSet.bgr(),x,y);
    }

    using ChannelFunc::value;//for warning: *** hides overloaded virtual function [-Woverloaded-virtual]
    int value(MatSet& matSet, Point point) {
        return RedFunc::value(matSet, point.x, point.y);
    }
    
    QString getChannelName() {
        return "red";
    }
};

#endif // REDFUNC_H
