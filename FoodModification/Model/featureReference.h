#pragma once
#ifndef FEATUREREFERENCE_H
#define FEATUREREFERENCE_H

#include "./Param/colorThreshold.h"
#include "../Utils/xmlUtils.h"
#include "./Param/channelFunc/channelFunc.h"
#include "./TypeDef.h"

class FeatureReference {

/*method*/
public:
    static FeatureReference& getInstance();
    void loadFeaturesFromFile(QDomDocument doc);
    void updateAverages(vint averages) {
        _colorThresholds[1].updateAverages(averages);
    }
    void updateMedianAndTolerance(vint medians, vint upperTolerances, vint underTolerances) {
        _colorThresholds[1].updateMedianAndTolerance(medians, upperTolerances, underTolerances);
    }

    void updateThresholds(QVis averages, QVis tolerances);

    bool isWithinThreshold(MatSet& matSet, Point& point) {
        
        // if( _colorThresholds[1].isWithinThreshold(matSet, point)) {
        //     return true;
        // } else if ( _colorThresholds[0].isWithinThreshold(matSet, point)) {
        //     return true;
        // } else {
        //     return false;
        // }

        if( _colorThresholds[1].isWithinThreshold(matSet, point)) {
            return true;
        } else {
            return false;
        }

    }

    void updateEngagedChannels(const vector<ChannelType> list, const int thresholdIndex);

     /**
    * リアルタイムの閾値調整
    *　@param degree 閾値の変更度合い
    * @param type どのチャンネルの閾値を変更するか
    * @param index 何個目のcolorThreshold か
    * @see ColorThresholdクラスのupdateChannelThresholdValue()
    */
    void updateChannelThresholdValue(int degree, ChannelType type, int index);
    void displayThreshold();

    int channelThresholdDegree(ChannelType type) {
        return _colorThresholds[0].channelThresholdDegree(type); //ほんとはindexで区別すべし
    }

private:
    FeatureReference();
    FeatureReference(const FeatureReference&);
    
/*property*/
private:
    vector<ColorThreshold> _colorThresholds;
    
};

#endif // FEATUREREFERENCE_H
