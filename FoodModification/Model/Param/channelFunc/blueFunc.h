#ifndef BLUEFUNC_H
#define BLUEFUNC_H

#include "./channelFunc.h"
#include "../../SDK/opencv/opencvApi.h"
#include "../matSet.h"

class BlueFunc : public ChannelFunc {

/*method*/
public:
    BlueFunc();
    int value(Mat img, int x, int y);
    int value(MatSet& matSet, int x, int y);
    int value(MatSet& matSet, Point point);
    QString getChannelName();
};

#endif // BLUEFUNC_H
