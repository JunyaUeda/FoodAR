#include "contourService.h"

ContourService::ContourService()
{
}

void ContourService::extractByContour(cv::Mat binaryImg, cv::Mat extractedImg) {
    
    std::vector<std::vector<cv::Point>> contours;
    cv::findContours(binaryImg, contours, CV_RETR_LIST, CV_CHAIN_APPROX_NONE);
    
    cv::Scalar color;
    color = cv::Scalar(255, 255, 255);
    for(size_t idx=0; idx<contours.size(); idx++) {
        cv::drawContours(extractedImg, contours, idx, color);
    }
}
