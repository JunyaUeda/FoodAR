#ifndef EXTRACTSERVICE_H
#define EXTRACTSERVICE_H

#include "../Param/region.h"
#include "../Param/matSet.h"
#include "../featureReference.h"
#include "../SDK/opencv/opencvApi.h"
#include "../condition.h"

class ExtractService {

/*property*/
private:
	Condition& _condition 				= Condition::getInstance();
	 FeatureReference& _featureReference = FeatureReference::getInstance();
	
/*method*/
public:
    ExtractService();
    Region* extractRegionByColor( MatSet* matSet);
};

#endif // EXTRACTSERVICE_H
