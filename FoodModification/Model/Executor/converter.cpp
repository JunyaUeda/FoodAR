#include "converter.h"

Converter::Converter() {
}

Converter& Converter::getInstance() {
    static Converter instance;
    return instance;
}

void Converter::updateAlpha(double value) {
    _alpha = value;
}

void Converter::updateMediaType(MediaType type) {
    _textureMediaType = type;
}

void Converter::updateVariableHSVShift(int hue, int saturation, int value) {
    _variableHueShift = hue;
    _variableSaturationShift = saturation;
    _variableValueShift = value;
}

// 
// void Converter::convertHSVAndIllumination(Mat srcBGRImg, Mat maskImg, vector<Rect>& rects, TextureParam* textureParam, double intensityFactor) {

    
//     Mat dstHSVImg;
//     cvtColor(srcBGRImg, dstHSVImg, CV_BGR2HSV);
//     for(int i=0; i<rects.size(); i++) {
//         for(int y=rects[i].y; y<(rects[i].y+rects[i].height); y++) {
//             for(int x=rects[i].x; x<(rects[i].x+rects[i].width); x++){
//                 if(L(maskImg,x,y) == 255) {
//                     H(dstHSVImg,x,y) = H(dstHSVImg,x,y) + textureParam->getH_shift();
//                     S(dstHSVImg,x,y) = S(dstHSVImg,x,y) + textureParam->getS_shift();
//                     V(dstHSVImg,x,y) = V(dstHSVImg,x,y) + textureParam->getV_shift();
//                 }
//             }
//         }
//     }

//     for(int y=0; y<srcBGRImg.rows; y++) {
//         for(int x=0; x<srcBGRImg.cols; x++) {
//             V(dstHSVImg,x,y) = changeIllumination(V(dstHSVImg,x,y), intensityFactor);
//         }
//     }
//     cvtColor(dstHSVImg, srcBGRImg, CV_HSV2BGR);

// }


// int Converter::changeIllumination(int currentValue, double intensityFactor) {

//     if(currentValue * intensityFactor > 255) {
//         return 255;
//     } else {
//         return (int)currentValue * intensityFactor;
//     }

// }

// void Converter::convertZ(Mat srcBGRImg, double ZFactor) {

//     Mat dstXYZImg;
//     cvtColor(srcBGRImg, dstXYZImg, CV_BGR2XYZ);
//     for(int y=0; y<srcBGRImg.rows; y++) {
//         for(int x=0; x<srcBGRImg.cols; x++) {
//             if(V(dstXYZImg,x,y) * ZFactor > 255) {
//                 V(dstXYZImg,x,y) =  255;
//             } else {
//                 V(dstXYZImg,x,y) = V(dstXYZImg,x,y) * ZFactor;
//             }
//         }
//     }
//     cvtColor(dstXYZImg, srcBGRImg, CV_XYZ2BGR);
// }
