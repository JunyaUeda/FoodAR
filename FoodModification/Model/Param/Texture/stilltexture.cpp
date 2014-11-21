#include "stillTexture.h"

StillTexture::StillTexture(QString path, QString name) {
    _path = path;
	_img = imread((string)path.toLocal8Bit(), 1);
    _mediaType = MediaType::still;
    _name = name;
}

void StillTexture::update() {}
