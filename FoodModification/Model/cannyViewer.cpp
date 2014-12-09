#include "cannyViewer.h"

#define APERTURE_SIZE 3
#define L2_GRADIENT true

CannyViewer::CannyViewer() {
}

int cannyViewerUpperThreshold[9] = {60};
int cannyViewerUnderThreshold[9] = {30};

void onBlueUpperTrackbar(int position) {
    cannyViewerUpperThreshold[0] = position;
}
void onGreenUpperTrackbar(int position) {
    cannyViewerUpperThreshold[1] = position;
}
void onRedUpperTrackbar(int position) {
    cannyViewerUpperThreshold[2] = position;
}
void onHueUpperTrackbar(int position) {
    cannyViewerUpperThreshold[3] = position;
}
void onSaturationUpperTrackbar(int position) {
    cannyViewerUpperThreshold[4] = position;
}
void onValueUpperTrackbar(int position) {
    cannyViewerUpperThreshold[5] = position;
}
void onYUpperTrackbar(int position) {
    cannyViewerUpperThreshold[6] = position;
}
void onCrUpperTrackbar(int position) {
    cannyViewerUpperThreshold[7] = position;
}
void onCbUpperTrackbar(int position) {
    cannyViewerUpperThreshold[8] = position;
}

void onBlueUnderTrackbar(int position) {
    cannyViewerUnderThreshold[0] = position;
}
void onGreenUnderTrackbar(int position) {
    cannyViewerUnderThreshold[1] = position;
}
void onRedUnderTrackbar(int position) {
    cannyViewerUnderThreshold[2] = position;
}
void onHueUnderTrackbar(int position) {
    cannyViewerUnderThreshold[3] = position;
}
void onSaturationUnderTrackbar(int position) {
    cannyViewerUnderThreshold[4] = position;
}
void onValueUnderTrackbar(int position) {
    cannyViewerUnderThreshold[5] = position;
}
void onYUnderTrackbar(int position) {
    cannyViewerUnderThreshold[6] = position;
}
void onCrUnderTrackbar(int position) {
    cannyViewerUnderThreshold[7] = position;
}
void onCbUnderTrackbar(int position) {
    cannyViewerUnderThreshold[8] = position;
}

