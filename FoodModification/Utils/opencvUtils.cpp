#include "opencvUtils.h"

OpenCVUtils::OpenCVUtils() {
}

void OpenCVUtils::setPixelValue(cv::Mat img, int x, int y, int value) {
    B(img,x,y) = value;
    G(img,x,y) = value;
    R(img,x,y) = value;
}

Rect OpenCVUtils::calculateROI(Size imgSize, Rect srcRect, double scaleRatio) {

    Rect scaledRect = scaleRect(srcRect, scaleRatio);

    int roi_x=0, roi_y=0, roi_w=0, roi_h=0;

    if(scaledRect.x < 0) roi_x=0;
    else roi_x = scaledRect.x;

    if( (scaledRect.x+scaledRect.width) > imgSize.width ) roi_w = imgSize.width - scaledRect.x;
    else roi_w = scaledRect.width;
                
    if(scaledRect.y<0) roi_y=0;
    else roi_y = scaledRect.y;

    if( (scaledRect.y+scaledRect.height) > imgSize.height ) roi_h = imgSize.height - scaledRect.y;
    else roi_h = scaledRect.height;

    return Rect(roi_x, roi_y, roi_w, roi_h);

}

Rect OpenCVUtils::scaleRect(Rect srcRect, double scaleRatio) {

    int x = (int)srcRect.x-(srcRect.width/2.0)*(scaleRatio-1.0);
    int y = (int)srcRect.y-(srcRect.height/2.0)*(scaleRatio-1.0);
    int w = srcRect.width*scaleRatio;
    int h = srcRect.height*scaleRatio;

    return Rect(x, y, w, h);

}