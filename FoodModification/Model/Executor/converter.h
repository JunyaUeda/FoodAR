#ifndef CONVERTER_H
#define CONVERTER_H

#include <QDebug>
#include "../SDK/opencv/opencvApi.h"
#include "../Param/region.h"
#include "../Param/matSet.h"
#include "../typeDef.h"

class Converter {

/*method*/    
public:
    static Converter& getInstance();
    void convert(const MatSet& srcSet, const Region& extractedRegion, const Mat& textureImg, Mat& dstBGRImg);
    void overlapTexture(const Mat& textureImg, const Region& extractedRegion, Mat& dstBGRImg);
    void updateAlpha(double value);
	void updateMediaType(MediaType type);

private:
	Converter();
    Converter(const Converter&);

/*property*/
private:
    double _alpha = 0.5;
    MediaType _textureMediaType;
};

#endif // CONVERTER_H
