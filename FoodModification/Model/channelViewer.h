#ifndef CHANNELVIEWER_H
#define CHANNELVIEWER_H

#include "./SDK/opencv/opencvApi.h"
#include "./Manager/cameraManager.h"

class ChannelViewer {

/*method*/
public:
	ChannelViewer();
    void showAllChannels();
    void closeAllWindows();

/*property*/
private:
    bool _isShowing = true;
    CameraManager& _cameraManager = CameraManager::getInstance();
};

#endif // CHANNELVIEWER_H
