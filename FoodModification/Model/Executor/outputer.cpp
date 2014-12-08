#include "outputer.h"

Outputer::Outputer() {
}

Outputer& Outputer::getInstance() {
    static Outputer instance;
    return instance;
}
void Outputer::setUp() {
    _windowManager.createWindow(QString("dst"));
}
void Outputer::show(Mat& img) {
    if(_isFullScreenSize) {
        resize(img, img, _dstSize, 0, 0, INTER_LINEAR);
        imshow("full", img);
    } else {
        imshow("dst", img);
    }
    
}

void Outputer::updateDstSize(Size& size) {
    _dstSize = size;
}