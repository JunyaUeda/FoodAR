#ifndef SATURATIONFUNC_H
#define SATURATIONFUNC_H

#include "./channelFunc.h"
#include "../matSet.h"

class SaturationFunc : public ChannelFunc {
public:
    SaturationFunc();
    int value(Mat img, int x, int y);
    int value(MatSet* matSet, int x, int y);
    int value(MatSet* matSet, Point point);
    
};

#endif // SATURATIONFUNC_H
