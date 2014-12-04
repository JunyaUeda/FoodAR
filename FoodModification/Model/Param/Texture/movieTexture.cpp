#include "movieTexture.h"

MovieTexture::MovieTexture(string path, string name) {
    _path = path;
	_capture = VideoCapture(path);
    _capture >> _img;    
    _mediaType = MediaType::movie;
    _name = name;
}

VideoCapture MovieTexture::capture() const {
    return _capture;
}

Mat MovieTexture::img() {
    _capture >> _img;
    return _img;
}