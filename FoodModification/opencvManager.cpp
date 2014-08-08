#include "opencvManager.h"

OpenCVManager::OpenCVManager(ExtractParamManager *extractParamManager)
{
    this->extractController = new ExtractController(extractParamManager);
}

void OpenCVManager::doConvertion() {

    cv::VideoCapture videoCapture = cv::VideoCapture(0);
    cv::Mat srcBGRImg, dstImg, srcHSVImg, srcYCrCbImg;
    cv::Mat BGRChannels[3], HSVChannels[3], YCrCbChannels[3];
    videoCapture >> srcBGRImg;
    if ( srcBGRImg.empty() ) {
     std::cerr << "Image can't be loaded!" << std::endl;
    }
    cv::namedWindow("myWindow",CV_WINDOW_NORMAL);

    while (1) {

        videoCapture >> srcBGRImg;

        cv::cvtColor(srcBGRImg, srcHSVImg, CV_BGR2HSV);
        cv::cvtColor(srcBGRImg, srcYCrCbImg,CV_BGR2YCrCb);

        cv::split(srcBGRImg, BGRChannels);
        cv::split(srcBGRImg, HSVChannels);
        cv::split(srcBGRImg, YCrCbChannels);

        extractController->extractByColor(srcBGRImg, srcHSVImg, srcYCrCbImg);

        cv::imshow("myWindow",YCrCbChannels[1]);


        char ch = cv::waitKey(33);
        if ( ch == 27 ) break;
    }
}
