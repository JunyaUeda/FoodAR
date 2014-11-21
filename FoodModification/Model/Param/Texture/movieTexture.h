#ifndef MOVIETEXTURE_H
#define MOVIETEXTURE_H

#include "texture.h"

class MovieTexture : public Texture {
/*property*/
private:
    VideoCapture  _capture;
/*property*/    
public:
	MovieTexture(QString path, QString name);
    VideoCapture capture() const;
    void update();
};

#endif // MOVIETEXTURE_H
