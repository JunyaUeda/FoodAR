#ifndef COLOR_H
#define COLOR_H

#include "./channel.h"
#include "./channelType/channelType.h"
#include "./spaceType/colorSpaceType.h"
#include <QVector>

using namespace std;

class Color {

/*property*/
public:
    QVector<Channel> _channels;

/*method*/
public:
    Color();
    Color(int channelNum);
    bool hasColorSpaceType(ColorSpaceType type);
};

#endif // COLOR_H
