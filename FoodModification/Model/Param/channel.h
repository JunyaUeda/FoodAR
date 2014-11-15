#ifndef CHANNEL_H
#define CHANNEL_H

#include "./channelFunc/channelFunc.h"

class Channel {

/*property*/
private:
    ChannelFunc _channelFunc;
    int _value;
public:
    Channel();
};

#endif // CHANNEL_H
