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

        int xBegin = scaledRect.x;
        int xEnd = scaledRect.x + scaledRect.width;
        int yBegin = scaledRect.y;
        int yEnd = scaledRect.y + scaledRect.height;


        if(xBegin <= 0) xBegin=0;
        // else if(xBegin >= imgSize.width) xBegin = imgSize.width-1;

        if( xEnd >= imgSize.width ) xEnd = imgSize.width;
        
                    
        if(yBegin <=  0) yBegin=0;
        

        if( yEnd >= imgSize.height ) yEnd = imgSize.height;
        

        return Rect(xBegin, yBegin, xEnd-xBegin, yEnd-yBegin);
    }

    static Rect calculateROI(Size imgSize, Rect srcRect, double scaleRatio, int variableShiftX, int variableShiftY) {
        Rect scaledRect = scaleRect(srcRect, scaleRatio);
        int xBegin = scaledRect.x;
        int xEnd = scaledRect.x + scaledRect.width;
        int yBegin = scaledRect.y;
        int yEnd = scaledRect.y + scaledRect.height;

        if(variableShiftX >= 0) {
            //x
            if(xBegin < 0) xBegin=0;
            else if(xBegin >= imgSize.width) xBegin = imgSize.width-1;

            int candidateXEnd = xEnd + (int)variableShiftX*1.5;
            if( candidateXEnd <= 0) xEnd = 0;
            else if( candidateXEnd >= imgSize.width ) xEnd = imgSize.width;
            else xEnd = candidateXEnd;

        } else {
            //x
            int candidateXBegin = xBegin + (int)variableShiftX*1.5;
            if(candidateXBegin < 0) xBegin=0;
            else if(candidateXBegin >= imgSize.width) xBegin = imgSize.width-1;
            else xBegin = candidateXBegin;

            if( xEnd <= 0) xEnd = 0;
            else if( xEnd >= imgSize.width ) xEnd = imgSize.width;

        }
       
        if(variableShiftY >= 0) {
            //y
            if(yBegin <= 0) yBegin=0;
            else if(yBegin >= imgSize.height) yBegin = imgSize.height-1;

            int candidateYEnd = yEnd + (int)variableShiftY*1.5;
            if( candidateYEnd <= 0) yEnd = 0;
            else if( candidateYEnd >= imgSize.height ) yEnd = imgSize.height;
            else yEnd = candidateYEnd;
        } else {
            //y
            int candidateYBegin = yBegin + (int)variableShiftY*1.5;
            if(candidateYBegin <= 0) yBegin=0;
            else if(candidateYBegin >= imgSize.height) yBegin = imgSize.height-1;
            else yBegin = candidateYBegin;

            if( yEnd <= 0) yEnd = 0;
            else if( yEnd >= imgSize.height ) yEnd = imgSize.height;
        }  
          
        return Rect(xBegin, yBegin, xEnd-xBegin, yEnd-yBegin);
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

private:


};

#endif // OPENCVAPI_H
