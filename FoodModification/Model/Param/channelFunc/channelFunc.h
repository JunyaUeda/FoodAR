#ifndef CHANNELFUNC_H
#define CHANNELFUNC_H

#include <QString>
#include "../../SDK/opencv/opencvApi.h"
#include "../matSet.h"


class ChannelFunc {

/*property*/
public:
  	int value(Mat img, int x, int y);
  	int value(MatSet* matSet, int x, int y);
  	int value(MatSet* matSet, Point point);
private:
    QString _name;

/*method*/
public:
	QString toString() const {
        return _name;
    }
    ChannelFunc();

private:

};

#endif // CHANNELFUNCs_H
