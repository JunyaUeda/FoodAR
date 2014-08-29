#include "mainController.h"
#include "../Utils/opencvUtils.h"
#define THRESHOLD1 30.0
#define THRESHOLD2 60.0
#define APERTURE_SIZE 3
#define L2_GRADIENT true

MainController::MainController(ExtractParamManager *extractParamManager)
{
	this->extractController = new ExtractController(extractParamManager);
}

void MainController::doConvertion() {

    cv::VideoCapture videoCapture = cv::VideoCapture(0);
    cv::Mat srcBGRImg, srcHSVImg, srcYCrCbImg, srcGrayImg;
    cv::Mat BGRChannels[3], HSVChannels[3], YCrCbChannels[3];
    cv::Mat BGREdges[3], HSVEdges[3], YCrCbEdges[3];
    cv::Mat dstImg;

    videoCapture >> srcBGRImg;
    if ( srcBGRImg.empty() ) {
     std::cerr << "Image can't be loaded!" << std::endl;
    }

    cv::namedWindow("myWindow",CV_WINDOW_NORMAL);
    cv::namedWindow("contourExtractedImg", CV_WINDOW_AUTOSIZE);
    srcGrayImg.create(srcBGRImg.size(), CV_8UC1);
    dstImg.create(srcBGRImg.size(), CV_8UC3);

    while (1) {

        videoCapture >> srcBGRImg;

        cv::cvtColor(srcBGRImg, srcHSVImg, CV_BGR2HSV);
        cv::cvtColor(srcBGRImg, srcYCrCbImg,CV_BGR2YCrCb);
        cv::cvtColor(srcBGRImg, srcGrayImg, CV_BGR2GRAY);
        
        cv::split(srcBGRImg, BGRChannels);
        cv::split(srcBGRImg, HSVChannels);
        cv::split(srcBGRImg, YCrCbChannels);

        cv::Canny(BGRChannels[0], BGREdges[0], THRESHOLD1, THRESHOLD2, APERTURE_SIZE, L2_GRADIENT);
        cv::Canny(BGRChannels[1], BGREdges[1], THRESHOLD1, THRESHOLD2, APERTURE_SIZE, L2_GRADIENT);
        cv::Canny(BGRChannels[2], BGREdges[2], THRESHOLD1, THRESHOLD2, APERTURE_SIZE, L2_GRADIENT);
        cv::Canny(HSVChannels[0], HSVEdges[0], THRESHOLD1, THRESHOLD2, APERTURE_SIZE, L2_GRADIENT);
        cv::Canny(HSVChannels[1], HSVEdges[1], THRESHOLD1, THRESHOLD2, APERTURE_SIZE, L2_GRADIENT);
        cv::Canny(HSVChannels[2], HSVEdges[2], THRESHOLD1, THRESHOLD2, APERTURE_SIZE, L2_GRADIENT);
        cv::Canny(YCrCbChannels[0], YCrCbEdges[0], THRESHOLD1, THRESHOLD2, APERTURE_SIZE, L2_GRADIENT);
        cv::Canny(YCrCbChannels[1], YCrCbEdges[1], THRESHOLD1, THRESHOLD2, APERTURE_SIZE, L2_GRADIENT);
        cv::Canny(YCrCbChannels[2], YCrCbEdges[2], THRESHOLD1, THRESHOLD2, APERTURE_SIZE, L2_GRADIENT);
        
        cv::imshow("result canny", BGREdges[0]);
        
        
        //dstImg = srcBGRImg.clone();
        dstImg = cv::Mat::zeros(srcBGRImg.size(), srcBGRImg.type());
        cv::threshold(srcGrayImg, srcGrayImg, 80, 255, cv::THRESH_BINARY);
        extractController->extract(srcBGRImg, srcHSVImg, srcYCrCbImg, srcGrayImg, dstImg, BGREdges);
        cv::imshow("myWindow", srcBGRImg);
        cv::imshow("contourExtractedImg", dstImg);


        char ch = cv::waitKey(33);
        if ( ch == 27 ) break;
    }
}
