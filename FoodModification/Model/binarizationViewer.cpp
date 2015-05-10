#include "binarizationViewer.h"

BinarizationViewer::BinarizationViewer() {
	_thresholds[0] = 128;
	_thresholds[1] = 128;
	_thresholds[2] = 128;
	_thresholds[3] = 128;
	_thresholds[4] = 128;
}

int binarizationViewerBlueThreshold = 128;
//int binarizationViewerGgreenThreshold = 128;
//int binarizationViewerRedThreshold = 128;
//int binarizationViewerHueThreshold = 128;
int binarizationViewerSaturationThreshold = 128;
//int binarizationViewerValueThreshold = 128;
int binarizationViewerYThreshold = 128;
int binarizationViewerCrThreshold = 128;
int binarizationViewerCbThreshold = 128;

void onBlueTrackbar(int position) {
    binarizationViewerBlueThreshold = position;
}
//void onGreenTrackbar(int position) {
//    binarizationViewerGgreenThreshold = position;
//}
//void onRedTrackbar(int position) {
//    binarizationViewerRedThreshold = position;
//}
//void onHueTrackbar(int position) {
//    binarizationViewerHueThreshold = position;
//}
void onSaturationTrackbar(int position) {
    binarizationViewerSaturationThreshold = position;
}
//void onValueTrackbar(int position) {
//    binarizationViewerValueThreshold = position;
//}
void onYTrackbar(int position) {
    binarizationViewerYThreshold = position;
}
void onCrTrackbar(int position) {
    binarizationViewerCrThreshold = position;
}
void onCbTrackbar(int position) {
    binarizationViewerCbThreshold = position;
}


