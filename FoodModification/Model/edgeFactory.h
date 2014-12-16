#ifndef EDGEFACTORY_H
#define EDGEFACTORY_H

#include "./Param/edge.h"
#include "typeDef.h"
#include "./Param/edgeThreshold.h"
#include "./Param/channelSet.h"

class EdgeFactory {

/*method*/
public:
    static EdgeFactory& getInstance();
    void createEdges(const MatSet& matSet, vector<Mat>& resultRawEdgeImgs);
    void createEdges(const MatSet& matSet, vector<Mat>& resultRawEdgeImgs, map<ChannelType, Mat>& channelMats);
    void createEdges(const MatSet& matSet, vector<Mat>& resultRawEdgeImgs, ChannelSet& channelSet);
    void updateEngagedChannels(vector<ChannelType> newList);
private:
    EdgeFactory();
    EdgeFactory(const EdgeFactory&);
    
/*property*/
private:
    vector<ChannelType> _engagedChannels;
    map<ChannelType, Mat> _channelMats;
    map<ChannelType, EdgeThreshold> _allEdgeThresholds;
    
};

#endif // EDGEFACTORY_H
