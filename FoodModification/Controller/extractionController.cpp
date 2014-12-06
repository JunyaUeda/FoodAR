#include "extractionController.h"

ExtractionController::ExtractionController()
{
}

ExtractionController& ExtractionController::getInstance() {
    static ExtractionController instance;
    return instance;
}

void ExtractionController::updateEngagedColorChannels(vector<ChannelType> list) {
    _featureReference.updateEngagedChannels(list, 0);
    _featureReference.updateEngagedChannels(list, 1);
}

void ExtractionController::updateEngagedEdgeChannels(vector<ChannelType> list) {
    _edgeFactory.updateEngagedChannels(list);
}

void ExtractionController::updateChannelThresholdValue(int degree, ChannelType type, int index) {
    _featureReference.updateChannelThresholdValue(degree, type, index);
}

/*モルフォロジー変換*/
void ExtractionController::updateDilateCount(int count) {
    _extractionManager.setDilateCount(count);
}

void ExtractionController::updateErodeCount(int count) {
    _extractionManager.setErodeCount(count);
}

