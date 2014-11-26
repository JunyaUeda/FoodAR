#ifndef CAMERAMANAGER_H
#define CAMERAMANAGER_H

#include "../SDK/opencv/opencvApi.h"

class CameraManager {

/*property*/
private:
    Size _size;
	Size _defaultSize = Size(640, 480);
/*method*/
public:
    VideoCapture _capture;
	static CameraManager& getInstance();
    bool setUp();
    void setCaptureSize(Size size);
    Mat getFrame();
private:
    CameraManager();
    CameraManager(const CameraManager&);
    void bindCamera(int port);
};

#endif // CAMERAMANAGER_H
