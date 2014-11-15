#ifndef FEATUREREFERENCE_H
#define FEATUREREFERENCE_H

#include "./Param/threshold.h"
#include "./Param/colorThreshold.h"
#include "../Utils/xmlUtils.h"
#include "../extractParamManager.h"
#include "./Param/channelFunc/channelFunc.h"
#include "./TypeDef.h"

class FeatureReference {

/*property*/
private:
    QList<ColorThreshold> _colorThresholds;
    Threshold* _threshold = new Threshold();
    ExtractParamManager& _extractParamManager = ExtractParamManager::getInstance();

/*method*/
public:
    static FeatureReference& getInstance();
    void loadFeaturesFromFile(QDomDocument doc);
    void updateThresholds(QVis averages, QVis tolerances);
    ChannelThreshold getChannelThreshold(ChannelFunc channelFunc);
    ColorThreshold* getColorThreshold(int value);
private:
    FeatureReference();
    FeatureReference(const FeatureReference&);
	void loadExtractColorSpace(QDomDocument doc);
	void loadAverage(QDomDocument doc);
	void loadTolerance(QDomDocument doc);

};

#endif // FEATUREREFERENCE_H
