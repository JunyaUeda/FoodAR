#ifndef CBTYPE_H
#define CBTYPE_H

#include "./channelType.h"

class CbType : public ChannelType {
public:
    CbType();
    int value(Mat img, int x, int y);
    int value(MatSet* matSet, int x, int y);
};

#endif // CBTYPE_H
