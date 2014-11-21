#include "textureManager.h"

TextureManager::TextureManager() {
    _current = new NoTexture();
}

TextureManager& TextureManager::getInstance() {
    static TextureManager instance;
    return instance;
}

void TextureManager::setUp() {
    
}

void TextureManager::setTexture(MediaType type, QString path,  QString name) {
    switch(type) {
        case no :
            _current = new NoTexture();
            break;
        case still :
            _current = new StillTexture(path, name);
            break;
        case movie :
            _current = new MovieTexture(path, name);
            break;    
    }
}

void TextureManager::update() {
	_current->update();
}
