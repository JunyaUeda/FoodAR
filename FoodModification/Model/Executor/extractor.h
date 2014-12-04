#ifndef EXTRACTOR_H
#define EXTRACTOR_H


#include "../Param/edge.h"
#include "../Param/matSet.h"
#include "../Param/region.h"
#include "../edgeFactory.h"
#include "../Service/edgeService.h"
#include "../Service/extractService.h"
#include "../Service/contourService.h"


class Extractor {

/*method*/
public:
    static Extractor& getInstance();
    void extract(MatSet& srcSet, Region& result);

private:
    Extractor();
    Extractor(const Extractor&);

/*property*/
private:
	ExtractService  _extractService;
    EdgeService _edgeService;
    ContourService _contourService;
	FeatureReference& _featureReference = FeatureReference::getInstance();
    EdgeFactory& _edgeFactory = EdgeFactory::getInstance();

};

#endif // EXTRACTOR_H
