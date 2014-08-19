#include "contourService.h"

ContourService::ContourService()
{
}

int ContourService::getMaxAreaContourIndex(std::vector<std::vector<cv::Point>> contours) {
	
	size_t max=0;
	int indexForMaxArea=0;
	for(int i=0; i<contours.size(); ++i) {
		size_t count = contours[i].size();
		if(count < 150 || count > 1000) continue;

		if(count > max) {
			indexForMaxArea = i;
			max = count;
		}
	}

	return indexForMaxArea;
}

std::vector<std::vector<cv::Point>> ContourService::getTargetContours(cv::Mat srcBinaryImg) {
	std::vector<std::vector<cv::Point>> contours;
    cv::findContours(srcBinaryImg, contours, CV_RETR_LIST, CV_CHAIN_APPROX_NONE);
    return contours;
}