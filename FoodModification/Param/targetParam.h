#ifndef TARGETPARAM_H
#define TARGETPARAM_H
#include "../Utils/opencvBase.h"

class TargetParam : public OpenCVBase
{

public:
    std::vector<std::vector<cv::Point> >* contours;
    std::vector<cv::Point>* maxSizeContour;
    cv::Mat dstEdgeImg;
public:
    TargetParam();
    std::vector<std::vector<cv::Point> > getContours();
    void setContours(std::vector<std::vector<cv::Point> >* contours);
    std::vector<cv::Point> getMaxSizeContour();
    void setMaxSizeContour(std::vector<cv::Point>* maxSizeContour);
    cv::Mat getDstEdgeImg() const;
    void setDstEdgeImg(const cv::Mat &value);
};

#endif // TARGETPARAM_H
