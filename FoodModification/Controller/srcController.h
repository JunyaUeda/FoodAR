#ifndef SRCCONTROLLER_H
#define SRCCONTROLLER_H
#include "../Model/cameraManager.h"
#include "../Model/textureManager.h"
#include "../Model/SDK/opencv/opencvApi.h"
#include "../definition.h"

class SrcController {

/*property*/
private:
	CameraManager& _cameraManager = CameraManager::getInstance();
    TextureManager& _textureManager = TextureManager::getInstance();
/*method*/
public:
	static SrcController& getInstance();
	void setVCaptureSize(Size size);
	void changeTextureImg(String path);
	void changeSplitColorSpace(int colorSpaceIndex);

private:
	SrcController();
	SrcController(const SrcController&);
	
};

#endif // SRCCONTROLLER_H
