#include "cameraManager.h"

CameraManager::CameraManager() {
}

CameraManager& CameraManager::getInstance() {
    static CameraManager instance;
    return instance;
}

void CameraManager::setUp() {
    bindCamera(0);
    setCaptureSize(_defaultSize);
    confirmCapture();
}

void CameraManager::bindCamera(int port) {
    _capture = VideoCapture(port);
}

void CameraManager::setCaptureSize(Size size) {
    _size = size;
	_capture.set(CV_CAP_PROP_FRAME_WIDTH, size.width);
	_capture.set(CV_CAP_PROP_FRAME_HEIGHT, size.height);
}

bool CameraManager::confirmCapture() {
    Mat srcImg;
    _capture >> srcImg;

    if(srcImg.empty()) {
        cerr << "videoCapture is failed." << endl;
        return false;
    }
    
    return true;
}

VideoCapture CameraManager::capture() {
    return _capture;
}