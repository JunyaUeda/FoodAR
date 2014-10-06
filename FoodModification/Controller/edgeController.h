#ifndef EDGECONTROLLER_H
#define EDGECONTROLLER_H

#include "../Param/edgeParam.h"
#include "../Utils/opencvBase.h"

class EdgeController {
public:
	static EdgeController& getInstance();

	void changeCannyThreshold(int channelIndex, CannyThreshold* novel);
	void calculateEdges(Mat* channels, Mat* dstEdges);

private:
	EdgeParam* _edgeParam = new EdgeParam();
    EdgeController();
    EdgeController(const EdgeController&);
};

#endif // EDGECONTROLLER_H
