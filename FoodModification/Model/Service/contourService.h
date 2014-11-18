#ifndef CONTOURSERVICE_H
#define CONTOURSERVICE_H

#include "../SDK/opencv/opencvApi.h"
#include "../TypeDef.h"

class ContourService {

/*method*/
public:
	ContourService();
    int getMaxAreaContourIndex(vPs contours);
    vPs getTargetContours(Mat srcBinaryImg);
    void fillContours(Mat& filledImg, vPs& contours, int lineType, int minSize);
    void fillContours(Mat& filledImg, int minSize);
    void fillSpecifiedContour(Mat filledImg, vPs& contours, int lineType, int minSize, int specifiedIndex);
    vPs extractContoursWithPoints(Mat srcImg, vP& points, int minSize);
    vPs extractContoursWithPoints(vPs& srcContours, vP& points, int minSize );
    void contourAreasAndCenters(vPs& contours, vector<double>& areas, vP& mCenters);
    void calcurateCenter(vPs& contours, vP &mCenters);
};

#endif // CONTOURSERVICE_H
