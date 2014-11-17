#ifndef EXTRACTSERVICE_H
#define EXTRACTSERVICE_H

#include "../Param/region.h"
#include "../Param/matSet.h"
#include "../featureReference.h"
#include "../SDK/opencv/opencvApi.h"
#include "../condition.h"
#include "../../Service/contourService.h"

class ExtractService {

/*property*/
private:
	Condition& _condition 				= Condition::getInstance();
	FeatureReference& _featureReference = FeatureReference::getInstance();
    ContourService* _contourService;
	
/*method*/
public:
    ExtractService();
    void extractRegionByColor( MatSet* matSet, Region* result);
    // Region extractRegionByColor( MatSet* matSet);
    Region acquireMaxAreaRegion(Region* region);
};

#endif // EXTRACTSERVICE_H
