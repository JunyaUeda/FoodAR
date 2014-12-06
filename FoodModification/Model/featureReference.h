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
    void updateThresholds(QVis averages, QVis tolerances);

    bool isWithinThreshold(MatSet& matSet, Point& point) {
        int value = L(matSet.hsv(), point.x, point.y);
        if(abs(value - _colorThresholds[0].luminance()) > abs(value - _colorThresholds[1].luminance() ) ){
            if( _colorThresholds[1].isWithinThreshold(matSet, point)) {
                return true;
            }
            return false;
        } else {
            if( _colorThresholds[0].isWithinThreshold(matSet, point)) {
                return true;
            }
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

    int channelThresholdDegree(ChannelType type, int index){
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
