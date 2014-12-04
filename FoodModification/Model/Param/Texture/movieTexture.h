#ifndef MOVIETEXTURE_H
#define MOVIETEXTURE_H

#include "texture.h"

class MovieTexture : public Texture {

/*method*/    
public:
    MovieTexture(string path, string name);
    VideoCapture capture() const;
    Mat img();

/*property*/
private:
    VideoCapture _capture;

};

#endif // MOVIETEXTURE_H
