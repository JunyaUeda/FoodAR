#ifndef CAMERAMANAGER_H
#define CAMERAMANAGER_H

#include "../SDK/opencv/opencvApi.h"

class CameraManager {

/*property*/
private:
    VideoCapture _capture;
    Size _size;
	Size _defaultSize = Size(640, 480);
/*method*/
public:
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
