#ifndef TEXTURE_H
#define TEXTURE_H

#include "../../TypeDef.h"

class Texture {

/*method*/
public:
    Texture();
    Mat img() const;
    string name() const;
    string path() const;
    void setName(const string &name);
    MediaType mediaType() {
        return _mediaType;
    }

/*property*/
protected:
    Mat _img;
    string _name;
    string _path;
    MediaType _mediaType;



};

#endif // TEXTURE_H
