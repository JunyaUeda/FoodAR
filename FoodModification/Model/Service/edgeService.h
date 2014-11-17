#ifndef EDGESERVICE_H
#define EDGESERVICE_H

#include "../SDK/opencv/opencvApi.h"
#include <QVector>

class EdgeService {

/*property*/

/*method*/
public:
	EdgeService();
    void aqcuireEdgeImgs();
    void extractEdge(QVector<Mat> channelEdgeImgs, Mat dstEdgeImg);
    void extractEdge(cv::Mat *channelEdgeImgs, cv::Mat dstEdgeImg);
    void drawEdge(Mat srcEdgeImg, Mat dstDrawnImg, int luminace);

private:
    void dillateEdge(cv::Mat *channelEdgeImgs);
};

#endif // EDGESERVICE_H
