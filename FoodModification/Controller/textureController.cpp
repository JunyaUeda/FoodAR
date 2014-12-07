#include "textureController.h"
#include <QDebug>

TextureController::TextureController() {

}

TextureController& TextureController::getInstance() {
	static TextureController instance;
	return instance;
}

/**
* mainWindowのテクスチャ選択によって呼び出される
*　@param textureのImageのパス
*/
void TextureController::changeTextureImg(String path) {
	_textureManager.updateCurrentTexture(path);
}
