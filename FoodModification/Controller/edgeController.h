#ifndef EDGECONTROLLER_H
#define EDGECONTROLLER_H

#include "../Model/TypeDef.h"
#include "Model/Util/cvUtil.h"

class EdgeController {

/*method*/
public:
	static EdgeController& getInstance();

	//void changeCannyThreshold(int channelIndex, CannyThreshold* novel);
	//void addEdgeChannel(int channelIndex, CannyThreshold* threshold);

private:
    EdgeController();
    EdgeController(const EdgeController&);
};

#endif // EDGECONTROLLER_H
