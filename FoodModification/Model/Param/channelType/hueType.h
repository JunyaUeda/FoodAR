#ifndef HUETYPE_H
#define HUETYPE_H

#include "./channelType.h"

class HueType : public ChannelType {
public:
    HueType();
    int value(Mat img, int x, int y);
    int value(MatSet* matSet, int x, int y);
    
};

#endif // HUETYPE_H
