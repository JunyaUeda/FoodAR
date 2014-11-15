#ifndef CHANNELHISTOGRAM_H
#define CHANNELHISTOGRAM_H

#include <QVector>
#include "./channelFunc/channelFunc.h"

class channelHistogram {

/*property*/
private:
    ChannelFunc _channeFunc;
	QVector<int> _histogramArray;
public:
	channelHistogram();
};

#endif // CHANNELHISTOGRAM_H
