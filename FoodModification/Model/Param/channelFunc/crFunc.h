#ifndef CRFUNC_H
#define CRFUNC_H

#include "./channelFunc.h"
#include "../matSet.h"

class CrFunc : public ChannelFunc {
public:
    CrFunc();
    int value(Mat img, int x, int y);
    int value(MatSet& matSet, int x, int y);
    int value(MatSet& matSet, Point point);
    QString getChannelName();
};

#endif // CRFUNC_H
