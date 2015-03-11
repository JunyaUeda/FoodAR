#include "edgeFactory.h"

#define APERTURE_SIZE 3
#define L2_GRADIENT true

EdgeFactory::EdgeFactory() {
    _allEdgeThresholds = EdgeThreshold::createAllEdgeThreshold();
    _engagedChannels.push_back(ChannelType::y);
    _engagedChannels.push_back(ChannelType::green);
    _engagedChannels.push_back(ChannelType::red);
}

EdgeFactory& EdgeFactory::getInstance() {
    static EdgeFactory instance;
    return instance;
}

void EdgeFactory::createEdge(ChannelSet& channelSet, Rect& roi) {
    Mat edgeMat;
    Canny(channelSet.getChannelMat(ChannelType::saturation), edgeMat, 120,
         80,  APERTURE_SIZE, L2_GRADIENT);
    Mat dstEdgeImg = Mat::zeros(channelSet.size().height, channelSet.size().width, CV_8UC1);
    for(int y=roi.y; y < (roi.y + roi.height); y++) {
            for(int x=roi.x; x < (roi.x + roi.width); x++) {
                if(L(edgeMat,x,y) == 255) {
                    L(dstEdgeImg, x, y) = 255;
                } 
            }
        }
    //dilate(dstEdgeImg, dstEdgeImg, cv::Mat(), Point(-1,-1), 1);
    _edgeManager.currentEdge().setRoiMergedMat(dstEdgeImg);

}

void EdgeFactory::createEdges(const MatSet& matSet, vector<Mat>& resultRawEdgeImgs, map<ChannelType, Mat>& channelMats) {
    for(ChannelType type : _engagedChannels) {
        Mat edgeMat;
        Canny(channelMats[type], edgeMat, _allEdgeThresholds[type].upper(), _allEdgeThresholds[type].under(),  APERTURE_SIZE, L2_GRADIENT);
        resultRawEdgeImgs.push_back(edgeMat);
    }
}

void EdgeFactory::createEdges(ChannelSet& channelSet, Rect& roi) {

    vector<Mat> rawEdges;
    for(ChannelType type : _engagedChannels) {
        Mat edgeMat;
		Canny(channelSet.getChannelMat(type), edgeMat, _allEdgeThresholds[type].upper(), _allEdgeThresholds[type].under(),  APERTURE_SIZE, L2_GRADIENT);
        rawEdges.push_back(edgeMat);
    }
    _edgeManager.currentEdge().setRawMats(rawEdges);


	// Mat dstEdgeImg(channelSet.size().height, channelSet.size().width, CV_8UC1, 255);
 //    revMergeEdges(rawEdges, roi, dstEdgeImg);

    Mat dstEdgeImg = Mat::zeros(channelSet.size().height, channelSet.size().width, CV_8UC1);
    mergeEdges(rawEdges, roi, dstEdgeImg);

    _edgeManager.currentEdge().setRoiMergedMat(dstEdgeImg);

}

void EdgeFactory::updateEngagedChannels(vector<ChannelType> newList) {
    _engagedChannels = newList;
}

