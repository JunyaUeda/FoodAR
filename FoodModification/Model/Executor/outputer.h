#ifndef OUTPUTER_H
#define OUTPUTER_H

#include "../SDK/opencv/opencvApi.h"
#include "../Manager/windowManager.h"

class Outputer {

/*method*/
public:
    static Outputer& getInstance();
    void setUp();
    void show(Mat& img);
    void updateDstSize(Size& size);
    void fullScreen() {
        _isFullScreenSize = true;
    }
    void unFullScreen() {
        _isFullScreenSize = false;
    }
private:
	Outputer();
    Outputer(const Outputer&);

/*property*/
private:
    bool _isFullScreenSize = false;
    Size _dstSize = Size(1280, 720);
    WindowManager& _windowManager = WindowManager::getInstance();
};

#endif // OUTPUTER_H
