#ifndef COLORTHRESHOLD_H
#define COLORTHRESHOLD_H

#include "./channelThreshold.h"
#include "../TypeDef.h"
#include "./matSet.h"

class ColorThreshold {

/*property*/
private:
    QList<ChannelThreshold> _channelThresholds;
    QList<ChannelThreshold> _usedChannelThresholds;
    int _luminance;

/*method*/
public:
	ColorThreshold();
    void updateThresholds(QVi averages, QVi tolerances);
    QList<ChannelThreshold> channelThresholds() const;
    void setChannelThresholds(const QList<ChannelThreshold> &channelThresholds);
    void addUsedChannelThreshold(ChannelThreshold threshold);
    bool isWithinThreshold(MatSet* matSet, Point point);
    void updateUsedChannels(QList<ChannelType> channelTypes);
    int luminance();

};

#endif // COLORTHRESHOLD_H
