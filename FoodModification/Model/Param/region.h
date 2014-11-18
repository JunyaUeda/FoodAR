#ifndef REGION_H
#define REGION_H

#include "../TypeDef.h"
#include "../SDK/opencv/opencvApi.h"

class Region {

/*property*/
private:
	Mat _maskImg;
    vPs _contours;
    QVector<Rect> _rois;
    vPs _regionPixels;

/*method*/
public:
    Region();
    Region(Size size);
    Region(Mat img);
    Mat maskImg() const;
    void setMaskImg(const Mat &maskImg);
    vPs contours() const;
    void setContours(const vPs &contours);
    QVector<Rect> rois() const;
    void calcContours();
    void calcRois();
    Size size() const;
};

#endif // REGION_H
