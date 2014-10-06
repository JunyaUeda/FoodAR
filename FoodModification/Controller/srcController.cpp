#include "srcController.h"
#include <QDebug>
#include <QtCore>

SrcController::SrcController() {
}

SrcController& SrcController::getInstance() {
	static SrcController instance;
	return instance;
}

bool SrcController::bindSrc() {

	_videoCapture_camera = VideoCapture(0);

	Mat srcImg;
	_videoCapture_camera >> srcImg;
	
	if(isCaptured(srcImg)) {
		_srcParam->setCameraSize(srcImg.size());
	} else {
		cerr << "videoCapture is failed." << endl;
		return false;
	}

	if(_srcParam->textureType() == JU_MOVIE) {
		_videoCapture_file = VideoCapture(_srcParam->srcPath());
	}

	return true;
}

bool SrcController::isCaptured(Mat srcImg) {
    if ( srcImg.empty() ) {
     	return false;
    }
    return true;
}

void SrcController::loadSrc(Mat srcBGRImg, Mat srcHSVImg, Mat srcYCrCbImg, Mat srcGrayImg, Mat* splitChannels) {

	_videoCapture_camera >> srcBGRImg;
	cvtColor(srcBGRImg, srcHSVImg, CV_BGR2HSV);
    cvtColor(srcBGRImg, srcYCrCbImg,CV_BGR2YCrCb);
    cvtColor(srcBGRImg, srcGrayImg, CV_BGR2GRAY);

    switch(_srcParam->splitColorSpace()) {
        case BGR:
            split(srcBGRImg, splitChannels);
            break;
        case HSV:
            split(srcHSVImg, splitChannels);
            break;
        case YCrCb:
            split(srcYCrCbImg, splitChannels);
            break;
    }
    

    
    if(_srcParam->textureType() == JU_MOVIE) {
    	Mat textureImg;
		_videoCapture_file  >> textureImg;
		_srcParam->setTextureImg(textureImg);
	}
    
}

SrcParam *SrcController::srcParam() const {
	return _srcParam;
}

void SrcController::setSrcParam(SrcParam *srcParam) {
	_srcParam = srcParam;
}

/**
* mainWindowのサイズ設定によって呼び出される.カメラ入力のサイズを変更する
*　@param cv::Size
*/
void SrcController::setVCaptureSize(Size size) {
    _videoCapture_camera.set(CV_CAP_PROP_FRAME_WIDTH, size.width);
    _videoCapture_camera.set(CV_CAP_PROP_FRAME_HEIGHT, size.height);
}


/**
* mainWindowのテクスチャ選択によって呼び出される
*　@param textureのImageのパス
*/
void SrcController::changeTextureImg(String path) {

	if(path.find("noTexture") != String::npos) {
		_srcParam->setTextureType(JU_NOTEXTURE);
		return;
	}

    _srcParam->setSrcPath(path);

    string uppercase_path;
    uppercase_path.resize(path.size());
    transform(path.cbegin(), path.cend(), uppercase_path.begin(), toupper);

    vector<string> imgExtensions{".JPG", ".JPEG", ".PNG"};
	vector<string> movieExtensions{".AVI", ".MP4", ".WMV"};
    
    for(string e : imgExtensions) {
    	unsigned int result = uppercase_path.find(e);
    	if(result != String::npos) {
    		_srcParam->setTextureImg(imread(path, 1));
    		_srcParam->setTextureType(JU_PICTURE);
    		return;
    	}
    }

    for(string e : movieExtensions) {
    	unsigned int result = uppercase_path.find(e);
    	if(result != String::npos) {
    		_videoCapture_file = VideoCapture(_srcParam->srcPath());
    		Mat textureImg;
    		_videoCapture_file  >> textureImg;
			_srcParam->setTextureImg(textureImg);
			_srcParam->setTextureType(JU_MOVIE);

			return;
    	}
    }
    
}


/**
* mainWindowの抽出タグのsplitColorのcomboBoxによって呼び出される
*　@param splitするcolorSpace:int
* @note uiにおけるcomboBoxのindexとdefinition.hのcolorSpaceIndexが一致している必要がある
*/
void SrcController::changeSplitColorSpace(int colorSpaceIndex) {
    _srcParam->setSplitColorSpace(colorSpaceIndex);
}