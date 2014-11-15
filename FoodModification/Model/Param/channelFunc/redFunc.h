#ifndef REDFUNC_H
#define REDFUNC_H

#include "./channelFunc.h"

class RedFunc : public ChannelFunc {
public:
    RedFunc();
    int value(Mat img, int x, int y);
    int value(MatSet* matSet, int x, int y);
    
};

#endif // REDFUNC_H
