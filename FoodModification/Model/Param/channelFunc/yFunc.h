#ifndef YFUNC_H
#define YFUNC_H

#include "./channelFunc.h"

class YFunc : public ChannelFunc {
public:
    YFunc();
    int value(Mat img, int x, int y);
    int value(MatSet* matSet, int x, int y);
    
};

#endif // YFUNC_H
