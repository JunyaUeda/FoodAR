#ifndef ONECONTOUR_H
#define ONECONTOUR_H

#include "../../../TypeDef.h"
#include "./contourCountState.h"
#include "../../../Manager/regionManager.h"
#include "../../../SDK/opencv/opencvApi.h"

#define LINK_EIGHT 8
#define LINK_FOUR 4
#define LINK_CVAA CV_AA

class OneContour : public ContourCountState {
/*method*/
public:
    static OneContour& getInstance();

    void drawAndCalcRegion(Contours& contours) {
        Mat maskImg = Mat::zeros(contours.matSize(), CV_8UC1);
        drawContours(maskImg, contours.all(), contours.indexSortedByArea()[0], Scalar(255, 255, 255), CV_FILLED, LINK_EIGHT);
        //imshow("OneContour", maskImg);
        _regionManager.currentRegion().setMaskImg(maskImg);
        if(contours.indexSortedByArea()[0]>=0) {
            _regionManager.currentRegion().setContour(contours.getLargestContour());
            _regionManager.currentRegion().calcRotatedRect();
            _regionManager.currentRegion().calcRoi();
            _regionManager.currentRegion().calcExpectedRoiConsideringMove(_regionManager.previousRegion());
        }
        
        _regionManager.setPreviousRegion(_regionManager.currentRegion());
    }

private:
	OneContour();
    OneContour(const OneContour&);

/*property*/
private:
    RegionManager& _regionManager = RegionManager::getInstance();
};

#endif // ONECONTOUR_H
