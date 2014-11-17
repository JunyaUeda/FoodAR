#ifndef EXTRACTOR_H
#define EXTRACTOR_H

#include "./Service/edgeService.h"
#include "./Param/matSet.h"
#include "./Param/region.h"
#include "./Param/edge.h"
#include "./Service/extractService.h"


class Extractor {

/*property*/
private:
	ExtractService  _extractService;
    EdgeService _edgeService;
	FeatureReference& _featureReference = FeatureReference::getInstance();
/*method*/
public:
	static Extractor& getInstance();
    void extract(MatSet* srcSet, QVector<Mat> edges);

private:
    Extractor();
    Extractor(const Extractor&);

};

#endif // EXTRACTOR_H
