#ifndef CHANNEL_H
#define CHANNEL_H

#include "./channelType/channelType.h"

class Channel {

/*property*/
private:
    ChannelType _channelType;
    int _value;
public:
    Channel();
};

#endif // CHANNEL_H
