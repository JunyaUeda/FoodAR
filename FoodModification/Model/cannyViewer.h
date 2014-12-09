#ifndef CANNYVIEWER_H
#define CANNYVIEWER_H

#include "./SDK/opencv/opencvApi.h"
#include "./Manager/cameraManager.h"

class CannyViewer {

/*method*/
public:
	CannyViewer();
    void showCannyImgs();
    void closeCannyImgs();
private:

/*property*/
private:
    bool _isShowing = true;
    CameraManager& _cameraManager = CameraManager::getInstance();
};

#endif // CANNYVIEWER_H
