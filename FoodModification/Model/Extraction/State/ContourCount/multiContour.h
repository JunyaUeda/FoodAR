#ifndef MULTICONTOUR_H
#define MULTICONTOUR_H

#include "../../../TypeDef.h"
#include "./contourCountState.h"
#include "../../../Manager/regionManager.h"
#include "../../../SDK/opencv/opencvApi.h"
#include "../../../Util/cvUtil.h"

#define LINK_EIGHT 8
#define LINK_FOUR 4
#define LINK_CVAA CV_AA

class MultiContour : public ContourCountState {
/*method*/
public:
    static MultiContour& getInstance();

    void drawAndCalcRegion(Contours& contours) {

        Mat maskImg = Mat::zeros(contours.matSize(), CV_8UC1);

        Point2f vertices[4];
        _regionManager.previousRegion().rotatedRect().points(vertices);

        vector<Point> allPoints = contours.getLargestContour();
   
        CVUtil::drawContours255(maskImg, contours.all(), contours.indexSortedByArea());
        for(int i=1; i<contours.numOfContour(); i++) {
            for(Point point :contours.all()[contours.indexSortedByArea()[i]]) {
                if(CVUtil::isInROI(point, vertices)) {
                    allPoints.push_back(point);
                }
                
            }
        }

      
        RotatedRect rect = minAreaRect(Mat(allPoints));
       
        _regionManager.currentRegion().setContour(contours.getLargestContour());//TODO:本来は結合した輪郭を入れるか別にいれる必要がある
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
