#include "targetParam.h"
#include <QDebug>
TargetParam::TargetParam()
{
}

std::vector<std::vector<cv::Point> > TargetParam::getContours() {
	return *contours;
}

void TargetParam::setContours(std::vector<std::vector<cv::Point> >* conturs) {
	//std::vector<std::vector<cv::Point>>* cont = contours;
	this->contours = conturs;
}

std::vector<cv::Point> TargetParam::getMaxSizeContour() {
	return *maxSizeContour;
}

void TargetParam::setMaxSizeContour(std::vector<cv::Point>* maxSizeContour) {
	this->maxSizeContour = maxSizeContour;
}
cv::Mat TargetParam::getDstEdgeImg() const
{
    return dstEdgeImg;
}

void TargetParam::setDstEdgeImg(const cv::Mat &value)
{
    dstEdgeImg = value;
}
