#include "textureManager.h"

#define A_IMAGE_PATH "../FoodModification/Images/sarmon.jpg"

TextureManager::TextureManager() {
    
     
    Texture* texture = new NoTexture();
    addTexture(string("../FoodModification/Images/NoTexture"), (*texture));
    loadTextureSrcFromDir();
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

//TODO : factoryメソッドかabstract factoryパターンを使うべし
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

/**private*/
//TODO:機能分割するべき
void TextureManager::loadTextureSrcFromDir() {

    QDir q_dir("../FoodModification/Images");
    QStringList filelist;
    if(q_dir.exists())  {
        filelist = q_dir.entryList();//全てのファイル・ディレクトリ名取得
    }

    vector<string> imgExtensions;
    imgExtensions.push_back(".JPG");
    imgExtensions.push_back(".JPEG");
    imgExtensions.push_back(".PNG");
    vector<string> movieExtensions;
    movieExtensions.push_back(".AVI");
    movieExtensions.push_back(".MP4");
    movieExtensions.push_back(".WMV");

    vector<string> pathStringList;
    for(QString filePath : filelist) {
        //QString→std::string
		string path = filePath.toLocal8Bit();
        pathStringList.push_back(path);
    }

    const string TEXTURE_DIRPATH = "../FoodModification/Images/";

    for(string path : pathStringList) {
        if(path == "." || path== "..") continue;
        //文字数分の領域確保
        string uppercase_path;
        uppercase_path.resize(path.size());
        //すべて大文字に変換
        std::transform(path.cbegin(), path.cend(), uppercase_path.begin(), (int (*)(int))std::toupper);
        
        for(string e : imgExtensions) {
			//静止画の拡張子を持っている検索
			unsigned int result = uppercase_path.find(e);
			if(result != String::npos) {
                 addTexture(MediaType::still, TEXTURE_DIRPATH+path, path);
                 break;
             }
        }

        for(string e : movieExtensions) {
            //動画の拡張子を持っているか検索
			unsigned int result = uppercase_path.find(e);
			if(result != String::npos) {
				addTexture(MediaType::movie, TEXTURE_DIRPATH+path, path);
                break;
            }
        }
    }
   map<string, Texture>::iterator p;
   for(p=_allTextures.begin(); p != _allTextures.end(); p++) {
        QString qstr = QString::fromStdString(p->first);
        qDebug() << qstr;
   }
}
