#ifndef COLOR_H
#define COLOR_H

#include "./channel.h"
#include "./channelFunc/channelFunc.h"
#include "./spaceFunc/colorSpaceFunc.h"
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
    bool hasColorSpaceFunc(ColorSpaceFunc type);
};

#endif // COLOR_H
