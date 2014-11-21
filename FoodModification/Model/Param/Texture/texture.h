#ifndef TEXTURE_H
#define TEXTURE_H
#include <QString>
#include "../../TypeDef.h"

class Texture {

/*property*/
protected:
    Mat _img;
    QString _name;
    QString _path;
    MediaType _mediaType;

/*method*/
public:
	Texture();
    Mat img() const;
    QString name() const;
    QString path() const;
    void setName(const QString &name);
	virtual void update(){}

};

#endif // TEXTURE_H
