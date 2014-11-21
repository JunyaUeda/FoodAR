#ifndef TEXTUREMANAGER_H
#define TEXTUREMANAGER_H

#include "../TypeDef.h"
#include "../SDK/opencv/opencvApi.h"
#include "../Param/Texture/texture.h"
#include "../Param/Texture/stillTexture.h"
#include "../Param/Texture/movieTexture.h"
#include "../Param/Texture/noTexture.h"

class TextureManager {

/*property*/
private:
    Texture* _current;
    QList<Texture> _allTextures;
    QString _path;
    MediaType _currentMediaType;
    
/*method*/    
public:
    static TextureManager& getInstance();

    void setUp();
    void setTexture(MediaType type, QString path="null",  QString name = "noTexture");
    void update();
private:
    TextureManager();
    TextureManager(const TextureManager&);
};

#endif // TEXTUREMANAGER_H
