#include "region.h"
#include <qDebug>
Region::Region() {
}

Region::Region(Size size) {
	_maskImg = Mat::zeros(size, CV_8UC1);
}

Region::Region(Mat img) {
    _maskImg = img;
}

Mat Region::maskImg() const {
    return _maskImg;
}

void Region::setMaskImg(const Mat &maskImg) {
    _maskImg = maskImg;
}

vPs Region::contours() const {
    return _contours;
}

void Region::setContours(const vPs &contours) {
    _contours = contours;
}

QVector<Rect> Region::rois() const {
    return _rois;
}

void Region::calcContours() {
	Mat copyImg = _maskImg.clone();
	findContours(copyImg, _contours, CV_RETR_LIST, CV_CHAIN_APPROX_NONE);
}

void Region::calcRois() {
    _rois.clear();
    for(int i=0; i<_contours.size(); i++) {
        Rect rect = boundingRect(_contours[i]);
        double SCALE_RATIO = 1.3;
        _rois.push_back( OpenCVAPI::calculateROI(_maskImg.size(), rect, SCALE_RATIO) );
    }
}

Size Region::size() const {
    return _maskImg.size();
}