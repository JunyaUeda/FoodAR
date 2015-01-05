#include "mainController.h"
#include "../Utils/opencvUtils.h"

#define THRESHOLD1 30.0
#define THRESHOLD2 60.0
#define APERTURE_SIZE 3
#define L2_GRADIENT true

MainController::MainController() {

}

MainController& MainController::getInstance() {
    static MainController instance;
    return instance;
}

void MainController::start() {
    _mainProcedure.start();
}

void MainController::stop() {
    _mainProcedure.stop();
}
/**
* チャンネル画像を見る
*/
void MainController::showChannelMat() {
    _mainProcedure.stop();
    _viewer.showAllChannels();
}

void MainController::closeChannelMat() {
    _viewer.closeAllWindows();
}

/**
* 各チャンネルの二値化画像を見る
*/
void MainController::showBinarizationImgs() {
    _mainProcedure.stop();
	_binarizationViewer.showBinarizedImgs();
}

void MainController::closeBinarizationImgs() {
	_binarizationViewer.closeBinarizedImgs();
}

/**
*Cannyエッジ画像を見る
*/
void MainController::showCannyImgs() {
    _mainProcedure.stop();
    _cannyViewer.showCannyImgs();
}
void MainController::closeCannyImgs() {
    _cannyViewer.closeCannyImgs();
}

/**
* mainWindowのサイズ設定によって呼び出される.
*　@param cv::Size
*/
void MainController::setDstSize(Size size) {

    dstSize = size;
    resizeFlag = true;

}

/**
* mainWindowのサイズ設定によって呼び出される.入力と出力画像のリサイズを行うかどうかのフラグを設定
*　@param cv::Size
*/
void MainController::setResizeFlag(bool flag) {
    resizeFlag = flag;
}



