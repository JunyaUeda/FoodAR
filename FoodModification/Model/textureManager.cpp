#include "textureManager.h"

TextureManager::TextureManager() {
}

TextureManager& TextureManager::getInstance() {
    static TextureManager instance;
    return instance;
}

void TextureManager::setUp() {
    if( _textureType == JU_MOVIE) {
        _capture = VideoCapture(_srcPath);
    }
}

void TextureManager::setTextureSource() {
    if(_textureType == JU_MOVIE) {
        Mat textureImg;
        _capture  >> textureImg;
        _textureImg = textureImg;
    }
}

VideoCapture TextureManager::capture() {
    return _capture;
}

// void TextureManager::setCapture(VideoCapture capture) const {
//     _capture = capture;
// }

String TextureManager::srcPath() const
{
    return _srcPath;
}

void TextureManager::setSrcPath(const String &srcPath)
{
    _srcPath = srcPath;
}

Mat TextureManager::textureImg() const
{
    return _textureImg;
}

void TextureManager::setTextureImg(const Mat &textureImg)
{
    _textureImg = textureImg;
}
int TextureManager::textureType() const
{
    return _textureType;
}

void TextureManager::setTextureType(int textureType)
{
    _textureType = textureType;
}

int TextureManager::splitColorSpace() const
{
    return _splitColorSpace;
}

void TextureManager::setSplitColorSpace(int splitColorSpace)
{
    _splitColorSpace = splitColorSpace;
}
