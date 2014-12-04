#include "extractService.h"

ExtractService::ExtractService() {
}

// void ExtractService::extractRegionByColor(MatSet& srcSet, Region& result) {
    
//     for(int y=0; y<srcSet.height(); y++) {
//         for(int x=0; x<srcSet.width(); x++) {

//             if(_featureReference.isWithinThreshold(srcSet, Point(x,y))) {
//                 L(result.maskImg(),x,y) = 255;
//             }

//         }
//     }

//     result.calcContours();
// }


// void ExtractService::acquireMaxAreaRegion(Region& region Region& result) {
    
//     int maxAreaIndex = _contourService->getMaxAreaContourIndex(region.contours());
//     int lineType = LINK_EIGHT;
//     drawContours(result.maskImg(), region.contours(), maxAreaIndex, Scalar(255, 255, 255), CV_FILLED, lineType);
//     result.calcContours();
//     result.calcRois();
// } 