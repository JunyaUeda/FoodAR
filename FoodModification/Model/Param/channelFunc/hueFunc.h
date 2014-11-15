#ifndef HUEFUNC_H
#define HUEFUNC_H

#include "./channelFunc.h"

class HueFunc : public ChannelFunc {
public:
    HueFunc();
    int value(Mat img, int x, int y);
    int value(MatSet* matSet, int x, int y);
    
};

#endif // HUEFUNC_H
