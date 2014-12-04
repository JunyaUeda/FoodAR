#ifndef CHANNELFUNC_H
#define CHANNELFUNC_H

#include <QString>
#include "../../SDK/opencv/opencvApi.h"
#include "../matSet.h"


class ChannelFunc {

/*method*/
public:
    virtual int value(Mat img, int x, int y) {
        return B(img, x, y);
    }

    virtual int value(MatSet& matSet, int x, int y) {
        return B(matSet.bgr(), x, y);
    }
        

    virtual int value(MatSet& matSet, Point& point) {
         return value(matSet, point.x, point.y);
    }

    virtual QString getChannelName() {
        return "channel";
    }
   
    ChannelFunc();

private:

/*property*/  	
private:
   



};

#endif // CHANNELFUNCs_H
