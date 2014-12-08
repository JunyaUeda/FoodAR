#include "opencvApi.h"

OpenCVAPI::OpenCVAPI() {
}

// Rect OpenCVAPI::calculateROI(Size imgSize, Rect srcRect, double scaleRatio) {

//     Rect scaledRect = scaleRect(srcRect, scaleRatio);

//     int roi_x=0, roi_y=0, roi_w=0, roi_h=0;

//     if(scaledRect.x < 0) roi_x=0;
//     else roi_x = scaledRect.x;

//     if( (scaledRect.x+scaledRect.width) > imgSize.width ) roi_w = imgSize.width - scaledRect.x;
//     else roi_w = scaledRect.width;
                
//     if(scaledRect.y<0) roi_y=0;
//     else roi_y = scaledRect.y;

//     if( (scaledRect.y+scaledRect.height) > imgSize.height ) roi_h = imgSize.height - scaledRect.y;
//     else roi_h = scaledRect.height;

//     return Rect(roi_x, roi_y, roi_w, roi_h);

// }

// Rect OpenCVAPI::calculateROI(Size imgSize, Rect srcRect, double scaleRatio, int variableXShift, int variableYShift) {
//     Rect scaledRect = scaleRect(srcRect, scaleRatio);

//     int roi_x=0, roi_y=0, roi_w=0, roi_h=0;

//     //x
//     if(scaledRect.x < 0) roi_x=0;
//     else roi_x = scaledRect.x + variableXShift;

//     //width
//     if( (scaledRect.x+scaledRect.width) > imgSize.width ) roi_w = imgSize.width - scaledRect.x;
//     else roi_w = scaledRect.width + variableXShift;
                
//     //y
//     if(scaledRect.y<0) roi_y=0;
//     else roi_y = scaledRect.y + variableYShift;

//     //height
//     if( (scaledRect.y+scaledRect.height) > imgSize.height ) roi_h = imgSize.height - scaledRect.y;
//     else roi_h = scaledRect.height + variableYShift;

//     return Rect(roi_x, roi_y, roi_w, roi_h);
// }

// Rect OpenCVAPI::scaleRect(Rect srcRect, double scaleRatio) {

//     int x = (int)srcRect.x-(srcRect.width/2.0)*(scaleRatio-1.0);
//     int y = (int)srcRect.y-(srcRect.height/2.0)*(scaleRatio-1.0);
//     int w = srcRect.width*scaleRatio;
//     int h = srcRect.height*scaleRatio;

//     return Rect(x, y, w, h);

// }