#ifndef EXTRACTSERVICE_H
#define EXTRACTSERVICE_H

#include "../condition.h"
#include "../Param/region.h"
#include "../Param/matSet.h"
#include "../featureReference.h"
#include "../SDK/opencv/opencvApi.h"
#include "contourService.h"

#define LINK_EIGHT 8
#define LINK_FOUR 4
#define LINK_CVAA CV_AA

class ExtractService {

/*method*/
public:
    ExtractService();

    void extractRegionByColor(MatSet& srcSet, Region& result) {
        for(int y=0; y<srcSet.height(); y++) {
            for(int x=0; x<srcSet.width(); x++) {

                if(_featureReference.isWithinThreshold(srcSet, Point(x,y))) {
                    L(result.maskImg(),x,y) = 255;
                }

            }
        }
        result.calcContours();
    }
    void acquireMaxAreaRegion(Region& region, Region& result) {
        int maxAreaIndex = _contourService->getMaxAreaContourIndex(region.contours());
        int lineType = LINK_EIGHT;
        drawContours(result.maskImg(), region.contours(), maxAreaIndex, Scalar(255, 255, 255), CV_FILLED, lineType);
        result.calcContours();
        result.calcRois();
    }

/*property*/
private:
	Condition& _condition 				= Condition::getInstance();
	FeatureReference& _featureReference = FeatureReference::getInstance();
    ContourService* _contourService;
	

};

#endif // EXTRACTSERVICE_H
