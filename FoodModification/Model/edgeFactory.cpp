#include "edgeFactory.h"

#define APERTURE_SIZE 3
#define L2_GRADIENT true

EdgeFactory::EdgeFactory() {
    _allEdgeThresholds = EdgeThreshold::createAllEdgeThreshold();
    _engagedChannels.push_back(ChannelType::saturation);
    _engagedChannels.push_back(ChannelType::value);
    _engagedChannels.push_back(ChannelType::cr);
}

EdgeFactory& EdgeFactory::getInstance() {
    static EdgeFactory instance;
    return instance;
}

void EdgeFactory::createEdges(MatSet& matSet, vector<Mat>& resultRawEdgeImgs) {

   
    list<SpaceType> splittedSpaceType;

    for(ChannelType type : _engagedChannels) {
        switch(type) {
            case ChannelType::blue :
            case ChannelType::green :
            case ChannelType::red :
                splittedSpaceType.push_back(SpaceType::bgr);
                break;
            case ChannelType::hue :
            case ChannelType::saturation :
            case ChannelType::value :
                splittedSpaceType.push_back(SpaceType::hsv);
                break;
            case ChannelType::y :
            case ChannelType::cr :
            case ChannelType::cb :
                splittedSpaceType.push_back(SpaceType::ycrcb);
                break;

        }
    }

    map<ChannelType, Mat> channelMats;

    for(SpaceType type : splittedSpaceType) {
        Mat channels[3];
        switch(type) {
            case SpaceType::bgr :
                split(matSet.bgr(), channels);
                channelMats.insert( map<ChannelType,Mat>::value_type(ChannelType::blue, channels[0]) );
                channelMats.insert( map<ChannelType,Mat>::value_type(ChannelType::green, channels[1]) );
                channelMats.insert( map<ChannelType,Mat>::value_type(ChannelType::red, channels[2]) );
                break;
            case SpaceType::hsv :
                split(matSet.hsv(), channels);
                channelMats.insert( map<ChannelType,Mat>::value_type(ChannelType::hue, channels[0]) );
                channelMats.insert( map<ChannelType,Mat>::value_type(ChannelType::saturation, channels[1]) );
                channelMats.insert( map<ChannelType,Mat>::value_type(ChannelType::value, channels[2]) );
                break;
            case SpaceType::ycrcb :
                split(matSet.ycrcb(), channels);
                channelMats.insert( map<ChannelType,Mat>::value_type(ChannelType::y, channels[0]) );
                channelMats.insert( map<ChannelType,Mat>::value_type(ChannelType::cr, channels[1]) );
                channelMats.insert( map<ChannelType,Mat>::value_type(ChannelType::cb, channels[2]) );
                break;
        }
    }


    
    for(ChannelType type : _engagedChannels) {
        Mat edgeMat;
        Canny(channelMats[type], edgeMat, _allEdgeThresholds[type].upper(), _allEdgeThresholds[type].under(),  APERTURE_SIZE, L2_GRADIENT);
        resultRawEdgeImgs.push_back(edgeMat);
    }

}

void EdgeFactory::updateEngagedChannels(vector<ChannelType> newList) {
    _engagedChannels = newList;
}

