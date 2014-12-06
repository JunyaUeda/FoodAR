#ifndef CONTOURSERVICE_H
#define CONTOURSERVICE_H

#include "../SDK/opencv/opencvApi.h"
#include "../TypeDef.h"

#define LINK_EIGHT 8
#define LINK_FOUR 4
#define LINK_CVAA CV_AA

class ContourService {

/*method*/
public:
	ContourService();
    vector<Point> acquireMaxAreaContour(Mat& maskImg) {
        vPs contours;
        Mat mat = maskImg.clone();
        findContours(mat, contours, CV_RETR_LIST, CV_CHAIN_APPROX_NONE);
        int indexOfMaxArea = calcIndexOfMaxArea(contours);

        return contours[indexOfMaxArea];
    }

    int calcIndexOfMaxArea(vPs& contours) {
        size_t max=0;
        int indexForMaxArea=0;
        for(int i=0; i<contours.size(); ++i) {
            size_t count = contours[i].size();
            if(count < 300 || count > 1000) continue;

            if(count > max) {
                indexForMaxArea = i;
                max = count;
            }
        }

        return indexForMaxArea;
    }

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
/**
*すべての輪郭を塗りつぶし、輪郭以外の部分を黒にする.
*@note 
*/ 
    void fillContours(Mat& filledImg, vPs& contours, int lineType, int minSize) {
        if(!contours.empty()) {
            return;
        }

        for(int i=0; i<contours.size(); ++i) {

            size_t count = contours[i].size();
            if(count < minSize) {
                drawContours(filledImg, contours, i, Scalar(0, 0, 0), CV_FILLED, lineType);
            } else {
                drawContours(filledImg, contours, i, Scalar(255, 255, 255), CV_FILLED, lineType);
            }
            
        }
    }

    void fillContours(Mat& filledImg, int minSize) {
        vPs contours;
        Mat tmp = filledImg.clone();
        findContours(tmp, contours, CV_RETR_LIST, CV_CHAIN_APPROX_NONE);
        fillContours(filledImg, contours, LINK_EIGHT, minSize);
    }

    void fillSpecifiedContour(Mat filledImg, vPs& contours, int lineType, int minSize, int specifiedIndex);
    vPs getTargetContours(Mat srcBinaryImg);
    vPs extractContoursWithPoints(Mat srcImg, vP& points, int minSize);
    vPs extractContoursWithPoints(vPs& srcContours, vP& points, int minSize );
    void contourAreasAndCenters(vPs& contours, vector<double>& areas, vP& mCenters);
    void calcurateCenter(vPs& contours, vP &mCenters);
};

#endif // CONTOURSERVICE_H
