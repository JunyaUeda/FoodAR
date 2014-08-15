#include "opencvManager.h"

OpenCVManager::OpenCVManager(ExtractParamManager *extractParamManager)
{
    this->extractController = new ExtractController(extractParamManager);
}

void OpenCVManager::doConvertion() {

    cv::VideoCapture videoCapture = cv::VideoCapture(0);
    cv::Mat srcBGRImg, dstImg, srcHSVImg, srcYCrCbImg;
    cv::Mat srcGrayImg;
    cv::Mat BGRChannels[3], HSVChannels[3], YCrCbChannels[3];
    videoCapture >> srcBGRImg;
    if ( srcBGRImg.empty() ) {
     std::cerr << "Image can't be loaded!" << std::endl;
    }
    cv::namedWindow("myWindow",CV_WINDOW_NORMAL);
    cv::namedWindow("contourExtractedImg", CV_WINDOW_AUTOSIZE);
    videoCapture >> srcBGRImg;
    srcGrayImg.create(srcBGRImg.size(), CV_8UC1);
    dstImg.create(srcBGRImg.size(), CV_8UC3);

    while (1) {

        videoCapture >> srcBGRImg;

        cv::cvtColor(srcBGRImg, srcHSVImg, CV_BGR2HSV);
        cv::cvtColor(srcBGRImg, srcYCrCbImg,CV_BGR2YCrCb);

        cv::split(srcBGRImg, BGRChannels);
        cv::split(srcBGRImg, HSVChannels);
        cv::split(srcBGRImg, YCrCbChannels);

        //extractController->extractByColor(srcBGRImg, srcHSVImg, srcYCrCbImg);

        //cv::Mat grayImg (bgrImg.size(), CV_8UC1, cv::Scalar(0,0,0));
        cv::cvtColor(srcBGRImg, srcGrayImg, CV_BGR2GRAY);
        cv::threshold(srcGrayImg, srcGrayImg, 80, 255, cv::THRESH_BINARY);
        extractController->extractByContour(srcGrayImg, dstImg);
        cv::imshow("myWindow", srcBGRImg);
       // cv::imshow("contourExtractedImg", dstImg);


        char ch = cv::waitKey(33);
        if ( ch == 27 ) break;
    }
}
