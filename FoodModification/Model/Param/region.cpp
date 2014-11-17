#include "region.h"
#include <qDebug>
Region::Region() {
}

Region::Region(Size size) {
	_maskImg = Mat::zeros(size, CV_8UC1);
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

void Region::calcContours() {
	Mat copyImg = _maskImg.clone();
	findContours(copyImg, _contours, CV_RETR_LIST, CV_CHAIN_APPROX_NONE);
}