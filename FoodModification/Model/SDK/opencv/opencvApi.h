#ifndef OPENCVAPI_H
#define OPENCVAPI_H

#include "opencv2/opencv.hpp"


#define CV_VER CVAUX_STR(CV_MAJOR_VERSION) CVAUX_STR(CV_MINOR_VERSION) CVAUX_STR(CV_SUBMINOR_VERSION)

#ifdef _DEBUG
#define CV_EXT "d.lib"
#else
#define CV_EXT ".lib"
#endif

#pragma comment(lib, "opencv_calib3d" CV_VER CV_EXT)
#pragma comment(lib, "opencv_contrib" CV_VER CV_EXT)
#pragma comment(lib, "opencv_core" CV_VER CV_EXT)
#pragma comment(lib, "opencv_features2d" CV_VER CV_EXT)
#pragma comment(lib, "opencv_flann" CV_VER CV_EXT)
#pragma comment(lib, "opencv_gpu" CV_VER CV_EXT)
#pragma comment(lib, "opencv_highgui" CV_VER CV_EXT)
#pragma comment(lib, "opencv_imgproc" CV_VER CV_EXT)
#pragma comment(lib, "opencv_legacy" CV_VER CV_EXT)
#pragma comment(lib, "opencv_ml" CV_VER CV_EXT)
#pragma comment(lib, "opencv_nonfree" CV_VER CV_EXT)
#pragma comment(lib, "opencv_objdetect" CV_VER CV_EXT)
#pragma comment(lib, "opencv_ocl" CV_VER CV_EXT)
#pragma comment(lib, "opencv_photo" CV_VER CV_EXT)
#pragma comment(lib, "opencv_stitching" CV_VER CV_EXT)
#pragma comment(lib, "opencv_superres" CV_VER CV_EXT)
#pragma comment(lib, "opencv_ts" CV_VER CV_EXT)
#pragma comment(lib, "opencv_video" CV_VER CV_EXT)
#pragma comment(lib, "opencv_videostab" CV_VER CV_EXT)


#define B(IMG, X,Y) ((IMG).data[((IMG).step*(Y) + (IMG).channels()*(X)) + 0])
#define G(IMG, X,Y) ((IMG).data[((IMG).step*(Y) + (IMG).channels()*(X)) + 1])
#define R(IMG, X,Y) ((IMG).data[((IMG).step*(Y) + (IMG).channels()*(X)) + 2])
#define I(IMG, X,Y) ((IMG).data[((IMG).step*(Y) + (IMG).channels()*(X)) + 3])

#define H(IMG, X,Y) ((IMG).data[((IMG).step*(Y) + (IMG).channels()*(X)) + 0])
#define S(IMG, X,Y) ((IMG).data[((IMG).step*(Y) + (IMG).channels()*(X)) + 1])
#define V(IMG, X,Y) ((IMG).data[((IMG).step*(Y) + (IMG).channels()*(X)) + 2])

#define L(IMG, X,Y) ((IMG).data[(IMG).step*(Y) + (X)])

#define BLUE(IMG,Y) ((IMG).data[(IMG).step*(Y) + (IMG).channels() + 0])
#define GREEN(IMG,Y) ((IMG).data[(IMG).step*(Y) + (IMG).channels() + 1])
#define RED(IMG,Y) ((IMG).data[(IMG).step*(Y) + (IMG).channels() + 2])
#define X(IMG,Y) ((IMG).data[(IMG).step*(Y) + (IMG).channels() + 3])
#define Y(IMG,Y) ((IMG).data[(IMG).step*(Y) + (IMG).channels() + 4])

using namespace cv;
using namespace std;

class OpenCVAPI {    
public:
    OpenCVAPI();
    static Rect calculateROI(Size imgSize, Rect srcRect, double scaleRatio) {
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

    static Rect calculateROI(Size imgSize, Rect srcRect, double scaleRatio, int variableShiftX, int variableShiftY) {
        Rect scaledRect = scaleRect(srcRect, scaleRatio);

        int roi_x=0, roi_y=0, roi_w=0, roi_h=0;

        //x
        int candidateX = scaledRect.x + variableShiftX;
        if(candidateX < 0) roi_x=0;
        else if(candidateX > imgSize.width) roi_x = imgSize.width;
        else roi_x = candidateX;

        //width
        int candidateW = scaledRect.width + abs(variableShiftX);
        if( (roi_x + candidateW) < 0) roi_w = 0;
        else if( (roi_x + candidateW) > imgSize.width ) roi_w = imgSize.width - roi_x;
        else roi_w = candidateW;
                    
        //y
        int candidateY = scaledRect.y + variableShiftY;
        if(candidateY < 0) roi_y = 0;
        else if(candidateY > imgSize.height) roi_y=imgSize.height;
        else roi_y = candidateY;

        //height
        int candidateH = scaledRect.height + abs(variableShiftX); 
        if( (roi_y + candidateH) < 0) roi_h = 0;
        else if( (roi_y + candidateH) > imgSize.height ) roi_h = imgSize.height - roi_y;
        else roi_h = candidateH;

        return Rect(roi_x, roi_y, roi_w, roi_h);
    }

    static Rect scaleRect(Rect srcRect, double scaleRatio) {
        int x = (int)srcRect.x-(srcRect.width/2.0)*(scaleRatio-1.0);
        int y = (int)srcRect.y-(srcRect.height/2.0)*(scaleRatio-1.0);
        int w = srcRect.width*scaleRatio;
        int h = srcRect.height*scaleRatio;

        return Rect(x, y, w, h);
    }

    template<class Functor> void raster(Size size, Functor f) {
    	for(int y =0; y<size.height; y++) {
    		for(int x=0; x<size.width; x++) {
    			f(x,y);
    		}
    	}
	}
    

};

#endif // OPENCVAPI_H
