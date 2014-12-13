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
#include "../SDK/opencv/opencvApi.h"
#include "../Param/channelSet.h"

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
        int indexForMaxArea=-1;
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

    vector<int> calcIndexiesOfTop3Area(vPs& contours) {
       
        size_t max=0;
        size_t second =0;
        size_t third = 0;
        vector<int> indexForTop3 = {-1, -1, -1};
    
        if(contours.size() > 0) {
            for(int i=0; i<contours.size(); ++i) {
                size_t count = contours[i].size();
                //if(count < 300 || count > 1000) continue;

                if(count > max) {
                    indexForTop3[2] = indexForTop3[1];
                    indexForTop3[1] = indexForTop3[0];
                    indexForTop3[0] = i;
                    third = second;
                    second = max;
                    max = count;
                } else if(count > second) {
                    indexForTop3[2] = indexForTop3[1];
                    indexForTop3[1] = i;
                    third = second;
                    second = count;
                } else if(count > third) {
                    indexForTop3[2] = i;
                    third = count;
                }
            }
        }
        
        return indexForTop3;
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

    void updateBinarizationThreshold(int value ,int index) {
        _binarizationThreshold[index] = value;
    }

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

    void acquireAllChannels() {

    }

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
	int _binarizationThreshold[9];
   

};

#endif // EXTRACTOR_H
