#ifndef STILLTEXTURE_H
#define STILLTEXTURE_H

#include "texture.h"

class StillTexture : public Texture {
/*property*/

/*method*/
public:
	StillTexture(QString path, QString name);
    void update();
};

#endif // STILLTEXTURE_H
