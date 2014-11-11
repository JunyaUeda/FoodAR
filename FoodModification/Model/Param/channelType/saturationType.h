#ifndef SATURATIONTYPE_H
#define SATURATIONTYPE_H

#include "./channelType.h"

class SaturationType : public ChannelType {
public:
    SaturationType();
    int value(Mat img, int x, int y);
    int value(MatSet* matSet, int x, int y);
    
};

#endif // SATURATIONTYPE_H
