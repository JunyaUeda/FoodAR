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

    vPs contours() const {
        return _contours;
    }

    void calcContours() {
        Mat copyImg = _maskImg.clone();
        findContours(copyImg, _contours, CV_RETR_LIST, CV_CHAIN_APPROX_NONE);
    }

    void setContours(const vPs &contours) {
        _contours = contours;
    }

    QVector<Rect> rois() const {
        return _rois;
    }

    void calcRois() {
        _rois.clear();
        for(int i=0; i<_contours.size(); i++) {
            Rect rect = boundingRect(_contours[i]);
            double SCALE_RATIO = 1.3;
            _rois.push_back( OpenCVAPI::calculateROI(_maskImg.size(), rect, SCALE_RATIO) );
        }
    }

    vector<RotatedRect> rotatedRects() const {
        return _rotatedRects;
    }

    void calcRotatedRects() {
         _rotatedRects.clear();
        for(int i=0; i<_contours.size(); i++) {
            _rotatedRects.push_back( minAreaRect(_contours[i]) );
        }
    }

    Size size() const {
        return _maskImg.size();
    }
    // Region(Size& size);
    // Region(Mat& img);
    // Mat maskImg() const;
    // void setMaskImg(Mat &maskImg);
    // vPs contours() const;
    // void calcContours();
    // void setContours(const vPs &contours);

    // QVector<Rect> rois() const;

    // void calcRois();

    // vector<RotatedRect> rotatedRects() const;

    // void calcRotatedRects();
    
    // Size size() const;

/*property*/
private:
	Mat _maskImg;
    vPs _contours;
    QVector<Rect> _rois;
    vPs _regionPixels;
    vector<RotatedRect> _rotatedRects;
    vector<Point> _points;


};

#endif // REGION_H
