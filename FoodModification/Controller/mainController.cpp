#include "mainController.h"
#include "../Utils/opencvUtils.h"

#define THRESHOLD1 30.0
#define THRESHOLD2 60.0
#define APERTURE_SIZE 3
#define L2_GRADIENT true

MainController::MainController() {
	thresholds[0] = 0;
	thresholds[1] = 0;
	thresholds[2] = 0;
	thresholds[3] = 0;
	thresholds[4] = 0;
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

void MainController::finish() {
	_mainProcedure.finish();
	_binarizationViewer.finish();
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
void MainController::showBinarizationImgs(QString file_name) {
    _mainProcedure.stop();
	QFile file(file_name);
	if(!file.open(QIODevice::ReadOnly)){
				qDebug() << "cant open file";
				return;
	}

	QString str;
	QTextStream in(&file);
	in >> str;

	int thresholds[5];
	for(int i=0; i < 5; i++) {
		QStringList list = str.split(',');
		thresholds[i] = list[2*i+1].toInt();
	}
	file.close();
	_binarizationViewer.showBinarizedImgs(thresholds);
}

void MainController::closeBinarizationImgs(QString file_name) {
	_binarizationViewer.closeBinarizedImgs(thresholds);
	QFile file(file_name);
	if ( file.open(QIODevice::WriteOnly ) ) {
		QTextStream stream( &file );
		stream << "b" << "," << thresholds[0] << ",";
		stream << "s" << "," << thresholds[1] <<",";
		stream << "y" << "," << thresholds[2] <<",";
		stream << "cr" << "," << thresholds[3] <<",";
		stream << "cb" << "," << thresholds[4] <<endl;
	}
	file.close();
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

/**
* colorDialogの色の編集によって呼び出される.
*　@param HSVのシフト量
*/
void MainController::changeShiftValue(int hShift, int sShift, int vShift) {

	//textureParam->setShift(hShift, sShift, vShift);
}

/**
* colorDialogの色の編集によって呼び出される.
*　@param shift量と色チャンネルを示すindex
*/
void MainController::changeShiftValue(int value, int colorIndex) {
    
    const int HUE = 0;
    const int SATURATION = 1;
    const int VALUE = 2;

//    switch(colorIndex) {
//        case HUE:
//            textureParam->setH_shift(value);
//            break;
//        case SATURATION:
//            textureParam->setS_shift(value);
//            break;
//        case VALUE:
//            textureParam->setV_shift(value);
//            break;
//    }

}

/**
* alpha値のセットを行う。colorDialogの色の編集によって呼び出される.
*　@param value:double
*/
void MainController::setAlpha(double value) {

   // textureParam->setAlpha(value);

}


/**
* mainWindowのテクスチャ選択によって呼び出される。テクスチャなしかどうかのフラグを設定する。
*　@param textureありなしのフラグ
*/
void MainController::setNoTexture(bool flag) {
	//textureParam->setNoTexture(flag);
}
