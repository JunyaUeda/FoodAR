#ifndef EXTRACTOR_H
#define EXTRACTOR_H


#include "../Param/edge.h"
#include "../Param/matSet.h"
#include "../Param/region.h"
#include "../edgeFactory.h"
#include "../Service/edgeService.h"
#include "../Service/extractService.h"
#include "../Service/contourService.h"
#include "../Manager/extractionManager.h"
// #include "../../Utils/opencvUtils.h"
#include "../SDK/opencv/opencvApi.h"

class Extractor {

/*method*/
public:
    static Extractor& getInstance();
    void extract(MatSet& srcSet, Region& result);
    void extractCoffee(MatSet& srcSet, Region& result);
    void setPreviousRegion(Region& region);
    void setScoreMatZeroAndSize(Size size);

    int calcIndexOfMaxArea(vPs& contours) {
        if(!contours.size()) {
            return -1;
        }
        size_t max=0;
        int indexForMaxArea=0;
        for(int i=0; i<contours.size(); ++i) {
            size_t count = contours[i].size();
            //if(count < 300 || count > 1000) continue;

            if(count > max) {
                indexForMaxArea = i;
                max = count;
            }
        }

        return indexForMaxArea;
    }

    void revMergeEdges(vector<Mat>& channelEdgeImgs, Rect& roi, Mat& dstEdgeImg) {

        if(!channelEdgeImgs.size()) {
            return;  
        }

        for(int y=roi.y; y<(roi.y+roi.height); y++) {
            for(int x=roi.x; x<(roi.x+roi.width); x++) {
                for(Mat mat : channelEdgeImgs) {
                    if(L(mat,x,y) == 255) {
                        L(dstEdgeImg, x, y) = 0;
                        break;
                    } 
                    L(dstEdgeImg, x, y) = 255;
                }
            }
		}
    }

    void revMergeEdges(vector<Mat>& channelEdgeImgs, Rect& roi, vector<Mat*> edgeImgs) {

        if(!channelEdgeImgs.size()) {
            return;  
        }

        for(int y=roi.y; y<(roi.y+roi.height); y++) {
            for(int x=roi.x; x<(roi.x+roi.width); x++) {
                for(Mat mat : channelEdgeImgs) {
                    if(L(mat,x,y) == 255) {
                        L((*edgeImgs[0]), x, y) = 0;
                        L((*edgeImgs[1]), x, y) = 255;
                        break;
                    } 
                    L((*edgeImgs[0]), x, y) = 255;
                    L((*edgeImgs[1]), x, y) = 0;
                }
            }
        }
    }

    void updateGreenBinarizationThreshold(int value) {
        _greenBinarizationThreshold = value;
    }   
    void updateYBinarizationThreshold(int value) {
        _yBinarizationThreshold = value;
    }
    void updateCrBinarizationThreshold(int value) {
        _crBinarizationThreshold = value;
    }
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
    ExtractionManager& _extractionManager = ExtractionManager::getInstance();
    Region _previousRegion;
    Mat _scoreMat;
    int _indexOfMaxArea=-1;
    int _greenBinarizationThreshold = 19;
    int _yBinarizationThreshold = 60;
    int _crBinarizationThreshold = 30;

    

};

#endif // EXTRACTOR_H
