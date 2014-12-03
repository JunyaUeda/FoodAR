#ifndef EXTRACTIONCONTROLLER_H
#define EXTRACTIONCONTROLLER_H

#include <QDebug>
#include "../Model/typeDef.h"
#include "../Model/featureReference.h"
#include "../Model/edgeFactory.h"

class ExtractionController {

/*method*/
public:
    static ExtractionController& getInstance();
    void updateEngagedColorChannels(vector<ChannelType> list);
    void updateEngagedEdgeChannels(vector<ChannelType> list);
private:
	ExtractionController();
    ExtractionController(const ExtractionController&);

/*property*/
private:
    FeatureReference& _featureReference = FeatureReference::getInstance();
    EdgeFactory& _edgeFactory = EdgeFactory::getInstance();

};

#endif // EXTRACTIONCONTROLLER_H
