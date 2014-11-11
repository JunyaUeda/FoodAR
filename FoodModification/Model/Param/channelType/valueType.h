#ifndef VALUETYPE_H
#define VALUETYPE_H

#include "./channelType.h"

class ValueType : public ChannelType {
public:
    ValueType();
    int value(Mat img, int x, int y);
    int value(MatSet* matSet, int x, int y);
    
};

#endif // VALUETYPE_H
