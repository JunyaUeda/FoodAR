#ifndef GREENFUNC_H
#define GREENFUNC_H

#include "./channelFunc.h"

class GreenFunc : public ChannelFunc {
public:
    GreenFunc();
    int value(Mat img, int x, int y);
    int value(MatSet* matSet, int x, int y);
};

#endif // GREENFUNC_H
