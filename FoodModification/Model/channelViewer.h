#ifndef CHANNELVIEWER_H
#define CHANNELVIEWER_H

#include "./SDK/opencv/opencvApi.h"

class ChannelViewer {

/*method*/
public:
	ChannelViewer();
    void showAllChannels();
    void closeAllWindows();

/*property*/
private:
    bool _isShowing = true;
};

#endif // CHANNELVIEWER_H
