#ifndef FEATUREREFERENCE_H
#define FEATUREREFERENCE_H

#include "./Param/threshold.h"
#include "../Utils/xmlUtils.h"
#include "../extractParamManager.h"

class FeatureReference {

/*property*/
private:
 Threshold* _threshold = new Threshold();
 ExtractParamManager& _extractParamManager = ExtractParamManager::getInstance();

/*method*/
public:
    FeatureReference();
    void loadFeaturesFromFile(QDomDocument doc);
private:
	void loadExtractColorSpace(QDomDocument doc);
	void loadAverage(QDomDocument doc);
	void loadTolerance(QDomDocument doc);

};

#endif // FEATUREREFERENCE_H
