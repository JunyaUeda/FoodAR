#include "contourService.h"

#define LINK_EIGHT 8
#define LINK_FOUR 4
#define LINK_CVAA CV_AA

ContourService::ContourService()
{
}

void ContourService::extractByContour(cv::Mat srcBinaryImg, cv::Mat dstImg) {
    
    std::vector<std::vector<cv::Point>> contours;
    cv::findContours(srcBinaryImg, contours, CV_RETR_LIST, CV_CHAIN_APPROX_NONE);	//元のimageはこの関数によって書き換えられる
    
    cv::Scalar color;
    color = cv::Scalar(255, 255, 255);
    int lineType = LINK_EIGHT;

    cv::drawContours(dstImg, contours, getMaxAreaContourIndex(contours), color, CV_FILLED, lineType);
    // for(size_t idx=0; idx<contours.size(); idx++) {
    //     cv::drawContours(dstImg, contours, idx, color, lineType, );
    // }
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