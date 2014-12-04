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
    void convert(const MatSet& srcSet, const Region& extractedRegion, const Mat& textureImg, Mat& dstBGRImg) {
        if(_textureMediaType != MediaType::no) {
            overlapTexture(textureImg, extractedRegion, dstBGRImg);
        } 
        

        // if(_illuminationParam->intensityChange()) {
        //     convertHSVAndIllumination(dstBGRImg, maskImg, rects, textureParam, _illuminationParam->intensityFactor());
        // } else {
        //     convertHSV(dstBGRImg, srcHSVImg, maskImg, rects, textureParam);
        // }

        // if(_illuminationParam->ZChange()) {
        //     convertZ(dstBGRImg, _illuminationParam->ZFactor());
        // }

    }

    void overlapTexture(const Mat& textureImg, const Region& extractedRegion, Mat& dstBGRImg) {
        for(int i=0; i<extractedRegion.rois().size(); i++) {

            for(int y=extractedRegion.rois()[i].y; y<(extractedRegion.rois()[i].y+extractedRegion.rois()[i].height); y++) {
                for(int x=extractedRegion.rois()[i].x; x<(extractedRegion.rois()[i].x+extractedRegion.rois()[i].width); x++){
                    if(L(extractedRegion.maskImg(),x,y) == 255) {
                        B(dstBGRImg,x,y) = _alpha*B(dstBGRImg,x,y) + (1-_alpha)*B(textureImg,x,y);
                        G(dstBGRImg,x,y) = _alpha*G(dstBGRImg,x,y) + (1-_alpha)*G(textureImg,x,y);
                        R(dstBGRImg,x,y) = _alpha*R(dstBGRImg,x,y) + (1-_alpha)*R(textureImg,x,y);
                    }
                }
            }

        }
    }
    
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
