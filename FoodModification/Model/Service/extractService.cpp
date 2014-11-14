#include "extractService.h"

ExtractService::ExtractService() {
}


// class ExtractByColor {
// public:
// 	void operator()(int x, int y) {

// 	}

// 	void operator()(int x, int y, MatSet* srcSet, Region* region, FeatureReference featureReference) {

// 		ColorThreshold* threshold = featureReference.getColorThreshold( V(srcSet->hsv(),x,y) );
//         if(threshold->isWithinThreshold(H(srcSet->hsv(),x,y), S(srcSet->hsv(),x,y), V(srcSet->hsv(),x,y))) {
//         		L(region->maskImg(),x,y) = 255;
//         }
// 	}
// };

// Region* extractRegionByColor(const MatSet* srcSet, FeatureReference featureReference) {
// 	Size size(srcSet->width(), srcSet->height());
// 	Region region(size);
// 	ExtractByColor extractByColor;

// 	OpenCVApi::raster(size, extractByColor(src))
//     return &region;
// }

 Region* ExtractService::extractRegionByColor(MatSet* srcSet, FeatureReference* featureReference) {

	 Region region(Size(srcSet->width(), srcSet->height()) );

	for(int y=0; y<srcSet->height(); y++) {
        for(int x=0; x<srcSet->width(); x++) {

            ColorThreshold* threshold=featureReference->getColorThreshold( V(srcSet->hsv(),x,y) );
        	if(threshold->isWithinThreshold(H(srcSet->hsv(),x,y), S(srcSet->hsv(),x,y), V(srcSet->hsv(),x,y))) {
        		L(region.maskImg(),x,y) = 255;
        	}

        }
    }

     region.calcContours();
    
    return &region;
}

