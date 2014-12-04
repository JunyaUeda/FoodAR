#ifndef COLORTHRESHOLD_H
#define COLORTHRESHOLD_H

#include "./channelThreshold.h"
#include "../TypeDef.h"
#include "./matSet.h"

class ColorThreshold {

/*method*/
public:
    ColorThreshold();
    void updateThresholds(QVi averages, QVi tolerances);
    vector<ChannelThreshold> channelThresholds() const;
    void setChannelThresholds(const vector<ChannelThreshold> &channelThresholds);
    void addEngagedChannelThreshold(ChannelThreshold& threshold);

    bool isWithinThreshold(MatSet& matSet, Point& point) {
        for(ChannelThreshold* thr : _engagedChannelThresholds) {
            if(!thr->isWithinThreshold(matSet, point)) {
                return  false;
            }
        }
        return true;
    }

    void updateEngagedChannels(vector<ChannelType> channelTypes);

    /**
    * リアルタイムの閾値調整
    *　@param degree 閾値の変更度合い
    * @param type どのチャンネルの閾値を変更するか
    * @see ChannelThresholdクラスのupdateVariableTolerance()
    */
    void updateChannelThresholdValue(int degree, ChannelType type);

    int luminance() {
         return _luminance;
    }

    void displayThreshold();

    int channelThresholdDegree(ChannelType type) {
        int channelNumber = static_cast<int>(type);
        return _channelThresholds[channelNumber].degree();
    }

/*property*/
private:
    vector<ChannelThreshold> _channelThresholds;
    vector<ChannelThreshold*> _engagedChannelThresholds;
    int _luminance;

};

#endif // COLORTHRESHOLD_H
