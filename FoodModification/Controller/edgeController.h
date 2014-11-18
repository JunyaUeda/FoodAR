#ifndef EDGECONTROLLER_H
#define EDGECONTROLLER_H

#include "../Model/TypeDef.h"
#include "../Param/edgeParam.h"
#include "../Utils/opencvUtils.h"
#include "../extractParamManager.h"

class EdgeController {

public:
	static EdgeController& getInstance();

	void calculateEdges(map<int, Mat>* channels, Mat* dstEdges);
    void calculateEdges(map<ChannelType, Mat>& channels, QVector<Mat>& dstEdges);
	void changeCannyThreshold(int channelIndex, CannyThreshold* novel);
	void addEdgeChannel(int channelIndex, CannyThreshold* threshold);

private:
	EdgeParam* _edgeParam = new EdgeParam();
    EdgeController();
    EdgeController(const EdgeController&);
};

#endif // EDGECONTROLLER_H
