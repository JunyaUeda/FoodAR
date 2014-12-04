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
