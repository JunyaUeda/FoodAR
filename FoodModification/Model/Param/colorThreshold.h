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
};

#endif // COLORTHRESHOLD_H
