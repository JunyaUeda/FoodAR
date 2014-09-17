#ifndef EDGESERVICE_H
#define EDGESERVICE_H
#include "../Utils/opencvBase.h"

class EdgeService : public OpenCVBase
{
public:
    EdgeService();
    void extractEdge(cv::Mat *channelEdgeImgs, cv::Mat dstEdgeImg);

private:
	void dillateEdge(cv::Mat *channelEdgeImgs);
};

#endif // EDGESERVICE_H
