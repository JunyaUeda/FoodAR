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
        return G(matSet.hsv(),x,y);
    }

    using ChannelFunc::value;//for warning: *** hides overloaded virtual function [-Woverloaded-virtual]
    int value(MatSet& matSet, Point point) {
        return SaturationFunc::value(matSet, point.x, point.y);
    }
    
    QString getChannelName() {
        return "saturation";
    }
};

#endif // SATURATIONFUNC_H
