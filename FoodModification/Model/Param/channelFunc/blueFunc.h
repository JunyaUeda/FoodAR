#ifndef BLUEFUNC_H
#define BLUEFUNC_H

#include "./channelFunc.h"
#include "../../SDK/opencv/opencvApi.h"

class BlueFunc : public ChannelFunc {
public:
    BlueFunc();
    int value(Mat img, int x, int y);
    int value(MatSet* matSet, int x, int y);
};

#endif // BLUEFUNC_H
