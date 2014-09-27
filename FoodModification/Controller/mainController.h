#ifndef MAINCONTROLLER_H
#define MAINCONTROLLER_H
#include "opencv2/opencv.hpp"
#include "./extractController.h"
#include "../Utils/opencvUtils.h"
#include "./textureController.h"
#include "./convertController.h"
#include "./calibrationController.h"

class MainController {

public:
	VideoCapture videoCapture;

	static MainController& getInstance();
    void doConvertion();
	void setVCaptureSize(int width, int height);

private:
    ExtractController& extractController = ExtractController::getInstance();
    CalibrationController& calibrationController = CalibrationController::getInstance();
    TextureController& textureController = TextureController::getInstance();
    ConvertController& convertController = ConvertController::getInstance();

    MainController();
    MainController(const MainController&);
    
};

#endif // MAINCONTROLLER_H
