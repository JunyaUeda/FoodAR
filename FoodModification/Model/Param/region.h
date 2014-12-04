#ifndef REGION_H
#define REGION_H

#include "../TypeDef.h"
#include "../SDK/opencv/opencvApi.h"

class Region {

/*method*/
public:
    Region();
    Region(Size& size);
    Region(Mat& img);
    Mat maskImg() const;
    void setMaskImg(Mat &maskImg);
    vPs contours() const;
    void calcContours();
    void setContours(const vPs &contours);

    QVector<Rect> rois() const;

    void calcRois();

    vector<RotatedRect> rotatedRects() const;

    void calcRotatedRects();
    
    Size size() const;

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
