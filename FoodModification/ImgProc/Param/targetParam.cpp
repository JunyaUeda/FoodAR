#include "targetParam.h"

TargetParam::TargetParam()
{
}

std::vector<std::vector<cv::Point>> TargetParam::getContours() {
	return this->contours;
}

void TargetParam::setContours(std::vector<std::vector<cv::Point>> contours) {
	this->contours = contours;
}

std::vector<cv::Point> TargetParam::getMaxSizeContour() {
	return this->maxSizeContour;
}

void TargetParam::setMaxSizeContour(std::vector<cv::Point> maxSizeContour) {
	this->maxSizeContour = maxSizeContour;
}