#include "channelViewer.h"
#include <qDebug>
ChannelViewer::ChannelViewer() {
}

Mat srcBGRImg;
Mat srcHSVImg;
void mouse_callback(int event, int x, int y, int flags, void* param){
    
    switch (event){
    

        case cv::EVENT_LBUTTONDOWN:
            qDebug() << "H =" << B(srcHSVImg, x, y);
            qDebug() << "S =" << G(srcHSVImg, x, y);
            qDebug() << "V =" << R(srcHSVImg, x, y);
            break;
        default:
            break;
    }
}



void ChannelViewer::showAllChannels() {
    
    
    
    Mat srcYCrCbImg;
    Mat bgrChannelImgs[3];
    Mat hsvChannelImgs[3];
    Mat ycrcbChannelImgs[3];
    namedWindow("src", 0);
    setMouseCallback("src",mouse_callback, 0);
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
