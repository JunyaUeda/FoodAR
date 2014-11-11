#ifndef CHANNELTYPE_H
#define CHANNELTYPE_H

#include <QString>
#include "../../SDK/opencv/opencvApi.h"
#include "../matSet.h"

class ChannelType {

/*property*/
public:
  	int value(Mat img, int x, int y);
  	int value(MatSet* matSet, int x, int y);
private:
    QString _name;

/*method*/
public:
	QString toString() const {
        return _name;
    }

private:

};

#endif // CHANNELTYPE_H
