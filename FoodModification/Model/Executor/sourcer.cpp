#include "sourcer.h"

Sourcer::Sourcer() {
}

Sourcer& Sourcer::getInstance() {
    static Sourcer instance;
    return instance;
}

bool Sourcer::setUp() {

    _cameraManager.setUp();

    _textureManager.setUp();

    return true;
}

void Sourcer::loadSrc(MatSet& srcSet) {

    Mat bgrImg = _cameraManager.getFrame();
   
    srcSet.setBgr(bgrImg);
    srcSet.addChannelImgs(SpaceType::bgr);
    srcSet.addChannelImgs(SpaceType::hsv);
    srcSet.addChannelImgs(SpaceType::ycrcb);

    _textureManager.update();
}
