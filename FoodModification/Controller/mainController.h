#ifndef MAINCONTROLLER_H
#define MAINCONTROLLER_H

#include "opencv2/opencv.hpp"
#include "./extractController.h"
#include "../Utils/opencvUtils.h"
#include "./textureController.h"
#include "./convertController.h"
#include "./calibrationController.h"
#include "./edgeController.h"
#include "./srcController.h"
#include "../Param/textureParam.h"
#include "../Model/sourcer.h"


class MainController {

public:
	static MainController& getInstance();
    void doConvertion();
	void setResizeFlag(bool flag);
	void setDstSize(Size size);
	void changeShiftValue(int hShift, int sShift, int vShift);
    void changeShiftValue(int value, int colorIndex);
    void setAlpha(double value);
    void setNoTexture(bool flag);

private:
    ExtractController& extractController         = ExtractController::getInstance();
    CalibrationController& calibrationController = CalibrationController::getInstance();
    TextureController& textureController         = TextureController::getInstance();
    ConvertController& convertController         = ConvertController::getInstance();
    EdgeController& edgeController               = EdgeController::getInstance();
    SrcController& srcController                 = SrcController::getInstance();
    Extractor& _extractor = Extractor::getInstance();
    Sourcer& _sourcer = Sourcer::getInstance();

    TextureParam* textureParam = new TextureParam();
    bool resizeFlag = false;
    Size dstSize;

    MainController();
    MainController(const MainController&);
 
};

#endif // MAINCONTROLLER_H
