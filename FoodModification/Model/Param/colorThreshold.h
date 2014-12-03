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
    bool isWithinThreshold(MatSet& matSet, Point point);
    void updateEngagedChannels(vector<ChannelType> channelTypes);
    int luminance();
    void displayThreshold();

/*property*/
private:
    vector<ChannelThreshold> _channelThresholds;
    vector<ChannelThreshold*> _engagedChannelThresholds;
    int _luminance;

};

#endif // COLORTHRESHOLD_H
