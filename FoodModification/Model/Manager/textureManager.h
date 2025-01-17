#ifndef TEXTUREMANAGER_H
#define TEXTUREMANAGER_H

#include <QDir>
#include <cctype>
#include <string>
#include <functional>
#include "../TypeDef.h"
#include "../SDK/opencv/opencvApi.h"
#include "../Param/Texture/texture.h"
#include "../Param/Texture/stillTexture.h"
#include "../Param/Texture/movieTexture.h"
#include "../Param/Texture/noTexture.h"

#include "../textureFactory.h"
#include "../Executor/converter.h"

class TextureManager {

/*method*/    
public:
    static TextureManager& getInstance();

    void setUp();
    void addTexture(const string path, const Texture texture);
    void addTexture(MediaType type, string path, string name);
    void updateCurrentTexture(const Texture texture);
    void updateCurrentTexture(const string path);

    MediaType currentMediaType() {
        return _currentTexture.mediaType();
    }
    
    
private:
    TextureManager();
    TextureManager(const TextureManager&);
    void loadTextureSrcFromDir();

/*property*/
private:
    Texture _currentTexture;
    map<string, Texture> _allTextures;
    string _path;
    MediaType _currentMediaType;
    TextureFactory& _textureFactory = TextureFactory::getInstance();
    Converter& _converter = Converter::getInstance();
	const string TEXTURE_DIRECTORY_PATH = "../FoodModification/Images";
    
};

#endif // TEXTUREMANAGER_H
