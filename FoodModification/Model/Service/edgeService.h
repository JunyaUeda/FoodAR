#ifndef EDGESERVICE_H
#define EDGESERVICE_H

#include "../SDK/opencv/opencvApi.h"
#include "../Param/region.h"


class EdgeService {

/*method*/
public:
	EdgeService();
    void aqcuireEdgeImgs();
    Mat extractEdge(vector<Mat>& channelEdgeImgs, Rect& roi);
    void drawEdge(Mat srcEdgeImg, Mat dstDrawnImg, int luminace);

private:
    void dillateEdge(cv::Mat *channelEdgeImgs);

/*property*/

};

#endif // EDGESERVICE_H
