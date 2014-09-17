#ifndef CONTOURSERVICE_H
#define CONTOURSERVICE_H
#include "../Utils/opencvBase.h"

class ContourService : public OpenCVBase
{
public:
    ContourService();
    int getMaxAreaContourIndex(std::vector<std::vector<cv::Point>> contours);
    std::vector<std::vector<cv::Point>> getTargetContours(cv::Mat srcBinaryImg);
private:
	
};

#endif // CONTOURSERVICE_H
