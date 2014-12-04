#include "texture.h"

Texture::Texture() {
}

Mat Texture::img() const {
    return _img;
}

string Texture::name() const {
    return _name;
}

string Texture::path() const {
    return _path;
}

void Texture::setName(const string &name) {
    _name = name;
}