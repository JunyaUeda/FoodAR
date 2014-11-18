#ifndef TEXTUREMANAGER_H
#define TEXTUREMANAGER_H
#include "../definition.h"
#include "./SDK/opencv/opencvApi.h"

class TextureManager {

/*property*/
private:
	VideoCapture  _capture;
    int _splitColorSpace = JU_YCrCb;
    String _srcPath;
    Mat _textureImg;
    int _textureType = JU_PICTURE; //JU_NOTEXTURE, JU_PICTURE, JU_MOVIE

/*method*/    
public:
    static TextureManager& getInstance();

    void setUp();
    void setTextureSource();
    VideoCapture capture();
	//void setCapture(VideoCapture capture) const;
    String srcPath() const;
    void setSrcPath(const String &srcPath);

    Mat textureImg() const;
    void setTextureImg(const Mat &textureImg);

    int textureType() const;
    void setTextureType(int textureType);

    int splitColorSpace() const;
    void setSplitColorSpace(int splitColorSpace);
private:
    TextureManager();
    TextureManager(const TextureManager&);
};

#endif // TEXTUREMANAGER_H
