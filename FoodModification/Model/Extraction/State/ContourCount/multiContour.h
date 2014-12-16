#ifndef MULTICONTOUR_H
#define MULTICONTOUR_H

#include "../../../TypeDef.h"
#include "./contourCountState.h"
#include "../../../Manager/regionManager.h"
#include "../../../SDK/opencv/opencvApi.h"

#define LINK_EIGHT 8
#define LINK_FOUR 4
#define LINK_CVAA CV_AA

class MultiContour : public ContourCountState {
/*method*/
public:
    static MultiContour& getInstance();
    void drawAndCalcRegion( Mat& maskImg, vector<int>& indexiesOfTop3Area, vPs contours) {

        Point2f vertices[4];
        _regionManager.previousRegion().rotatedRect().points(vertices);

        vector<Point> allPoints = contours[indexiesOfTop3Area[0]];

        if(indexiesOfTop3Area[2] >= 0) {
            drawContours(maskImg, contours, indexiesOfTop3Area[0], Scalar(255, 255, 255), CV_FILLED, LINK_EIGHT);
            drawContours(maskImg, contours, indexiesOfTop3Area[1], Scalar(255, 255, 255), CV_FILLED, LINK_EIGHT);
            drawContours(maskImg, contours, indexiesOfTop3Area[2], Scalar(255, 255, 255), CV_FILLED, LINK_EIGHT);
            
            for(int i=1; i<3; i++) {
                for(Point point :contours[indexiesOfTop3Area[i]]) {
                    if(OpenCVAPI::isInROI(point, vertices)) {
                        allPoints.push_back(point);
                    }
                    
                }
            }

        } else {
            drawContours(maskImg, contours, indexiesOfTop3Area[0], Scalar(255, 255, 255), CV_FILLED, LINK_EIGHT);
            drawContours(maskImg, contours, indexiesOfTop3Area[1], Scalar(255, 255, 255), CV_FILLED, LINK_EIGHT);
            
            for(int i=1; i<2; i++) {
                for(Point point :contours[indexiesOfTop3Area[i]]) {
                    if(OpenCVAPI::isInROI(point, vertices)) {
                        allPoints.push_back(point);
                    }
                }
            }
    
        }
    
        RotatedRect rect = minAreaRect(Mat(allPoints));
       
        _regionManager.currentRegion().setContour(contours[indexiesOfTop3Area[0]]);//TODO:本来は結合した輪郭を入れるか別にいれる必要がある
        _regionManager.currentRegion().setMaskImg(maskImg);
        _regionManager.currentRegion().setRotatedRect(rect);
        _regionManager.currentRegion().calcRoiWithRotatedRect();
        _regionManager.currentRegion().calcExpectedRoiConsideringMoveWithRotatedRect(_regionManager.previousRegion());

        _regionManager.setPreviousRegion(_regionManager.currentRegion());
    }

private:
	MultiContour();
    MultiContour(const MultiContour&);

/*property*/
private:
    RegionManager& _regionManager = RegionManager::getInstance();
};

#endif // MULTICONTOUR_H
