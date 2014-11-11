#ifndef CRTYPE_H
#define CRTYPE_H

#include "./channelType.h"

class CrType : public ChannelType {
public:
    CrType();
    int value(Mat img, int x, int y);
    int value(MatSet* matSet, int x, int y);
};

#endif // CRTYPE_H
