#ifndef CONTOURSTATE_H
#define CONTOURSTATE_H

#include "../../Param/channelSet.h"
#include "../../SDK/opencv/opencvApi.h"

class ContourState {

/*method*/
public:
	ContourState();
    virtual void createMaskByColor(Mat& maskImg, ChannelSet& channelSet)=0;

};

#endif // CONTOURSTATE_H
