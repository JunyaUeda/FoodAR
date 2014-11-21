#ifndef SOURCER_H
#define SOURCER_H

#include "../Param/matSet.h"
#include "../SDK/opencv/opencvApi.h"
#include "../Manager/cameraManager.h"
#include "../Manager/textureManager.h"

class Sourcer {

/*property*/
private:
    CameraManager& _cameraManager = CameraManager::getInstance();
    TextureManager& _textureManager = TextureManager::getInstance();
/*method*/
public:
    static Sourcer& getInstance();
    bool setUp();
    void loadSrc(MatSet& srcSet);
private:
	Sourcer();
    Sourcer(const Sourcer&);
};

#endif // SOURCER_H
