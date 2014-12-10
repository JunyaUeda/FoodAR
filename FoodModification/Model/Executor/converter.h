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
            qDebug() << "contour is empty in convert()";
            return;
        }
        
        if(_isOriginalValueUsed) {

            if(_textureMediaType != MediaType::no) {
                overlapTexture(srcSet, textureImg, extractedRegion, dstBGRImg);
            } 
            convertHSV(srcSet, extractedRegion, dstBGRImg);

        } else {

            if(_textureMediaType != MediaType::no) {
                overlapTextureWithAverageCalc(srcSet, textureImg, extractedRegion, dstBGRImg);
            } 
            convertHSVWithTextureValue(srcSet, extractedRegion, dstBGRImg);
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

    
    void updateAlpha(double value);
	void updateMediaType(MediaType type);
    void updateVariableHSVShift(int hue, int saturation, int value);
    void updateRatioPixelNum(double upperRatio, double underRatio) {
        _ratioOfUpperPixelNum = upperRatio;
        _ratioOfUnderPixelNum = underRatio;
    }
    void setOriginalValueUsedFlag(bool flag) {
        _isOriginalValueUsed = flag;
    }
private:
	Converter();
    Converter(const Converter&);

    void overlapTexture(const MatSet& srcSet, const Mat& textureImg, const Region& extractedRegion, Mat& dstBGRImg) {

           
        vint sum(9,0);
        int pixelSum=0;
        vint averages(9,0);
        // vint medians(9,0);
        // vint upperTolerances(9,0);
        // vint underTolerances(9,0);
        // int greenFrequency[256] = {0};
        // int yFrequency[256] = {0};
        // int crFrequency[256] = {0};
        // int cbFrequency[256] = {0};

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
                    // greenFrequency[G(srcSet.bgr(), x, y)]++;
                    // yFrequency[B(srcSet.ycrcb(), x, y)]++;
                    // crFrequency[G(srcSet.ycrcb(), x, y)]++;
                    // cbFrequency[R(srcSet.ycrcb(), x, y)]++;
                    pixelSum++;
                }
            }
        }

        //calculate average;
        for(int i=0; i<9; i++) {
            averages[i] = static_cast<int>((float)sum[i] / (float)pixelSum);
        }
        _featureReference.updateAverages(averages);


        // int harfOfPixelSum = (int)((double)pixelSum/2.0);
        // int underOfPixelSum = (int)((double)pixelSum*0.1);
        // int upperOfPixelSum = (int)((double)pixelSum*0.9);

        // int greenPixelCount = 0;
        // int greenMedian = 0;
        // int greenUpperTolerance = 0;
        // int greenUnderTolerance = 0;

        // for(int bin =0; bin<256; bin++ ) {
        //     greenPixelCount = greenPixelCount + greenFrequency[bin];
        //     if(greenPixelCount <= underOfPixelSum) {
        //         greenUnderTolerance = bin;
        //         continue;
        //     }
        //     if(greenPixelCount <= harfOfPixelSum) {
        //         greenMedian = bin;
        //         continue;
        //     }
        //     if(greenPixelCount >= upperOfPixelSum) {
        //         greenUpperTolerance = bin;
        //         break;
        //     }

        // }
        // int yPixelCount = 0;
        // int yMedian = 0;
        // int yUpperTolerance = 0;
        // int yUnderTolerance = 0;
        // for(int bin =0; bin<256; bin++ ) {
        //     yPixelCount = yPixelCount + yFrequency[bin];
        //     if(yPixelCount <= underOfPixelSum) {
        //         yUnderTolerance = bin;
        //         continue;
        //     }
        //     if(yPixelCount <= harfOfPixelSum) {
        //         yMedian = bin;
        //         continue;
        //     }
        //     if(yPixelCount >= upperOfPixelSum) {
        //         yUpperTolerance = bin;
        //         break;
        //     }
        // }
        // int crPixelCount = 0;
        // int crMedian = 0;
        // int crUpperTolerance = 0;
        // int crUnderTolerance = 0;
        // for(int bin =0; bin<256; bin++ ) {
        //     crPixelCount = crPixelCount + crFrequency[bin];
        //     if(crPixelCount <= underOfPixelSum) {
        //         crUnderTolerance = bin;
        //         continue;
        //     }
        //     if(crPixelCount <= harfOfPixelSum) {
        //         crMedian = bin;
        //         continue;
        //     }
        //     if(crPixelCount >= upperOfPixelSum) {
        //         crUpperTolerance = bin;
        //         break;
        //     }
        // }
        // int cbPixelCount = 0;
        // int cbMedian = 0;
        // int cbUpperTolerance = 0;
        // int cbUnderTolerance = 0;
        // for(int bin =0; bin<256; bin++ ) {
        //     cbPixelCount = cbPixelCount + cbFrequency[bin];
        //     if(cbPixelCount <= underOfPixelSum) {
        //         cbUnderTolerance = bin;
        //         continue;
        //     }
        //     if(cbPixelCount <= harfOfPixelSum) {
        //         cbMedian = bin;
        //         continue;
        //     }
        //     if(cbPixelCount >= upperOfPixelSum) {
        //         cbUpperTolerance = bin;
        //         break;
        //     }

        // }

        
        
        // medians[1] = greenMedian;
        // medians[6] = yMedian;
        // medians[7] = crMedian;
        // medians[8] = cbMedian;
        // upperTolerances[1] = greenUpperTolerance;
        // upperTolerances[6] = yUpperTolerance;
        // upperTolerances[7] = crUpperTolerance;
        // upperTolerances[8] = cbUpperTolerance;
        // underTolerances[1] = greenUnderTolerance;
        // underTolerances[6] = yUnderTolerance;
        // underTolerances[7] = crUnderTolerance;
        // underTolerances[8] = cbUnderTolerance;
        // _featureReference.updateMedianAndTolerance(medians, upperTolerances, underTolerances);
    }
    void overlapTextureWithAverageCalc(const MatSet& srcSet, const Mat& textureImg, const Region& extractedRegion, Mat& dstBGRImg) {
        vint sum(9,0);
        int pixelSum=0;
        vint averages(9,0);
        
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
        for(int i=0; i<9; i++) {
            averages[i] = static_cast<int>((float)sum[i] / (float)pixelSum);
        }
        _featureReference.updateAverages(averages);
    
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

    void convertHSVWithTextureValue(const MatSet& srcSet, const Region& extractedRegion, Mat& dstBGRImg) {
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
                    V(dstHSVImg,x,y) = V(dstHSVImg,x,y) + _variableValueShift;
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
    double _ratioOfUnderPixelNum = 0.05;
    double _ratioOfUpperPixelNum = 0.95;
    bool _isOriginalValueUsed = true;
    MediaType _textureMediaType;
    FeatureReference& _featureReference = FeatureReference::getInstance();

};

#endif // CONVERTER_H
