#ifndef EXTRACTOR_H
#define EXTRACTOR_H

#include "../TypeDef.h"
#include "../Param/edge.h"
#include "../Param/matSet.h"
#include "../Param/region.h"
#include "../edgeFactory.h"
#include "../Service/edgeService.h"
#include "../Service/extractService.h"
#include "../Service/contourService.h"
#include "../Manager/extractionManager.h"
#include "../Manager/edgeManager.h"
#include "../Manager/regionManager.h"
#include "../SDK/opencv/opencvApi.h"
#include "../Param/channelSet.h"
#include "../Param/contours.h"
#include "../Extraction/State/contourState.h"
#include "../Extraction/State/contourExisted.h"
#include "../Extraction/State/contourNonEXisted.h"
#include "../Extraction/State/ContourCount/contourCountState.h"
#include "../Extraction/State/ContourCount/multiContour.h"
#include "../Extraction/State/ContourCount/oneContour.h"


class Extractor {

/*method*/
public:
    static Extractor& getInstance();
    void extract(const MatSet& srcSet);
    
private:
    Extractor();
    Extractor(const Extractor&);

/*property*/
private:
	ExtractService  _extractService;
    EdgeService _edgeService;
    ContourService _contourService;
	FeatureReference& _featureReference    = FeatureReference::getInstance();
    EdgeFactory& _edgeFactory              = EdgeFactory::getInstance();
    ExtractionManager& _extractionManager  = ExtractionManager::getInstance();
    RegionManager& _regionManager          = RegionManager::getInstance();
    EdgeManager& _edgeManager              = EdgeManager::getInstance();
    ContourState& _contourExisted          = ContourExisted::getInstance();
	ContourState& _contourNonExisted       = ContourNonExisted::getInstance();
    ContourCountState& _oneContour         = OneContour::getInstance();
    ContourCountState& _multiContour       = MultiContour::getInstance();
   

};

#endif // EXTRACTOR_H
