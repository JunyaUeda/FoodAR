#ifndef COLORTHRESHOLD_H
#define COLORTHRESHOLD_H

#include "./channelThreshold.h"
#include "../TypeDef.h"

class ColorThreshold {

/*property*/
private:
    QList<ChannelThreshold> _channelThresholds;

/*method*/
public:
	ColorThreshold();
    void updateThresholds(QVi averages, QVi tolerances);
    QList<ChannelThreshold> channelThresholds() const;
    void setChannelThresholds(const QList<ChannelThreshold> &channelThresholds);
    bool isWithinThreshold(int h, int s, int v);
};

#endif // COLORTHRESHOLD_H
