#include "channelViewer.h"
#include <qDebug>
ChannelViewer::ChannelViewer() {
}

void ChannelViewer::showAllChannels() {
    // VideoCapture capture = VideoCapture(0);
    Mat srcBGRImg;
    Mat srcHSVImg;
    Mat srcYCrCbImg;
    Mat bgrChannelImgs[3];
    Mat hsvChannelImgs[3];
    Mat ycrcbChannelImgs[3];

    _isShowing = true;
    while(_isShowing) {

        srcBGRImg = _cameraManager.getFrame();
        cvtColor(srcBGRImg, srcHSVImg, CV_BGR2HSV);
        cvtColor(srcBGRImg, srcYCrCbImg, CV_BGR2YCrCb);

        split(srcBGRImg, bgrChannelImgs);
        split(srcHSVImg, hsvChannelImgs);
        split(srcYCrCbImg, ycrcbChannelImgs);

        imshow("src", srcBGRImg);
        imshow("Blue", bgrChannelImgs[0]);
        imshow("Green", bgrChannelImgs[1]);
        imshow("Red", bgrChannelImgs[2]);
        imshow("Hue", hsvChannelImgs[0]);
        imshow("Saturation", hsvChannelImgs[1]);
        imshow("Value", hsvChannelImgs[2]);
        imshow("Y", ycrcbChannelImgs[0]);
        imshow("Cr", ycrcbChannelImgs[1]);
        imshow("Cb", ycrcbChannelImgs[2]);

		char ch = waitKey(33);
		if ( ch == 27 ) break;
    }

    destroyAllWindows();
}

void ChannelViewer::closeAllWindows() {
    _isShowing = false;
}
