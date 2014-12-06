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

    QVector<Rect> rois() const {
        return _rois;
    }

    vector<RotatedRect> rotatedRects() const {
        return _rotatedRects;
    }

    void calcContours() {
        Mat copyImg = _maskImg.clone();
        findContours(copyImg, _contours, CV_RETR_LIST, CV_CHAIN_APPROX_NONE);
    }

    void setContours(const vPs &contours) {
        _contours = contours;
    }

    void calcRois() {
        _rois.clear();
        for(int i=0; i<_contours.size(); i++) {
            Rect rect = boundingRect(_contours[i]);
            double SCALE_RATIO = 1.2;
            _rois.push_back( OpenCVAPI::calculateROI(_maskImg.size(), rect, SCALE_RATIO) );
        }
    }

    void calcRotatedRects() {
         _rotatedRects.clear();
         //_rotatedRectVertices.clear();
        for(int i=0; i<_contours.size(); i++) {
            //RotatedRect rect = minAreaRect(_contours[i]);
            //_rotatedRects.push_back(rect);
            //calcRotatedRectVetcies(rect);
            //_rotatedRectVertices.push_back(calcRotatedRectVetcies(rect));
            _rotatedRects.push_back(minAreaRect(_contours[i]));
        }
    }



    Size size() const {
        return _maskImg.size();
    }
    
     // void addPoint(Point point) {
    //     _points.push_back(point);
    // }

    // vector<Point> points() {
    //     return _points;
    // }

private:
    // vector<Point2f> calcRotatedRectVetcies(RotatedRect& rect) {
    //     Point2f vertices[4];
    //     rect.points(vertices);
    //     vector<Point2f> result;
    //     for(int i=0; i<4; i++) {
    //         result.push_back(vertices[i]);
    //     }
    //     return result;
    // }
/*property*/
private:
	Mat _maskImg;
    vPs _contours;
    QVector<Rect> _rois;
    vPs _regionPixels;
    vector<RotatedRect> _rotatedRects;
    vector<Point> _points;
   // vector<vector<Point2f> > _rotatedRectVertices;

};

#endif // REGION_H
