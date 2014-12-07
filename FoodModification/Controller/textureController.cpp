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

	if(path.find("NoTexture") != String::npos) {
		_textureManager.updateCurrentTexture("NoTexture");
		return;
	}

    string uppercase_path;
    uppercase_path.resize(path.size());
    std::transform(path.cbegin(), path.cend(), uppercase_path.begin(), (int (*)(int))std::toupper);

    vector<string> imgExtensions;
    imgExtensions.push_back(".JPG");
    imgExtensions.push_back(".JPEG");
    imgExtensions.push_back(".PNG");
    vector<string> movieExtensions;
    movieExtensions.push_back(".AVI");
    movieExtensions.push_back(".MP4");
    movieExtensions.push_back(".WMV");

   //  for(string e : imgExtensions) {
   //  	unsigned int result = uppercase_path.find(e);
   //  	if(result != String::npos) {
   //  		_textureManager.setTextureImg(imread(path, 1));
   //  		_textureManager.setTextureType(JU_PICTURE);
   //  		return;
   //  	}
   //  }

   //  for(string e : movieExtensions) {
   //  	unsigned int result = uppercase_path.find(e);
   //  	if(result != String::npos) {
   //  		_textureManager.setCapture(VideoCapture(_textureManager.srcPath()));
   //  		Mat textureImg;
   //  		_textureManager.capture()  >> textureImg;
			// _textureManager.setTextureImg(textureImg);
			// _textureManager.setTextureType(JU_MOVIE);

			// return;
   //  	}
   //  }
    
}
