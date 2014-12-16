#ifndef TEXTUREFACTORY_H
#define TEXTUREFACTORY_H

#include <QDebug>
#include "./Param/region.h"
#include "./Manager/regionManager.h"

class TextureFactory {

/*method*/
public:
    static TextureFactory& getInstance();
	void create(Mat& result);
    void updateSrc(Mat src);
private:
    TextureFactory();
    TextureFactory(const TextureFactory&);

/*property*/
private:
    Mat _src;
    Mat _resizedSrc;
    RegionManager& _regionManager = RegionManager::getInstance();

};

#endif // TEXTUREFACTORY_H
