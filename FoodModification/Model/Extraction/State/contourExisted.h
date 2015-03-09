#ifndef CONTOUREXISTED_H
#define CONTOUREXISTED_H

#include "./contourState.h"
#include "../../SDK/opencv/opencvApi.h"
#include "../../Manager/regionManager.h"
#include "../../Manager/thresholdManager.h"
#include "../../Manager/edgeManager.h"

class ContourExisted : public ContourState {

/*method*/
public:
	static ContourExisted& getInstance();
	
    void createMaskByColor(Mat& maskImg, ChannelSet& channelSet) {

        Rect previousRect = _regionManager.previousRegion().expectedRoi();
        int yBegin = previousRect.y;
        int yEnd = previousRect.y + previousRect.height;
        int xBegin = previousRect.x;
        int xEnd = previousRect.x + previousRect.width;

        for(int y=yBegin; y<yEnd; y++) {
            for(int x=xBegin; x<xEnd; x++) {
                // if(_featureReference.isWithinThreshold(srcSet, Point(x,y)) ) { 
                //         L(mat,x,y) = 255;     
                //     } 

				if(L(channelSet.sMat(),x,y)>=_thresholdManager.s() && L(channelSet.crMat(),x,y) >= _thresholdManager.cr() && L(channelSet.cbMat(), x, y)<=_thresholdManager.cb() && L(channelSet.bMat(),x,y) <=_thresholdManager.b() && L(channelSet.yMat(),x,y) <= _thresholdManager.y()) {
                    //if(L(_edgeManager.currentEdge().roiMergedMat(), x, y) != 0) {
                        L(maskImg,x,y) = 255;
                   // }
                    
                    
                 }// } else if(L(channelSet.sMat(),x,y) >=_thresholdManager.s() && L(channelSet.crMat(),x,y) >= _thresholdManager.cr() && L(channelSet.gMat(),x,y) <=_thresholdManager.g() && L(channelSet.yMat(),x,y) <= _thresholdManager.y() ) {
                //     L(maskImg,x,y) = 255;
                // }
                
                // if(L(channelSet.crMat(),x,y) <= _thresholdManager.cr() && L(channelSet.gMat(),x,y) <=_thresholdManager.g() && L(channelSet.yMat(),x,y) <= _thresholdManager.y()) {
    
                //     L(maskImg,x,y) = 255;
                    
                // }
            }
        }
    }

private:
    ContourExisted();
    ContourExisted(const ContourExisted&);
/*property*/
private:
    RegionManager& _regionManager = RegionManager::getInstance();
    ThresholdManager& _thresholdManager = ThresholdManager::getInstance();
    EdgeManager& _edgeManager              = EdgeManager::getInstance();

};
#endif // CONTOUREXISTED_H
