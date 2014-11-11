#ifndef CHANNELHISTOGRAM_H
#define CHANNELHISTOGRAM_H

#include <QVector>
#include "./channelType/channelType.h"

class channelHistogram {

/*property*/
private:
	ChannelType _channeType;
	QVector<int> _histogramArray;
public:
	channelHistogram();
};

#endif // CHANNELHISTOGRAM_H
