#ifndef BLUETYPE_H
#define BLUETYPE_H

#include "./channelType.h"
#include "../../SDK/opencv/opencvApi.h"

class BlueType : public ChannelType {
public:
    BlueType();
    int value(Mat img, int x, int y);
};

#endif // BLUETYPE_H
