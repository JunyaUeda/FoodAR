#ifndef CONTOURSERVICE_H
#define CONTOURSERVICE_H
#include "../Utils/opencvBase.h"

class ContourService : public OpenCVBase {
public:
    ContourService();
    int getMaxAreaContourIndex(vector<vector<Point>> contours);
    vector<vector<Point>> getTargetContours(Mat srcBinaryImg);
    void fillContours(Mat filledImg, vector<vector<Point> >& contours, int lineType, int minSize);
    vector<vector<Point>> extractContoursWithPoints(Mat srcImg, vector<Point>& points, int minSize);
    vector<vector<Point>> extractContoursWithPoints(vector<vector<Point> >& srcContours, vector<Point>& points, int minSize );
    void contourAreasAndCenters(vector<vector<Point> >& contours, vector<double>& areas, vector<Point>& mCenters);
    void calcurateCenter(vector<vector<Point> >& contours, vector<Point> &mCenters);
private:
	
};

#endif // CONTOURSERVICE_H
