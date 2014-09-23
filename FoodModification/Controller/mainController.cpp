#include "mainController.h"
#include "../Utils/opencvUtils.h"

#define THRESHOLD1 30.0
#define THRESHOLD2 60.0
#define APERTURE_SIZE 3
#define L2_GRADIENT true

Mat srcHSVImg;//クリックポイントの色度値を取得するためにグローバルにしている。

MainController::MainController(ExtractParamManager *extractParamManager) {

	this->extractController = new ExtractController(extractParamManager);
    
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

    VideoCapture videoCapture = cv::VideoCapture(0);
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
        extractController->extract(srcBGRImg, srcHSVImg, srcYCrCbImg, srcGrayImg, maskImg, dstContours, YCrCbEdges);
        imshow("myWindow", srcBGRImg);
        imshow("FinalExtractedImg", maskImg);

        vector<Rect> rects;
        Mat textureImg = textureController->createTexture(dstContours, maskImg, rects);
        imshow("textureImg", textureImg);

        dstBGRImg = srcBGRImg.clone();
        convertController->convert(srcBGRImg,srcHSVImg, dstBGRImg, textureImg, maskImg, rects);
        imshow("dstImg",dstBGRImg);

        char ch = waitKey(33);
        if ( ch == 27 ) break;
    }

}
