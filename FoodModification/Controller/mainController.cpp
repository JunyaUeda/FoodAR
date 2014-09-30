#include "mainController.h"
#include "../Utils/opencvUtils.h"

#define THRESHOLD1 30.0
#define THRESHOLD2 60.0
#define APERTURE_SIZE 3
#define L2_GRADIENT true

Mat srcHSVImg;//クリックポイントの色度値を取得するためにグローバルにしている。

MainController::MainController() {

}

MainController& MainController::getInstance() {
    static MainController instance;
    return instance;
}

void mouseCallback1(int event, int x, int y, int flags, void* param) {
 
    switch(event) {
        case cv::EVENT_LBUTTONDOWN:
            qDebug() << " H =" << B(srcHSVImg, x,y);
            qDebug() << " S =" << G(srcHSVImg, x,y);
            qDebug() << " V =" << R(srcHSVImg, x,y);
        break;
        case cv::EVENT_RBUTTONDOWN:
        
        break;
    }

}

void MainController::doConvertion() {

    videoCapture = cv::VideoCapture(0);
    Mat srcBGRImg, /*srcHSVImg, */srcYCrCbImg, srcGrayImg, dstBGRImg;
    Mat BGRChannels[3], HSVChannels[3], YCrCbChannels[3];
    Mat BGREdges[3], HSVEdges[3], YCrCbEdges[3];
    Mat maskImg;
    
    videoCapture >> srcBGRImg;
    if ( srcBGRImg.empty() ) {
     cerr << "Image can't be loaded!" << endl;
    }

    namedWindow("myWindow",CV_WINDOW_AUTOSIZE);
    srcGrayImg.create(srcBGRImg.size(), CV_8UC1);
    maskImg.create(srcBGRImg.size(), CV_8UC3);
    setMouseCallback("myWindow", mouseCallback1);

    textureParam->setPicturePath("../FoodModification/Images/toro.jpg");

    while (1) {

        videoCapture >> srcBGRImg;

        cvtColor(srcBGRImg, srcHSVImg, CV_BGR2HSV);
        cvtColor(srcBGRImg, srcYCrCbImg,CV_BGR2YCrCb);
        cvtColor(srcBGRImg, srcGrayImg, CV_BGR2GRAY);
        
        //cv::split(srcBGRImg, BGRChannels);
        //cv::split(srcBGRImg, HSVChannels);
        split(srcBGRImg, YCrCbChannels);

        // cv::Canny(BGRChannels[0], BGREdges[0], THRESHOLD1, THRESHOLD2, APERTURE_SIZE, L2_GRADIENT);
        // cv::Canny(BGRChannels[1], BGREdges[1], THRESHOLD1, THRESHOLD2, APERTURE_SIZE, L2_GRADIENT);
        // cv::Canny(BGRChannels[2], BGREdges[2], THRESHOLD1, THRESHOLD2, APERTURE_SIZE, L2_GRADIENT);
       // cv::Canny(HSVChannels[0], HSVEdges[0], THRESHOLD1, THRESHOLD2, APERTURE_SIZE, L2_GRADIENT);
       // cv::Canny(HSVChannels[1], HSVEdges[1], THRESHOLD1, THRESHOLD2, APERTURE_SIZE, L2_GRADIENT);
        //cv::Canny(HSVChannels[2], HSVEdges[2], THRESHOLD1, THRESHOLD2, APERTURE_SIZE, L2_GRADIENT);
        Canny(YCrCbChannels[0], YCrCbEdges[0], THRESHOLD1, THRESHOLD2, APERTURE_SIZE, L2_GRADIENT);
        Canny(YCrCbChannels[1], YCrCbEdges[1], THRESHOLD1, THRESHOLD2, APERTURE_SIZE, L2_GRADIENT);
        Canny(YCrCbChannels[2], YCrCbEdges[2], THRESHOLD1, THRESHOLD2, APERTURE_SIZE, L2_GRADIENT);
        
    
        //maskImg = srcBGRImg.clone();
        maskImg = Mat::zeros(srcBGRImg.size(), CV_8UC1);
        vector<vector<Point>> dstContours;
        //cv::threshold(srcGrayImg, srcGrayImg, 80, 255, cv::THRESH_BINARY);
        extractController.extract(srcBGRImg, srcHSVImg, srcYCrCbImg, srcGrayImg, maskImg, dstContours, YCrCbEdges);
        imshow("myWindow", srcBGRImg);
        imshow("FinalExtractedImg", maskImg);

        
        vector<Rect> rects;
        if(textureParam->isNoTexture()) {
            textureController.setROI(dstContours, rects);
        } else {
            Mat textureImg = textureController.createTexture(dstContours, maskImg, rects, textureParam->getPicturePath());
            textureParam->setImg(textureImg);
            imshow("textureImg", textureImg);
        }
        

        dstBGRImg = srcBGRImg.clone();
        convertController.convert(srcBGRImg,srcHSVImg, dstBGRImg, maskImg, rects, textureParam);
        if(resizeFlag) {
            resize(dstBGRImg, dstBGRImg, dstSize, 0, 0, INTER_LINEAR);
        }
        imshow("dstImg",dstBGRImg);


        char ch = waitKey(33);
        if ( ch == 27 ) break;
    }

}

/**
* mainWindowのサイズ設定によって呼び出される.
*　@param cv::Size
*/
void MainController::setVCaptureSize(Size size) {

    videoCapture.set(CV_CAP_PROP_FRAME_WIDTH, size.width);
    videoCapture.set(CV_CAP_PROP_FRAME_HEIGHT, size.height);

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
* mainWindowのテクスチャ選択によって呼び出される
*　@param textureのImageのパス
*/
void MainController::setPicturePath(String path) {

    textureParam->setPicturePath(path);

}

/**
* mainWindowのテクスチャ選択によって呼び出される。テクスチャなしかどうかのフラグを設定する。
*　@param textureありなしのフラグ
*/
void MainController::setNoTexture(bool flag) {
    textureParam->setNoTexture(flag);
}