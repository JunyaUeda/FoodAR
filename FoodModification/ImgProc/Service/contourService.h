#ifndef CONTOURSERVICE_H
#define CONTOURSERVICE_H
#include "../opencvBase.h"

class ContourService : public OpenCVBase
{
public:
    ContourService();
     void extractByContour(cv::Mat binaryImg, cv::Mat extractedImg);

private:

};

#endif // CONTOURSERVICE_H
