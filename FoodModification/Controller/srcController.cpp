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

bool SrcController::bindSrc() {

	_videoCapture_camera = VideoCapture(0);
    _videoCapture_camera.set(CV_CAP_PROP_FRAME_WIDTH, 480);
    _videoCapture_camera.set(CV_CAP_PROP_FRAME_HEIGHT, 320);
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
        case JU_BGR:
            split(srcBGRImg, splitChannels);
            break;
        case JU_HSV:
            split(srcHSVImg, splitChannels);
            break;
        case JU_YCrCb:
            split(srcYCrCbImg, splitChannels);
            break;
    }
    

    
    if(_srcParam->textureType() == JU_MOVIE) {
    	Mat textureImg;
		_videoCapture_file  >> textureImg;
		_srcParam->setTextureImg(textureImg);
	}
    
}

void SrcController::loadSrc(Mat srcBGRImg, Mat srcHSVImg, Mat srcYCrCbImg, Mat srcGrayImg, map<int,Mat>* channels) {

    _videoCapture_camera >> srcBGRImg;
    cvtColor(srcBGRImg, srcHSVImg, CV_BGR2HSV);
    cvtColor(srcBGRImg, srcYCrCbImg,CV_BGR2YCrCb);
    cvtColor(srcBGRImg, srcGrayImg, CV_BGR2GRAY);

    Mat BGRChannels[3];
    Mat HSVChannels[3];
    Mat YCrCbChannels[3];

    split(srcBGRImg, BGRChannels);
    (*channels).insert( map<int,Mat>::value_type(JU_B, BGRChannels[0]) );
    (*channels).insert( map<int,Mat>::value_type(JU_G, BGRChannels[1]) );
    (*channels).insert( map<int,Mat>::value_type(JU_R, BGRChannels[2]) );

    split(srcHSVImg, HSVChannels);
    (*channels).insert( map<int,Mat>::value_type(JU_H, HSVChannels[0]) );
    (*channels).insert( map<int,Mat>::value_type(JU_S, HSVChannels[1]) );
    (*channels).insert( map<int,Mat>::value_type(JU_V, HSVChannels[2]) );

    split(srcYCrCbImg, YCrCbChannels);
    (*channels).insert( map<int,Mat>::value_type(JU_Y, YCrCbChannels[0]) );
    (*channels).insert( map<int,Mat>::value_type(JU_Cr, YCrCbChannels[1]) );
    (*channels).insert( map<int,Mat>::value_type(JU_Cb, YCrCbChannels[2]) );
    // switch(_srcParam->splitColorSpace()) {
    //     case JU_BGR:
    //         split(srcBGRImg, BGRChannels);
    //         break;
    //     case JU_HSV:
    //         split(srcHSVImg, HSVChannels);
    //         break;
    //     case JU_YCrCb:
    //         split(srcYCrCbImg, YCrCbChannels);
    //         break;
    // }
    
    
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
    std::transform(path.cbegin(), path.cend(), uppercase_path.begin(), (int (*)(int))std::toupper);

    vector<string> imgExtensions;
    imgExtensions.push_back(".JPG");
    imgExtensions.push_back(".JPEG");
    imgExtensions.push_back(".PNG");
    vector<string> movieExtensions;
    movieExtensions.push_back(".AVI");
    movieExtensions.push_back(".MP4");
    movieExtensions.push_back(".WMV");

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
