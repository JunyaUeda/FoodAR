#include "extractService.h"
#define LINK_EIGHT 8
#define LINK_FOUR 4
#define LINK_CVAA CV_AA

ExtractService::ExtractService() {
}

// Region ExtractService::extractRegionByColor(MatSet* srcSet) {

//     Region region(Size(srcSet->width(), srcSet->height()) );
//     for(int y=0; y<srcSet->height(); y++) {
//         for(int x=0; x<srcSet->width(); x++) {

//             if(_featureReference.isWithinThreshold(srcSet, Point(x,y))) {
//                 L(region.maskImg(),x,y) = 255;
//             }

//         }
//     }

//     region.calcContours();
  
//     return region;
// }

void ExtractService::extractRegionByColor(MatSet& srcSet, Region& result) {
    
    for(int y=0; y<srcSet.height(); y++) {
        for(int x=0; x<srcSet.width(); x++) {

            if(_featureReference.isWithinThreshold(srcSet, Point(x,y))) {
                L(result.maskImg(),x,y) = 255;
            }

        }
    }

    result.calcContours();
}


Region ExtractService::acquireMaxAreaRegion(Region& region) {
    
    Region result(region.size() );
    int maxAreaIndex = _contourService->getMaxAreaContourIndex(region.contours());
    int lineType = LINK_EIGHT;
    drawContours(result.maskImg(), region.contours(), maxAreaIndex, Scalar(255, 255, 255), CV_FILLED, lineType);
    result.calcContours();
    result.calcRois();

    return result;
} 