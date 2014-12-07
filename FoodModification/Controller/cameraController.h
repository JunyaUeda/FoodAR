#ifndef CAMERACONTROLLER_H
#define CAMERACONTROLLER_H

#include "../Model/SDK/opencv/opencvApi.h"
#include "../Model/Manager/cameraManager.h"

class CameraController {

/*method*/
public:
    static CameraController& getInstance();
    void setCaptureSize(Size size);
    void setCaptureSaturation(double value);
    void setCaptureExposure(double value);
    void setCaptureGain(double value);
    void setCaptureBrightness(double value);
    void setCaptureContrast(double value);

private:
	CameraController();
    CameraController(const CameraController&);

/*property*/
private:
    CameraManager& _cameraManager = CameraManager::getInstance();

};

#endif // CAMERACONTROLLER_H
