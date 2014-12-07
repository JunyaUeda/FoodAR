#ifndef TEXTURECONTROLLER_H
#define TEXTURECONTROLLER_H

#include <cctype>
#include <string>
#include <functional>
#include "../Model/SDK/opencv/opencvApi.h"
#include "../Model/Manager/textureManager.h"

class TextureController {

/*method*/
public:
	static TextureController& getInstance();
    void changeTextureImg(String path);
private:
	TextureController();
	TextureController(const TextureController&);

/*property*/
private: 
    TextureManager& _textureManager = TextureManager::getInstance(); 
};

#endif // TEXTURECONTROLLER_H
