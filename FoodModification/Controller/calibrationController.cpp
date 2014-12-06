#include "calibrationController.h"
#include <stdio.h>


#define RATIO_OF_REGION 0.95
#define BGR_SPACE 0
#define HSV_SPACE 1

CalibrationController::CalibrationController() {
	this->clickParam = new CalibrateClickParam;
}

CalibrationController& CalibrationController::getInstance() {
	static CalibrationController instance;
	return instance;
}

void CalibrationController::capture() {
	this->inputFlag = false;
}

void CalibrationController::stopDrawing() {
	this->drawingFlag = false;
}


/**
* calibrationの制御メソッド
*
*/
void CalibrationController::calibrate(CalibrateClickParam* param) {

    QVector<Scalar> color = QVector<Scalar>() << Scalar(0,0,255) << Scalar(0,255,0);
    _calibrator.calibrate(param->srcBGRImg, param->refImg, color);

}

Size CalibrationController::captureSize() {
    return _cameraManager.size();
}
