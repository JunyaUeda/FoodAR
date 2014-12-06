#ifndef REGION_H
#define REGION_H

#include "../TypeDef.h"
#include "../SDK/opencv/opencvApi.h"

class Region {

/*method*/
public:
    Region();
    Region(Size& size) {
        _maskImg = Mat::zeros(size, CV_8UC1);
    }
    Region(Mat& img) {
        _maskImg = img;
    }

    Mat maskImg() const {
        return _maskImg;
    }
    void setMaskImg(Mat &maskImg) {
        _maskImg = maskImg;
    }

    vector<Point> contour() const {
        return _contour;
    }

    Rect roi() const {
        return _roi;
    }

    RotatedRect rotatedRect() const {
        return _rotatedRect;
    }

    // void calcContours() {
    //     Mat copyImg = _maskImg.clone();
    //     findContours(copyImg, _contours, CV_RETR_LIST, CV_CHAIN_APPROX_NONE);
    // }

    void setContour(vector<Point> contour) {
        _contour = contour;
    }

    void calcRoi() {       
        Rect rect = boundingRect(_contour);
        double SCALE_RATIO = 1.2;
        _roi = OpenCVAPI::calculateROI(_maskImg.size(), rect, SCALE_RATIO);
    }

    void calcRotatedRect() {
        _rotatedRect= minAreaRect(_contour);
    }

    Size size() const {
        return _maskImg.size();
    }
    
private:
    
/*property*/
private:
	Mat _maskImg;
    vector<Point> _contour;
    Rect _roi;
    vector<Point> _points;
    RotatedRect _rotatedRect;
  
};

#endif // REGION_H
