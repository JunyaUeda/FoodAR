#ifndef VALUEFUNC_H
#define VALUEFUNC_H

#include "./channelFunc.h"
#include "../matSet.h"

class ValueFunc : public ChannelFunc {
public:
    ValueFunc();
    int value(Mat img, int x, int y);
    int value(MatSet& matSet, int x, int y);
    int value(MatSet& matSet, Point point);
    
};

#endif // VALUEFUNC_H
