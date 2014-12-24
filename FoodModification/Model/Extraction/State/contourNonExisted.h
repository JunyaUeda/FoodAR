#ifndef CONTOURNONEXISTED_H
#define CONTOURNONEXISTED_H

#include "./contourState.h"
#include "../../SDK/opencv/opencvApi.h"
#include "../../Manager/regionManager.h"
#include "../../Manager/thresholdManager.h"

class ContourNonExisted : public ContourState {
/*method*/
public:
    static ContourNonExisted& getInstance();
    void createMaskByColor(Mat& maskImg, ChannelSet& channelSet) {
        for(int y=0; y<maskImg.rows; y++) {
            for(int x=0; x<maskImg.cols; x++) {
                if(L(channelSet.crMat(),x,y) >= _thresholdManager.cr() && L(channelSet.gMat(),x,y) <=_thresholdManager.g() && L(channelSet.yMat(),x,y) <= _thresholdManager.y()) {
    
                    L(maskImg,x,y) = 255;
                    
                } else if(L(channelSet.sMat(),x,y) >=_thresholdManager.s() && L(channelSet.crMat(),x,y) >= _thresholdManager.cr() && L(channelSet.gMat(),x,y) <=_thresholdManager.g()-15 && L(channelSet.yMat(),x,y) <= _thresholdManager.y() ) {
                    L(maskImg,x,y) = 255;
                }

                // if(L(channelSet.crMat(),x,y) <= _thresholdManager.cr() && L(channelSet.gMat(),x,y) <=_thresholdManager.g() && L(channelSet.yMat(),x,y) <= _thresholdManager.y()) {
    
                //     L(maskImg,x,y) = 255;
                    
                // }

            }
        }
    }

private:
    ContourNonExisted();
    ContourNonExisted(const ContourNonExisted&);
/*property*/
private:
    RegionManager& _regionManager = RegionManager::getInstance();
    ThresholdManager& _thresholdManager = ThresholdManager::getInstance();

};
#endif // CONTOURNONEXISTED_H
