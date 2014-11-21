#include "texture.h"

Texture::Texture() {
}

Mat Texture::img() const {
    return _img;
}

QString Texture::name() const {
    return _name;
}

QString Texture::path() const {
    return _path;
}

void Texture::setName(const QString &name) {
    _name = name;
}