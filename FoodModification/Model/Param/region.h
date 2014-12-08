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

    RotatedRect rotatedRect() const {
        return _rotatedRect;
    }

    Rect roi() const {
        return _roi;
    }

    Rect expectedRoi() const {
        return _expectedRoi;
    }
    

    // void calcContours() {
    //     Mat copyImg = _maskImg.clone();
    //     findContours(copyImg, _contours, CV_RETR_LIST, CV_CHAIN_APPROX_NONE);
    // }

    void setContour(vector<Point> contour) {
        _contour = contour;
    }

    void calcRotatedRect() {
        if(!_contour.size()) {
            return;
        }  
        _rotatedRect= minAreaRect(_contour);
    }

    void calcRoi() { 
        if(!_contour.size()) {
            return;
        }      
        Rect rect = boundingRect(_contour);
        double SCALE_RATIO = 2.0;
        _roi = OpenCVAPI::calculateROI(_maskImg.size(), rect, SCALE_RATIO);
    }

    /**
    * 前フレームにおける回転Rectの中心と今回の中心の移動量を加味して今回のROIを作成する
    * @note このメソッドを実行する前にcalcRotatedRect()を実行する必要がある
    */
    void calcExpectedRoiConsideringMove(RotatedRect& _previousRotatedRect) {
        if(!_contour.size()) {
            return;
        }      
        int shiftX = 0;
        int shiftY = 0;
        if(_previousRotatedRect.center.x > 0 && _previousRotatedRect.center.x < _maskImg.size().width) {
            shiftX = _rotatedRect.center.x - _previousRotatedRect.center.x;
            shiftY = _rotatedRect.center.y - _previousRotatedRect.center.y;
        }
        
        double SCALE_RATIO = 2.0;
        Rect rect = boundingRect(_contour);
        _expectedRoi = OpenCVAPI::calculateROI(_maskImg.size(), rect, SCALE_RATIO, shiftX, shiftY);
    }

    Size size() const {
        return _maskImg.size();
    }
    
private:
    
/*property*/
private:
	Mat _maskImg;
    vector<Point> _contour;
    RotatedRect _rotatedRect;
    Rect _roi;
    Rect _expectedRoi;
    vector<Point> _points;
    
  
};

#endif // REGION_H
