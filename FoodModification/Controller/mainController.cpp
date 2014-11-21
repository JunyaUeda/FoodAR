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


void MainController::doConvertion() {
    _mainProcedure.start();
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

/**
* colorDialogの色の編集によって呼び出される.
*　@param HSVのシフト量
*/
void MainController::changeShiftValue(int hShift, int sShift, int vShift) {

    textureParam->setShift(hShift, sShift, vShift);
    
}

/**
* colorDialogの色の編集によって呼び出される.
*　@param shift量と色チャンネルを示すindex
*/
void MainController::changeShiftValue(int value, int colorIndex) {
    
    const int HUE = 0;
    const int SATURATION = 1;
    const int VALUE = 2;

    switch(colorIndex) {
        case HUE:
            textureParam->setH_shift(value);
            break;
        case SATURATION:
            textureParam->setS_shift(value);
            break;
        case VALUE:
            textureParam->setV_shift(value);
            break;
    }

}

/**
* alpha値のセットを行う。colorDialogの色の編集によって呼び出される.
*　@param value:double
*/
void MainController::setAlpha(double value) {

    textureParam->setAlpha(value);

}


/**
* mainWindowのテクスチャ選択によって呼び出される。テクスチャなしかどうかのフラグを設定する。
*　@param textureありなしのフラグ
*/
void MainController::setNoTexture(bool flag) {
    textureParam->setNoTexture(flag);
}
