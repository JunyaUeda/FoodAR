#ifndef CONTOURSERVICE_H
#define CONTOURSERVICE_H

#include "../SDK/opencv/opencvApi.h"
#include "../TypeDef.h"

class ContourService {

/*method*/
public:
	ContourService();
    
    int getMaxAreaContourIndex(vPs& contours) {
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
