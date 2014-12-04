#include "textureManager.h"

#define A_IMAGE_PATH "../FoodModification/Images/sarmon.jpg"

TextureManager::TextureManager() {
    Texture* texture = new NoTexture();
    addTexture(string("No Texture"), (*texture));
    addTexture(MediaType::still, A_IMAGE_PATH, "Sarmon");
    //updateCurrentTexture((*texture));
    updateCurrentTexture(A_IMAGE_PATH);
}

TextureManager& TextureManager::getInstance() {
    static TextureManager instance;
    return instance;
}

void TextureManager::setUp() {
    
}

void TextureManager::addTexture(const string path, const Texture texture) {
    _allTextures.insert(pair<string, Texture>(path, texture));
}

void TextureManager::addTexture(MediaType type, string path, string name) {
    switch(type) {
        case no :
            _allTextures.insert(pair<string, Texture>(path, (*new NoTexture()) ));
            break;
        case still :
            _allTextures.insert(pair<string, Texture>(path, (*new StillTexture(path, name)) ));
            break;
        case movie :
			_allTextures.insert(pair<string, Texture>(path, (*new MovieTexture(path, name)) ));
            break;    
    }
}

void TextureManager::updateCurrentTexture(const Texture texture) {
    _currentTexture = texture;
	_textureFactory.updateSrc(_currentTexture.img());
    _converter.updateMediaType(_currentTexture.mediaType());
}

void TextureManager::updateCurrentTexture(const string path) {

    map<string, Texture>::iterator aTexture;
    aTexture = _allTextures.find(path);
    if(aTexture != _allTextures.end()) {
        _currentTexture = aTexture->second;;
        _textureFactory.updateSrc(_currentTexture.img());
        _converter.updateMediaType(_currentTexture.mediaType());
    }
}

