#include "cameraManager.h"

CameraManager::CameraManager() {
}

CameraManager& CameraManager::getInstance() {
    static CameraManager instance;
    return instance;
}

bool CameraManager::setUp() {
    bindCamera(0);
    setCaptureSize(_defaultSize);

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