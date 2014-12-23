#ifndef SOURCER_H
#define SOURCER_H

#include "../Param/matSet.h"
#include "../SDK/opencv/opencvApi.h"
#include "../Manager/cameraManager.h"
#include "../Manager/textureManager.h"
#include "../Manager/inputManager.h"

class Sourcer {

/*method*/
public:
    static Sourcer& getInstance();
    bool setUp();
    void loadSrc() {
        Mat& bgrImg = _cameraManager.getFrame();
        //srcSet.setBgr(bgrImg);
        _inputManager.updateCurrentSrc(bgrImg);

    }
    
private:
    Sourcer();
    Sourcer(const Sourcer&);
    
/*property*/
private:
    CameraManager& _cameraManager = CameraManager::getInstance();
    TextureManager& _textureManager = TextureManager::getInstance();
    InputManager& _inputManager = InputManager::getInstance();

};

#endif // SOURCER_H
