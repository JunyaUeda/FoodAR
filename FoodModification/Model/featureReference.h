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
    bool isWithinThreshold(MatSet& matSet, Point point);
    void updateEngagedChannels(const vector<ChannelType> list, const int thresholdIndex);
    void displayThreshold();
private:
    FeatureReference();
    FeatureReference(const FeatureReference&);
    
    inline ColorThreshold* getColorThreshold(int value);

/*property*/
private:
    QList<ColorThreshold> _colorThresholds;
    
};

#endif // FEATUREREFERENCE_H
