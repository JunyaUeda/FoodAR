#ifndef EXTRACTOR_H
#define EXTRACTOR_H

#include "./Param/matSet.h"
#include "./Param/region.h"
#include "./Param/edge.h"
#include "./Service/extractService.h"

class Extractor {

/*property*/
private:
	ExtractService  _extractService;
	FeatureReference& _featureReference = FeatureReference::getInstance();
/*method*/
public:
	static Extractor& getInstance();
    void extract(MatSet* srcSet);

private:
    Extractor();
    Extractor(const Extractor&);

};

#endif // EXTRACTOR_H
