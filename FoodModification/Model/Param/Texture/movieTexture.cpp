#include "movieTexture.h"

MovieTexture::MovieTexture(QString path, QString name) {
    _path = path;
	_capture = VideoCapture((string)path.toLocal8Bit());
    _capture >> _img;    
    _mediaType = MediaType::movie;
    _name = name;
}

VideoCapture MovieTexture::capture() const {
    return _capture;
}

void MovieTexture::update() {
    _capture >> _img;
}
