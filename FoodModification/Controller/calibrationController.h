#ifndef CALIBRATIONCONTROLLER_H
#define CALIBRATIONCONTROLLER_H
#include "../Utils/opencvUtils.h"
#include "./Param/calibrateClickParam.h"
#include "../Model/Service/regionService.h"
#include "../Model/Executor/calibrator.h"
#include "../Model/Manager/cameraManager.h"

class CalibrationController {

/*method*/
public:
    static CalibrationController& getInstance();
    void calibrate_old();
    void calibrate(CalibrateClickParam* param);
    void videoInput();
    void capture();
    void stopDrawing();
    Size captureSize();

private:
    CalibrationController();
    CalibrationController(const CalibrationController&);

/*property*/
private:
    bool inputFlag = true;
    bool drawingFlag = true;
    CalibrateClickParam* clickParam;
    Calibrator& _calibrator = Calibrator::getInstance();
    CameraManager& _cameraManager = CameraManager::getInstance();

};

#endif // CALIBRATIONCONTROLLER_H
