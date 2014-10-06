#ifndef SRCPARAM_H
#define SRCPARAM_H
#include "../definition.h"
#include "../Utils/opencvBase.h"

class SrcParam {
public:
	SrcParam();
		
	String srcPath() const;
	void setSrcPath(const String &srcPath);

	Size cameraSize() const;
	void setCameraSize(const Size &cameraSize);

	Mat textureImg() const;
	void setTextureImg(const Mat &textureImg);

	int textureType() const;
	void setTextureType(int textureType);

	int splitColorSpace() const;
	void setSplitColorSpace(int splitColorSpace);

private:
	int _splitColorSpace = YCrCb;
	String _srcPath;
	Size _cameraSize;
	Mat _textureImg;
	int _textureType = JU_PICTURE; //JU_NOTEXTURE, JU_PICTURE, JU_MOVIE
};

#endif // SRCPARAM_H
