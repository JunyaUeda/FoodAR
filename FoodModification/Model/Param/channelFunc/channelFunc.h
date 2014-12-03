#ifndef CHANNELFUNC_H
#define CHANNELFUNC_H

#include <QString>
#include "../../SDK/opencv/opencvApi.h"
#include "../matSet.h"


class ChannelFunc {
/*method*/
public:
    virtual int value(Mat img, int x, int y);
    virtual int value(MatSet& matSet, int x, int y);
    virtual int value(MatSet& matSet, Point point);
    virtual QString getChannelName();
    ChannelFunc();

private:

/*property*/  	
private:
   



};

#endif // CHANNELFUNCs_H
