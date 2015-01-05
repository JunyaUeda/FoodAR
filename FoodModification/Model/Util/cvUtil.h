#pragma once
#ifndef CVUTIL_H
#define CVUTIL_H

#include "../SDK/opencv/opencvApi.h"
#include "../TypeDef.h"

#define LINK_EIGHT 8
#define LINK_FOUR 4
#define LINK_CVAA CV_AA

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

class CVUtil {

/*method*/
public:
    static void drawContours255(Mat& img, const vPs& contours, vector<int> contourIdx) {
        for(int idx : contourIdx) {
            drawContours(img, contours, idx, Scalar(255, 255, 255), CV_FILLED, LINK_EIGHT);
        }
    }

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

    static void drawRotatedRect(RotatedRect& rect, Mat& result, Scalar color, int thickness) {
        Point2f vertices[4];
        rect.points(vertices);
        for (int i = 0; i < 4; i++) line(result, vertices[i], vertices[(i+1)%4], color, thickness, 8, 0);
    }

    static bool isInROI(Point p, Point2f roi[]) {
        double pro[4];
        for(int i=0; i<4; ++i) {
            pro[i] = computeProduct(p, roi[i], roi[(i+1)%4]);
        }
        if(pro[0]*pro[2]<0 && pro[1]*pro[3]<0) {
            return true;
        }
        return false;
    }

    static double computeProduct(Point p, Point2f a, Point2f b) {
        double k = (a.y-b.y)/(a.x-b.x);
        double j = a.y -k*a.x;
        return k*p.x -p.y + j;
    }
    
private:
	CVUtil();
};

#endif // CVUTIL_H
