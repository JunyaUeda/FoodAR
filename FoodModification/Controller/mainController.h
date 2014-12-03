#ifndef MAINCONTROLLER_H
#define MAINCONTROLLER_H

#include "opencv2/opencv.hpp"
#include "../Utils/opencvUtils.h"
#include "./convertController.h"
#include "./srcController.h"
#include "../Param/textureParam.h"
#include "../Model/mainProcedure.h"


class MainController {

public:
	static MainController& getInstance();
    void start();
    void stop();
    void doConvertion();
	void setResizeFlag(bool flag);
	void setDstSize(Size size);
	void changeShiftValue(int hShift, int sShift, int vShift);
    void changeShiftValue(int value, int colorIndex);
    void setAlpha(double value);
    void setNoTexture(bool flag);

private:
    MainProcedure& _mainProcedure = MainProcedure::getInstance();


    TextureParam* textureParam = new TextureParam();
    bool resizeFlag = false;
    Size dstSize;

    MainController();
    MainController(const MainController&);
 
};

#endif // MAINCONTROLLER_H
