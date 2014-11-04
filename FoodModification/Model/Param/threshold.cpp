#include "threshold.h"
#include <QDebug>

Threshold::Threshold() {
	
}

void Threshold::loadThreshold(QDomElement element) {
	loadAverage(element);
	qDebug() << "H=" + _channelThreshold0.average();
}

void Threshold::loadAverage(QDomElement element) {
	_channelThreshold0.loadAverage(element);
	_channelThreshold1.loadAverage(element);
	_channelThreshold2.loadAverage(element);
}
