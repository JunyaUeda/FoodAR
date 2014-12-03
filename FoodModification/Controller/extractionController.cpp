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