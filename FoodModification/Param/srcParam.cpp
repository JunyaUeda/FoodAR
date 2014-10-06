#include "srcParam.h"

SrcParam::SrcParam() {
}

String SrcParam::srcPath() const
{
	return _srcPath;
}

void SrcParam::setSrcPath(const String &srcPath)
{
	_srcPath = srcPath;
}

Size SrcParam::cameraSize() const
{
    return _cameraSize;
}

void SrcParam::setCameraSize(const Size &cameraSize)
{
    _cameraSize = cameraSize;
}

Mat SrcParam::textureImg() const
{
	return _textureImg;
}

void SrcParam::setTextureImg(const Mat &textureImg)
{
    _textureImg = textureImg;
}
int SrcParam::textureType() const
{
	return _textureType;
}

void SrcParam::setTextureType(int textureType)
{
	_textureType = textureType;
}

int SrcParam::splitColorSpace() const
{
	return _splitColorSpace;
}

void SrcParam::setSplitColorSpace(int splitColorSpace)
{
	_splitColorSpace = splitColorSpace;
}
