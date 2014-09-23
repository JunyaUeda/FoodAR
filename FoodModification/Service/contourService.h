#ifndef CONTOURSERVICE_H
#define CONTOURSERVICE_H
#include "../Utils/opencvBase.h"

class ContourService : public OpenCVBase
{
public:
    ContourService();
    int getMaxAreaContourIndex(vector<vector<Point>> contours);
    vector<vector<Point>> getTargetContours(Mat srcBinaryImg);
private:
	
};

#endif // CONTOURSERVICE_H
