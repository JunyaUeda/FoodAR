#include "stillTexture.h"

StillTexture::StillTexture(string path, string name) {
    _path = path;
	_img = imread(path, 1);
    _mediaType = MediaType::still;
    _name = name;
}

