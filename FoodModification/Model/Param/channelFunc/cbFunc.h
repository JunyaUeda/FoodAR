#ifndef CBFUNC_H
#define CBFUNC_H

#include "./channelFunc.h"

class CbFunc : public ChannelFunc {
public:
    CbFunc();
    int value(Mat img, int x, int y);
    int value(MatSet* matSet, int x, int y);
};

#endif // CBFUNC_H
