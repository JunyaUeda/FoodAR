#ifndef VALUEFUNC_H
#define VALUEFUNC_H

#include "./channelFunc.h"

class ValueFunc : public ChannelFunc {
public:
    ValueFunc();
    int value(Mat img, int x, int y);
    int value(MatSet* matSet, int x, int y);
    
};

#endif // VALUEFUNC_H
