#ifndef REDFUNC_H
#define REDFUNC_H

#include "./channelFunc.h"
#include "../matSet.h"

class RedFunc : public ChannelFunc {
public:
    RedFunc();
    int value(Mat img, int x, int y);
    int value(MatSet* matSet, int x, int y);
    int value(MatSet* matSet, Point point);
    
};

#endif // REDFUNC_H
