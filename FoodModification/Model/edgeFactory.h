#ifndef EDGEFACTORY_H
#define EDGEFACTORY_H

#include "./Param/edge.h"
#include "typeDef.h"
#include "./Param/edgeThreshold.h"

class EdgeFactory {

/*method*/
public:
    static EdgeFactory& getInstance();
    void createEdges(MatSet& matSet, vector<Mat>& resultRawEdgeImgs);
    void createEdges(MatSet& matSet, vector<Mat>& resultRawEdgeImgs, map<ChannelType, Mat>& channelMats);
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
