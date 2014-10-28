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

    srcController.bindSrc();
    
    Mat srcBGRImg, srcHSVImg, srcYCrCbImg, srcGrayImg, dstBGRImg;
    Mat BGRChannels[3], HSVChannels[3], YCrCbChannels[3];
    Mat BGREdges[3], HSVEdges[3], YCrCbEdges[3];

    
    map<int, Mat> edges;
    Mat maskImg;
    
    namedWindow("myWindow",CV_WINDOW_AUTOSIZE);
    setMouseCallback("myWindow", mouseCallback1);

    Size srcSize = srcController.srcParam()->cameraSize();
    srcBGRImg.create(srcSize, CV_8UC3);
    srcYCrCbImg.create(srcSize, CV_8UC3);
    srcHSVImg.create(srcSize, CV_8UC3);
    srcGrayImg.create(srcSize, CV_8UC1);
    maskImg.create(srcSize, CV_8UC3);
    


    while (1) {
        map<int, Mat> channels;
        srcController.loadSrc(srcBGRImg, srcHSVImg, srcYCrCbImg, srcGrayImg, &channels);
        edgeController.calculateEdges(&channels, YCrCbEdges);

        maskImg = Mat::zeros(srcBGRImg.size(), CV_8UC1);
        vector<vector<Point> > dstContours;
        extractController.extract(srcBGRImg, srcHSVImg, srcYCrCbImg, srcGrayImg, maskImg, dstContours, YCrCbEdges);
        imshow("myWindow", srcBGRImg);
        imshow("FinalExtractedImg", maskImg);

        
        vector<Rect> rects;
        if(textureParam->isNoTexture()) {
            textureController.setROI(dstContours, rects);
        } else {
            Mat textureImg = textureController.createTexture(dstContours, maskImg, rects, srcController.srcParam()->textureImg() );
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