void CannyViewer::showCannyImgs() {
    
    Mat srcBGRImg, srcHSVImg, srcYCrCbImg;
    Mat bgrChannelImgs[3], hsvChannelImgs[3], ycrcbChannelImgs[3];

    vector<string> channelNames = {
        "Blue",
        "Green",
        "Red",
        "Hue",
        "Saturation",
        "Value",
        "Y",
        "Cr",
        "Cb"
    };
    vector<string> upperTrackbarNames;
    vector<string> underTrackbarNames;
    for(int i=0; i<9; i++) {
        upperTrackbarNames.push_back(channelNames[i]+"upper");
        underTrackbarNames.push_back(channelNames[i]+"under");
    }

    for(int i=0; i<9; i++) {
        namedWindow(channelNames[i], CV_WINDOW_AUTOSIZE);
    }
    int trackbarUpperInitValue = 60;
    int trackbarUnderInitValue = 30;
    cvCreateTrackbar(upperTrackbarNames[0].c_str(), channelNames[0].c_str(), &trackbarUpperInitValue, 255, onBlueUpperTrackbar);
    cvCreateTrackbar(upperTrackbarNames[1].c_str(), channelNames[1].c_str(), &trackbarUpperInitValue, 255, onGreenUpperTrackbar);
    cvCreateTrackbar(upperTrackbarNames[2].c_str(), channelNames[2].c_str(), &trackbarUpperInitValue, 255, onRedUpperTrackbar);
    cvCreateTrackbar(upperTrackbarNames[3].c_str(), channelNames[3].c_str(), &trackbarUpperInitValue, 255, onHueUpperTrackbar);
    cvCreateTrackbar(upperTrackbarNames[4].c_str(), channelNames[4].c_str(), &trackbarUpperInitValue, 255, onSaturationUpperTrackbar);
    cvCreateTrackbar(upperTrackbarNames[5].c_str(), channelNames[5].c_str(), &trackbarUpperInitValue, 255, onValueUpperTrackbar);
    cvCreateTrackbar(upperTrackbarNames[6].c_str(), channelNames[6].c_str(), &trackbarUpperInitValue, 255, onYUpperTrackbar);
    cvCreateTrackbar(upperTrackbarNames[7].c_str(), channelNames[7].c_str(), &trackbarUpperInitValue, 255, onCrUpperTrackbar);
    cvCreateTrackbar(upperTrackbarNames[8].c_str(), channelNames[8].c_str(), &trackbarUpperInitValue, 255, onCbUpperTrackbar);
    cvCreateTrackbar(underTrackbarNames[0].c_str(), channelNames[0].c_str(), &trackbarUnderInitValue, 255, onBlueUnderTrackbar);
    cvCreateTrackbar(underTrackbarNames[1].c_str(), channelNames[1].c_str(), &trackbarUnderInitValue, 255, onGreenUnderTrackbar);
    cvCreateTrackbar(underTrackbarNames[2].c_str(), channelNames[2].c_str(), &trackbarUnderInitValue, 255, onRedUnderTrackbar);
    cvCreateTrackbar(underTrackbarNames[3].c_str(), channelNames[3].c_str(), &trackbarUnderInitValue, 255, onHueUnderTrackbar);
    cvCreateTrackbar(underTrackbarNames[4].c_str(), channelNames[4].c_str(), &trackbarUnderInitValue, 255, onSaturationUnderTrackbar);
    cvCreateTrackbar(underTrackbarNames[5].c_str(), channelNames[5].c_str(), &trackbarUnderInitValue, 255, onValueUnderTrackbar);
    cvCreateTrackbar(underTrackbarNames[6].c_str(), channelNames[6].c_str(), &trackbarUnderInitValue, 255, onYUnderTrackbar);
    cvCreateTrackbar(underTrackbarNames[7].c_str(), channelNames[7].c_str(), &trackbarUnderInitValue, 255, onCrUnderTrackbar);
    cvCreateTrackbar(underTrackbarNames[8].c_str(), channelNames[8].c_str(), &trackbarUnderInitValue, 255, onCbUnderTrackbar);

    cvSetTrackbarPos(upperTrackbarNames[0].c_str(), channelNames[0].c_str(), 60 );
    cvSetTrackbarPos(upperTrackbarNames[1].c_str(), channelNames[1].c_str(), 60 );
    cvSetTrackbarPos(upperTrackbarNames[2].c_str(), channelNames[2].c_str(), 60 );
    cvSetTrackbarPos(upperTrackbarNames[3].c_str(), channelNames[3].c_str(), 60 );
    cvSetTrackbarPos(upperTrackbarNames[4].c_str(), channelNames[4].c_str(), 60 );
    cvSetTrackbarPos(upperTrackbarNames[5].c_str(), channelNames[5].c_str(), 60 );
    cvSetTrackbarPos(upperTrackbarNames[6].c_str(), channelNames[6].c_str(), 60 );
    cvSetTrackbarPos(upperTrackbarNames[7].c_str(), channelNames[7].c_str(), 60 );
    cvSetTrackbarPos(upperTrackbarNames[8].c_str(), channelNames[8].c_str(), 60 );
    cvSetTrackbarPos(underTrackbarNames[0].c_str(), channelNames[0].c_str(), 30 );
    cvSetTrackbarPos(underTrackbarNames[1].c_str(), channelNames[1].c_str(), 30 );
    cvSetTrackbarPos(underTrackbarNames[2].c_str(), channelNames[2].c_str(), 30 );
    cvSetTrackbarPos(underTrackbarNames[3].c_str(), channelNames[3].c_str(), 30 );
    cvSetTrackbarPos(underTrackbarNames[4].c_str(), channelNames[4].c_str(), 30 );
    cvSetTrackbarPos(underTrackbarNames[5].c_str(), channelNames[5].c_str(), 30 );
    cvSetTrackbarPos(underTrackbarNames[6].c_str(), channelNames[6].c_str(), 30 );
    cvSetTrackbarPos(underTrackbarNames[7].c_str(), channelNames[7].c_str(), 30 );
    cvSetTrackbarPos(underTrackbarNames[8].c_str(), channelNames[8].c_str(), 30 );


    _isShowing = true;
    while(_isShowing) {
        srcBGRImg = _cameraManager.getFrame();
        imshow("src", srcBGRImg);
        boxFilter(srcBGRImg, srcBGRImg, 8, Size(3,3));
    
        cvtColor(srcBGRImg, srcHSVImg, CV_BGR2HSV);
        cvtColor(srcBGRImg, srcYCrCbImg, CV_BGR2YCrCb);

        split(srcBGRImg, bgrChannelImgs);
        split(srcHSVImg, hsvChannelImgs);
        split(srcYCrCbImg, ycrcbChannelImgs);

      
        Canny(bgrChannelImgs[0], bgrChannelImgs[0], cannyViewerUpperThreshold[0], cannyViewerUnderThreshold[0],  APERTURE_SIZE, L2_GRADIENT);
        Canny(bgrChannelImgs[1], bgrChannelImgs[1], cannyViewerUpperThreshold[1], cannyViewerUnderThreshold[1],  APERTURE_SIZE, L2_GRADIENT);
        Canny(bgrChannelImgs[2], bgrChannelImgs[2], cannyViewerUpperThreshold[2], cannyViewerUnderThreshold[2],  APERTURE_SIZE, L2_GRADIENT);
        Canny(hsvChannelImgs[0], hsvChannelImgs[0], cannyViewerUpperThreshold[3], cannyViewerUnderThreshold[3],  APERTURE_SIZE, L2_GRADIENT);
        Canny(hsvChannelImgs[1], hsvChannelImgs[1], cannyViewerUpperThreshold[4], cannyViewerUnderThreshold[4],  APERTURE_SIZE, L2_GRADIENT);
        Canny(hsvChannelImgs[2], hsvChannelImgs[2], cannyViewerUpperThreshold[5], cannyViewerUnderThreshold[5],  APERTURE_SIZE, L2_GRADIENT);
        Canny(ycrcbChannelImgs[0], ycrcbChannelImgs[0], cannyViewerUpperThreshold[6], cannyViewerUnderThreshold[6],  APERTURE_SIZE, L2_GRADIENT);
        Canny(ycrcbChannelImgs[1], ycrcbChannelImgs[1], cannyViewerUpperThreshold[7], cannyViewerUnderThreshold[7],  APERTURE_SIZE, L2_GRADIENT);
        Canny(ycrcbChannelImgs[2], ycrcbChannelImgs[2], cannyViewerUpperThreshold[8], cannyViewerUnderThreshold[8],  APERTURE_SIZE, L2_GRADIENT);

        imshow(channelNames[0], bgrChannelImgs[0]);
        imshow(channelNames[1], bgrChannelImgs[1]);
        imshow(channelNames[2], bgrChannelImgs[2]);
        imshow(channelNames[3], hsvChannelImgs[0]);
        imshow(channelNames[4], hsvChannelImgs[1]);
        imshow(channelNames[5], hsvChannelImgs[2]);
        imshow(channelNames[6], ycrcbChannelImgs[0]);
        imshow(channelNames[7], ycrcbChannelImgs[1]);
        imshow(channelNames[8], ycrcbChannelImgs[2]);

        int key = waitKey(33);
        if(key == 27) break;
    }

    destroyAllWindows();
}

void CannyViewer::closeCannyImgs() {
    _isShowing = false;
}