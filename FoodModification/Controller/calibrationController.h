#ifndef CALIBRATIONCONTROLLER_H
#define CALIBRATIONCONTROLLER_H
#include "../Utils/opencvUtils.h"
#include "../Param/calibrateClickParam.h"
#include "../Model/Service/regionService.h"
#include "../Model/Executor/calibrator.h"

class CalibrationController {

public:
    static CalibrationController& getInstance();
    void calibrate_old();
    void calibrate(CalibrateClickParam* param);
    void videoInput();
    void capture();
    void stopDrawing();
    
private:
    bool inputFlag = true;
    bool drawingFlag = true;
    CalibrateClickParam* clickParam;
    Calibrator& _calibrator = Calibrator::getInstance();


    CalibrationController();
    CalibrationController(const CalibrationController&);
    
};

#endif // CALIBRATIONCONTROLLER_H
