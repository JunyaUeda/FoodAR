#ifndef YTYPE_H
#define YTYPE_H

#include "./channelType.h"

class YType : public ChannelType {
public:
    YType();
    int value(Mat img, int x, int y);
    int value(MatSet* matSet, int x, int y);
    
};

#endif // YTYPE_H
