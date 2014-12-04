#ifndef TEXTUREFACTORY_H
#define TEXTUREFACTORY_H

#include <QDebug>
#include "./Param/region.h"

class TextureFactory {

/*method*/
public:
    static TextureFactory& getInstance();
	void create(const Region& region, Mat& result);
    void updateSrc(Mat src);
private:
    TextureFactory();
    TextureFactory(const TextureFactory&);

/*property*/
private:
    Mat _src;
    Mat _resizedSrc;

};

#endif // TEXTUREFACTORY_H
