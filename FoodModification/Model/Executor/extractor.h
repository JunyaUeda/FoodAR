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

    bool isInROI(Point p, Point2f roi[]) {
        double pro[4];
        for(int i=0; i<4; ++i) {
            pro[i] = computeProduct(p, roi[i], roi[(i+1)%4]);
        }
        if(pro[0]*pro[2]<0 && pro[1]*pro[3]<0) {
            return true;
        }
        return false;
    }

    double computeProduct(Point p, Point2f a, Point2f b) {
        double k = (a.y-b.y)/(a.x-b.x);
        double j = a.y -k*a.x;
        return k*p.x -p.y + j;
    }


/*property*/
private:
	ExtractService  _extractService;
    EdgeService _edgeService;
    ContourService _contourService;
	FeatureReference& _featureReference = FeatureReference::getInstance();
    EdgeFactory& _edgeFactory = EdgeFactory::getInstance();
    ExtractionManager& _extractionManager = ExtractionManager::getInstance();
    RegionManager& _regionManager = RegionManager::getInstance();
    EdgeManager& _edgeManager = EdgeManager::getInstance();
    ContourState& _contourExisted = ContourExisted::getInstance();
	ContourState& _contourNonExisted = ContourNonExisted::getInstance();
    ContourCountState& _oneContour = OneContour::getInstance();
    ContourCountState& _multiContour = MultiContour::getInstance();
   

};

#endif // EXTRACTOR_H
