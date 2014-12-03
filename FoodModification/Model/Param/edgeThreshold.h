#ifndef EDGETHRESHOLD_H
#define EDGETHRESHOLD_H

#include "../typeDef.h"
#include "./channelFunc/channelFunc.h"
#include "./channelFunc/blueFunc.h"
#include "./channelFunc/greenFunc.h"
#include "./channelFunc/redFunc.h"
#include "./channelFunc/hueFunc.h"
#include "./channelFunc/saturationFunc.h"
#include "./channelFunc/valueFunc.h"
#include "./channelFunc/yFunc.h"
#include "./channelFunc/crFunc.h"
#include "./channelFunc/cbFunc.h"

class EdgeThreshold {

/*method*/
public:
    EdgeThreshold();
	EdgeThreshold(ChannelFunc* type);
    int upper() const;
    int under() const;
    void setUpper(const int value);
    void setUnder(const int value);
    static map<ChannelType, EdgeThreshold> createAllEdgeThreshold();
private:
    

/*property*/
private:
    ChannelFunc* _channelFunc;
    int _upper;
    int _under;
};

#endif // EDGETHRESHOLD_H
