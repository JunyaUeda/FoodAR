#include "srcController.h"
#include <QDebug>
#include <QtCore>
#include <cctype>
#include <string>
#include <functional>

SrcController::SrcController() {

}

SrcController& SrcController::getInstance() {
	static SrcController instance;
	return instance;
}


/**
* mainWindowのサイズ設定によって呼び出される.カメラ入力のサイズを変更する
*　@param cv::Size
*/
void SrcController::setVCaptureSize(Size size) {
    //_cameraManager.setCaptureSize(size);
}


/**
* mainWindowのテクスチャ選択によって呼び出される
*　@param textureのImageのパス
*/
void SrcController::changeTextureImg(String path) {

	// if(path.find("noTexture") != String::npos) {
	// 	_textureManager.setTextureType(JU_NOTEXTURE);
	// 	return;
	// }

 //    _textureManager.setSrcPath(path);

 //    string uppercase_path;
 //    uppercase_path.resize(path.size());
 //    std::transform(path.cbegin(), path.cend(), uppercase_path.begin(), (int (*)(int))std::toupper);

 //    vector<string> imgExtensions;
 //    imgExtensions.push_back(".JPG");
 //    imgExtensions.push_back(".JPEG");
 //    imgExtensions.push_back(".PNG");
 //    vector<string> movieExtensions;
 //    movieExtensions.push_back(".AVI");
 //    movieExtensions.push_back(".MP4");
 //    movieExtensions.push_back(".WMV");

 //    for(string e : imgExtensions) {
 //    	unsigned int result = uppercase_path.find(e);
 //    	if(result != String::npos) {
 //    		_textureManager.setTextureImg(imread(path, 1));
 //    		_textureManager.setTextureType(JU_PICTURE);
 //    		return;
 //    	}
 //    }

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


/**
* mainWindowの抽出タグのsplitColorのcomboBoxによって呼び出される
*　@param splitするcolorSpace:int
* @note uiにおけるcomboBoxのindexとdefinition.hのcolorSpaceIndexが一致している必要がある
*/
void SrcController::changeSplitColorSpace(int colorSpaceIndex) {
   //_textureManager.setSplitColorSpace(colorSpaceIndex);
}
