#ifndef OUTPUTER_H
#define OUTPUTER_H

#include "../SDK/opencv/opencvApi.h"

class Outputer {

/*method*/
public:
    static Outputer& getInstance();
    void show(Mat& img);
    void updateDstSize(Size& size);
private:
	Outputer();
    Outputer(const Outputer&);

/*property*/
private:
    bool _isFullScreenSize = false;
    Size _dstSize;
};

#endif // OUTPUTER_H
