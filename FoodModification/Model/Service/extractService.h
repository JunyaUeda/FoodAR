#ifndef EXTRACTSERVICE_H
#define EXTRACTSERVICE_H

#include "../Param/region.h"
#include "../Param/matSet.h"
#include "../featureReference.h"
#include "../SDK/opencv/opencvApi.h"

class ExtractService {

/*property*/
private:
	
/*method*/
public:
    ExtractService();
    Region* extractRegionByColor( MatSet* matSet, FeatureReference* featureReference);
};

#endif // EXTRACTSERVICE_H
