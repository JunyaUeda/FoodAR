#ifndef REGION_H
#define REGION_H

#include "../TypeDef.h"
#include "../SDK/opencv/opencvApi.h"
#include <QDebug>

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

    void setRotatedRect(RotatedRect &rotatedRect) {
        _rotatedRect = rotatedRect;
    }

    Rect roi() const {
        return _roi;
    }

    Rect expectedRoi() const {
        return _expectedRoi;
    }
    
    int velocityX() {
        return _velocityX;
    }

    int velocityY() {
        return _velocityY;
    }

    void updatePixelSum(int sum) {
        _pixelSum = sum;
    }

    int pixelSum() {
        return _pixelSum;
    }


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
        _roi = OpenCVAPI::calculateROI(_maskImg.size(), rect, _roiScaleRatio);
    }

    void calcRoiWithRotatedRect() {
        Rect rect = _rotatedRect.boundingRect();
        _roi = OpenCVAPI::calculateROI(_maskImg.size(), rect, _roiScaleRatio);
    }
    /**
    * 前フレームにおける回転Rectの中心と今回の中心の移動量を加味して今回のROIを作成する
    * @note このメソッドを実行する前にcalcRotatedRect()を実行する必要がある
    */
    void calcExpectedRoiConsideringMove(Region& previousRegion) {
        if(!_contour.size()) {
            return;
        }

        int shiftX = 0;
        int shiftY = 0;
        _accelerationX = 0;
        _accelerationY = 0;
        if(previousRegion.rotatedRect().center.x > 0 && previousRegion.rotatedRect().center.x < _maskImg.size().width) {
            _velocityX = _rotatedRect.center.x - previousRegion.rotatedRect().center.x;
            _velocityY = _rotatedRect.center.y - previousRegion.rotatedRect().center.y;
            _accelerationX = _velocityX - previousRegion.velocityX();
            _accelerationY = _velocityY - previousRegion.velocityY();

            shiftX = _velocityX + _accelerationX;
            shiftY = _velocityY + _accelerationY;
        }

        Rect rect = boundingRect(_contour);
        _expectedRoi = OpenCVAPI::calculateROI(_maskImg.size(), rect, _roiScaleRatio, shiftX, shiftY);
    }

    void calcExpectedRoiConsideringMoveWithRotatedRect(Region& previousRegion) {
        if(!_contour.size()) {
            return;
        }

        int shiftX = 0;
        int shiftY = 0;
        _accelerationX = 0;
        _accelerationY = 0;
        if(previousRegion.rotatedRect().center.x > 0 && previousRegion.rotatedRect().center.x < _maskImg.size().width) {
            _velocityX = _rotatedRect.center.x - previousRegion.rotatedRect().center.x;
            _velocityY = _rotatedRect.center.y - previousRegion.rotatedRect().center.y;
            _accelerationX = _velocityX - previousRegion.velocityX();
            _accelerationY = _velocityY - previousRegion.velocityY();

            shiftX = _velocityX + _accelerationX;
            shiftY = _velocityY + _accelerationY;
        }

        Rect rect = _rotatedRect.boundingRect();
        _expectedRoi = OpenCVAPI::calculateROI(_maskImg.size(), rect, _roiScaleRatio, shiftX, shiftY);
    }

    Size size() const {
        return _maskImg.size();
    }

    RotatedRect expectedRotatedRect() {
        return _expectedRotatedRect;
    }
    
    void calcExpectedRotatedRect() {
        _expectedRotatedRect = RotatedRect(_rotatedRect.center, Size((int)_rotatedRect.size.width*1.5, (int)_rotatedRect.size.height*1.5), _rotatedRect.angle);
    }

    bool isExisted() {
        if(_contour.empty()) {
            return false;
        }
        return true;
    }
private:
    
/*property*/
private:
	Mat _maskImg;
    vector<Point> _contour;
    vector<Point> _points;
    RotatedRect _rotatedRect;
    Rect _roi;
    /**次回フレームで使用*/
    Rect _expectedRoi;
    RotatedRect _expectedRotatedRect;
    

    int _velocityX = 0;
    int _velocityY = 0;
    int _accelerationX = 0;
    int _accelerationY = 0;
    int _pixelSum = 0;
    double _roiScaleRatio = 2.0;
  
};

#endif // REGION_H
