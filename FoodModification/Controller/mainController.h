#ifndef MAINCONTROLLER_H
#define MAINCONTROLLER_H

#include "opencv2/opencv.hpp"
#include "../Utils/opencvUtils.h"
#include "./convertController.h"
#include "../Model/mainProcedure.h"
#include "../Model/channelViewer.h"
#include "../Model/binarizationViewer.h"
#include "../Model/cannyViewer.h"


class MainController {

public:
	static MainController& getInstance();
    void start();
    void stop();
	void finish();

    /**チャンネル画像を見る*/
    void showChannelMat();
    void closeChannelMat();
    /**2値化画像を見る*/
	void showBinarizationImgs(QString file_name);
	void closeBinarizationImgs(QString file_name);
    /**Cannyエッジ画像を見る*/
    void showCannyImgs();
    void closeCannyImgs();
	void setResizeFlag(bool flag);
	void setDstSize(Size size);
	void changeShiftValue(int hShift, int sShift, int vShift);
    void changeShiftValue(int value, int colorIndex);
    void setAlpha(double value);
    void setNoTexture(bool flag);

private:
    MainProcedure& _mainProcedure = MainProcedure::getInstance();
	ChannelViewer _viewer;
    BinarizationViewer _binarizationViewer;
	CannyViewer _cannyViewer;
    bool resizeFlag = false;
    Size dstSize;
	int thresholds[5];

    MainController();
    MainController(const MainController&);
 
};

#endif // MAINCONTROLLER_H
