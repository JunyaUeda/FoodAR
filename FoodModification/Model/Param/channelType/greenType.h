#ifndef GREENTYPE_H
#define GREENTYPE_H

#include "./channelType.h"

class GreenType : public ChannelType {
public:
    GreenType();
    int value(Mat img, int x, int y);
    int value(MatSet* matSet, int x, int y);
};

#endif // GREENTYPE_H
