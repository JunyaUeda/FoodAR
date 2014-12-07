#include "cameraManager.h"

CameraManager::CameraManager() {
    setUp();
}

CameraManager& CameraManager::getInstance() {
    static CameraManager instance;
    return instance;
}

bool CameraManager::setUp() {
    bindCamera(0);
    setCaptureSize(_defaultSize);
	//_extractor.setScoreMatZeroAndSize(_defaultSize);
	if(_capture.isOpened()) {
        return true;
    }
	return false;
}

void CameraManager::bindCamera(int port) {
    _capture = VideoCapture(port);
}

void CameraManager::setCaptureSize(Size size) {
    _size = size;
	_capture.set(CV_CAP_PROP_FRAME_WIDTH, size.width);
	_capture.set(CV_CAP_PROP_FRAME_HEIGHT, size.height);
}

void CameraManager::setCaptureSaturation(double value) {
    _captureSaturation = value;
    _capture.set(CV_CAP_PROP_SATURATION, value);
        
}

void CameraManager::setCaptureExposure(double value) {
    _captureExposure = value;
    _capture.set(CV_CAP_PROP_EXPOSURE, value);
}

void CameraManager::setCaptureGain(double value) {
    _captureGain = value;
    _capture.set(CV_CAP_PROP_GAIN, value);
}

void CameraManager::setCaptureBrightness(double value) {
    _captureBrightness = value;
    _capture.set(CV_CAP_PROP_BRIGHTNESS, value);
}

void CameraManager::setCaptureContrast(double value) {
    _captureContrast = value;
    _capture.set(CV_CAP_PROP_CONTRAST, value);
}

void CameraManager::save(QXmlStreamWriter& writer) {
   
    writer.writeStartElement("Camera"); // root element start

    writer.writeStartElement("input size"); // element1 start
    QXmlStreamAttributes inputSizes;
    inputSizes.append("width", QtUtil::toQString(_size.width));
    inputSizes.append("height", QtUtil::toQString(_size.width));
    writer.writeAttributes(inputSizes);
    writer.writeEndElement(); // element1 end

    writer.writeEndElement(); // root end
  
}
