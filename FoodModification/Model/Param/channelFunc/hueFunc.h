#ifndef HUEFUNC_H
#define HUEFUNC_H

#include "./channelFunc.h"
#include "../matSet.h"

class HueFunc : public ChannelFunc {
public:
    HueFunc();
    int value(Mat img, int x, int y);
    int value(MatSet& matSet, int x, int y);
    int value(MatSet& matSet, Point point);
    QString getChannelName();
};

#endif // HUEFUNC_H
