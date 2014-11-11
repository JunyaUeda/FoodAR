#ifndef REDTYPE_H
#define REDTYPE_H

#include "./channelType.h"

class RedType : public ChannelType {
public:
    RedType();
    int value(Mat img, int x, int y);
    int value(MatSet* matSet, int x, int y);
    
};

#endif // REDTYPE_H
