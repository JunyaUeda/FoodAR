#ifndef CONVERTER_H
#define CONVERTER_H

#include <QDebug>
#include "../SDK/opencv/opencvApi.h"
#include "../Param/region.h"
#include "../Param/matSet.h"
#include "../typeDef.h"
#include "../featureReference.h"

class Converter {

/*method*/    
public:
    static Converter& getInstance();
    void convert(const MatSet& srcSet, const Region& extractedRegion, const Mat& textureImg, Mat& dstBGRImg) {
        if(!extractedRegion.contour().size()) {
            return;
        }
        if(_textureMediaType != MediaType::no) {
            overlapTexture(srcSet, textureImg, extractedRegion, dstBGRImg);
        } 
        
        convertHSV(srcSet, extractedRegion, dstBGRImg);

        // if(_illuminationParam->intensityChange()) {
        //     convertHSVAndIllumination(dstBGRImg, maskImg, rects, textureParam, _illuminationParam->intensityFactor());
        // } else {
        //     convertHSV(dstBGRImg, srcHSVImg, maskImg, rects, textureParam);
        // }

        // if(_illuminationParam->ZChange()) {
        //     convertZ(dstBGRImg, _illuminationParam->ZFactor());
        // }

    }

    
    void updateAlpha(double value);
	void updateMediaType(MediaType type);
    void updateVariableHSVShift(int hue, int saturation, int value);

private:
	Converter();
    Converter(const Converter&);

    void overlapTexture(const MatSet& srcSet, const Mat& textureImg, const Region& extractedRegion, Mat& dstBGRImg) {

        vint sum(9,0);
        int pixelSum=0;

        int yBegin = extractedRegion.roi().y;
        int yEnd = extractedRegion.roi().y+extractedRegion.roi().height;
        int xBegin = extractedRegion.roi().x;
        int xEnd = extractedRegion.roi().x+extractedRegion.roi().width;
        
        for(int y=yBegin; y<yEnd; y++) {
            for(int x=xBegin; x<xEnd; x++){
                if(L(extractedRegion.maskImg(),x,y) == 255) {

                    //overlapTexture
                    B(dstBGRImg,x,y) = _alpha*B(dstBGRImg,x,y) + (1-_alpha)*B(textureImg,x,y);
                    G(dstBGRImg,x,y) = _alpha*G(dstBGRImg,x,y) + (1-_alpha)*G(textureImg,x,y);
                    R(dstBGRImg,x,y) = _alpha*R(dstBGRImg,x,y) + (1-_alpha)*R(textureImg,x,y);

                    //count Sum
                    sum[0] = sum[0] + B(srcSet.bgr(), x, y);
                    sum[1] = sum[1] + G(srcSet.bgr(), x, y);
                    sum[2] = sum[2] + R(srcSet.bgr(), x, y);
                    sum[3] = sum[3] + B(srcSet.hsv(), x, y);
                    sum[4] = sum[4] + G(srcSet.hsv(), x, y);
                    sum[5] = sum[5] + R(srcSet.hsv(), x, y);
                    sum[6] = sum[6] + B(srcSet.ycrcb(), x, y);
                    sum[7] = sum[7] + G(srcSet.ycrcb(), x, y);
                    sum[8] = sum[8] + R(srcSet.ycrcb(), x, y);
                    pixelSum++;
                }
            }
        }


        //calculate average;
        vint averages(9,0);
        for(int i=0; i<9; i++) {
            averages[i] = static_cast<int>((float)sum[i] / (float)pixelSum);
        }
        
       // _featureReference.updateAverages(averages);
    }

    void convertHSV(const MatSet& srcSet, const Region& extractedRegion, Mat& dstBGRImg) {
 
        Mat dstHSVImg;
        cvtColor(dstBGRImg, dstHSVImg, CV_BGR2HSV);

        int yBegin = extractedRegion.roi().y;
        int yEnd = extractedRegion.roi().y+extractedRegion.roi().height;
        int xBegin = extractedRegion.roi().x;
        int xEnd = extractedRegion.roi().x+extractedRegion.roi().width;

        for(int y=yBegin; y<yEnd; y++) {
            for(int x=xBegin; x<xEnd; x++){
                if(L(extractedRegion.maskImg(),x,y) == 255) {
                    H(dstHSVImg,x,y) = H(dstHSVImg,x,y) + _variableHueShift;
                    S(dstHSVImg,x,y) = S(dstHSVImg,x,y) + _variableSaturationShift;
                    V(dstHSVImg,x,y) = V(srcSet.hsv(),x,y) + _variableValueShift;
                }
            }
        }
    
        cvtColor(dstHSVImg, dstBGRImg, CV_HSV2BGR);
}

/*property*/
private:
    double _alpha = 0.3;
    int _variableHueShift = 0;
    int _variableSaturationShift=0;
    int _variableValueShift=0;
    MediaType _textureMediaType;
    FeatureReference& _featureReference = FeatureReference::getInstance();
};

#endif // CONVERTER_H
