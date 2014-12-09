#ifndef EXTRACTIONCONTROLLER_H
#define EXTRACTIONCONTROLLER_H

#include <QDebug>
#include "../Model/typeDef.h"
#include "../Model/featureReference.h"
#include "../Model/edgeFactory.h"
#include "../Model/Manager/extractionManager.h"
#include "../Model/Executor/extractor.h"


class ExtractionController {

/*method*/
public:
    static ExtractionController& getInstance();
    void updateEngagedColorChannels(vector<ChannelType> list);
    void updateEngagedEdgeChannels(vector<ChannelType> list);
    void updateChannelThresholdValue(int degree, ChannelType type, int index);
    int channelThresholdComboBox_currentIndexChanged(ChannelType type){
		return _featureReference.channelThresholdDegree(type, 0);
    }
    void updateDilateCount(int count);
    void updateErodeCount(int count);
    void updateRatioOfPixelNum(double upperRatio, double underRatio) {
        _extractionManager.updateRatioOfPixelNum(upperRatio, underRatio);
    }
    void updateGreenBinarizationThreshold(int value) {
        _extractor.updateGreenBinarizationThreshold(value);
    }   
    void updateYBinarizationThreshold(int value) {
        _extractor.updateYBinarizationThreshold(value);
    }
    void updateCrBinarizationThreshold(int value) {
        _extractor.updateCrBinarizationThreshold(value);
    }
private:
	ExtractionController();
    ExtractionController(const ExtractionController&);

/*property*/
private:
    FeatureReference& _featureReference = FeatureReference::getInstance();
    EdgeFactory& _edgeFactory = EdgeFactory::getInstance();
    ExtractionManager& _extractionManager = ExtractionManager::getInstance();
    Extractor& _extractor = Extractor::getInstance();
};

#endif // EXTRACTIONCONTROLLER_H