void BinarizationViewer::showBinarizedImgs(int* thresholdsFromFile) {
	for(int i=0; i<5; i++) {
		_thresholds[i] = thresholdsFromFile[i];
	}

    Mat srcBGRImg, srcHSVImg, srcYCrCbImg;
    Mat bgrChannelImgs[3], hsvChannelImgs[3], ycrcbChannelImgs[3];

    vector<string> channelNames = {};
    int trackbarInitValue = 128;
    namedWindow("Blue", CV_WINDOW_AUTOSIZE);
//    namedWindow("Green", CV_WINDOW_AUTOSIZE);
//    namedWindow("Red", CV_WINDOW_AUTOSIZE);
//    namedWindow("Hue", CV_WINDOW_AUTOSIZE);
    namedWindow("Saturation", CV_WINDOW_AUTOSIZE);
//    namedWindow("Value", CV_WINDOW_AUTOSIZE);
    namedWindow("Y", CV_WINDOW_AUTOSIZE);
    namedWindow("Cr", CV_WINDOW_AUTOSIZE);
    namedWindow("Cb", CV_WINDOW_AUTOSIZE);

    cvCreateTrackbar("B_Threshold", "Blue", &trackbarInitValue, 255, onBlueTrackbar);
//    cvCreateTrackbar("G_Threshold", "Green", &trackbarInitValue, 255, onGreenTrackbar);
//    cvCreateTrackbar("R_Threshold", "Red", &trackbarInitValue, 255, onRedTrackbar);
//    cvCreateTrackbar("H_Threshold", "Hue", &trackbarInitValue, 255, onHueTrackbar);
    cvCreateTrackbar("S_Threshold", "Saturation", &trackbarInitValue, 255, onSaturationTrackbar);
//    cvCreateTrackbar("V_Threshold", "Value", &trackbarInitValue, 255, onValueTrackbar);
    cvCreateTrackbar("Y_Threshold", "Y", &trackbarInitValue, 255, onYTrackbar);
    cvCreateTrackbar("Cr_Threshold", "Cr", &trackbarInitValue, 255, onCrTrackbar);
    cvCreateTrackbar("Cb_Threshold", "Cb", &trackbarInitValue, 255, onCbTrackbar);

	cvSetTrackbarPos("B_Threshold", "Blue", _thresholds[0]);
//    cvSetTrackbarPos("G_Threshold", "Green", 128);
//    cvSetTrackbarPos("R_Threshold", "Red", 128);
//    cvSetTrackbarPos("H_Threshold", "Hue", 128);
	cvSetTrackbarPos("S_Threshold", "Saturation", _thresholds[1]);
//    cvSetTrackbarPos("V_Threshold", "Value", 128);
	cvSetTrackbarPos("Y_Threshold", "Y", _thresholds[2]);
	cvSetTrackbarPos("Cr_Threshold", "Cr", _thresholds[3]);
	cvSetTrackbarPos("Cb_Threshold", "Cb", _thresholds[4]);

    _isShowing = true;
	while(_isShowing) {
        srcBGRImg = _cameraManager.getFrame();

        cvtColor(srcBGRImg, srcHSVImg, CV_BGR2HSV);
        cvtColor(srcBGRImg, srcYCrCbImg, CV_BGR2YCrCb);

        split(srcBGRImg, bgrChannelImgs);
        split(srcHSVImg, hsvChannelImgs);
        split(srcYCrCbImg, ycrcbChannelImgs);

        threshold(bgrChannelImgs[0], bgrChannelImgs[0], binarizationViewerBlueThreshold, 255, CV_THRESH_BINARY);
//        threshold(bgrChannelImgs[1], bgrChannelImgs[1], binarizationViewerGgreenThreshold, 255, CV_THRESH_BINARY);
//        threshold(bgrChannelImgs[2], bgrChannelImgs[2], binarizationViewerRedThreshold, 255, CV_THRESH_BINARY);
//        threshold(hsvChannelImgs[0], hsvChannelImgs[0], binarizationViewerHueThreshold, 255, CV_THRESH_BINARY);
        threshold(hsvChannelImgs[1], hsvChannelImgs[1], binarizationViewerSaturationThreshold, 255, CV_THRESH_BINARY);
//        threshold(hsvChannelImgs[2], hsvChannelImgs[2], binarizationViewerValueThreshold, 255, CV_THRESH_BINARY);
        threshold(ycrcbChannelImgs[0], ycrcbChannelImgs[0], binarizationViewerYThreshold, 255, CV_THRESH_BINARY);
        threshold(ycrcbChannelImgs[1], ycrcbChannelImgs[1], binarizationViewerCrThreshold, 255, CV_THRESH_BINARY);
        threshold(ycrcbChannelImgs[2], ycrcbChannelImgs[2], binarizationViewerCbThreshold, 255, CV_THRESH_BINARY);
        
        imshow("src", srcBGRImg);
        imshow("Blue", bgrChannelImgs[0]);
//        imshow("Green", bgrChannelImgs[1]);
//        imshow("Red", bgrChannelImgs[2]);
//        imshow("Hue", hsvChannelImgs[0]);
        imshow("Saturation", hsvChannelImgs[1]);
//        imshow("Value", hsvChannelImgs[2]);
        imshow("Y", ycrcbChannelImgs[0]);
        imshow("Cr", ycrcbChannelImgs[1]);
        imshow("Cb", ycrcbChannelImgs[2]);

		_thresholds[0] = cvGetTrackbarPos ("B_Threshold", "Blue");
		_thresholds[1] = cvGetTrackbarPos ("S_Threshold", "Saturation");
		_thresholds[2] = cvGetTrackbarPos ("Y_Threshold", "Y");
		_thresholds[3] = cvGetTrackbarPos ("Cr_Threshold", "Cr");
		_thresholds[4] = cvGetTrackbarPos ("Cb_Threshold", "Cb");

		int key = waitKey(1);
        if(key == 27) break;
    }

    destroyAllWindows();
}

void BinarizationViewer::closeBinarizedImgs(int* thresholds) {
    _isShowing = false;
	for(int i=0; i<5; i++) {
		thresholds[i] = _thresholds[i];
	}

}

