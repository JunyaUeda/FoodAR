#include "calibrateDialog.h"
#include "ui_calibrateDialog.h"
#include <QImage>
#include <QMouseEvent>

CalibrateDialog::CalibrateDialog(QWidget *parent) :
    QDialog(parent), 
    ui(new Ui::CalibrateDialog)
{

	clickParam = new CalibrateClickParam;
    // Size captureSize = _calibrationController.captureSize();
    // videoCapture.set(CV_CAP_PROP_FRAME_WIDTH, captureSize.width);
    // videoCapture.set(CV_CAP_PROP_FRAME_HEIGHT, captureSize.height);
    ui->setupUi(this);
    
    timerId = startTimer(33);

}

CalibrateDialog::~CalibrateDialog() {

    delete ui;

}

void CalibrateDialog::show(Mat img) {

    Mat RGBImg;
    cvtColor(img, RGBImg, CV_BGR2RGB);
    QImage image(RGBImg.data, RGBImg.cols, RGBImg.rows, QImage::Format_RGB888);
    ui->label_2->setPixmap(QPixmap::fromImage(image));

}

void CalibrateDialog::on_captureButton_clicked() {

    if(captureStatus) {
        clickParam->setImgsByBGRImg(srcBGRImg);
        killTimer(timerId);
        captureStatus = false;
        ui->captureButton->setText("START");
    } else {
        timerId = startTimer(33);
        captureStatus = true;
        ui->captureButton->setText("STOP");
    }
    
}

/**
*startTimer()によって呼ばれるtimerEvent.
*@note QObjectの持っているtimerのtimerEvent。startTimer(33)とすれば、自分のメンバメソッドのtimerEventが呼ばれる
*/
void CalibrateDialog::timerEvent(QTimerEvent *event) {

    event->timerId();//for warning unused
    srcBGRImg = _cameraManager.getFrame();
    show(srcBGRImg);

}

/**
*マウスクリックによって呼ばれるEvent.
*/
void CalibrateDialog::mousePressEvent(QMouseEvent* event) {

    if(captureStatus) {
        return;
    }

	QPoint clickedPoint = event->pos();
	Point* pts;
	switch(event->button()) {

	    case Qt::LeftButton:
	        clickParam->leftClickedCounts++;
            clickParam->clickedPoints[0].push_back(Point(clickedPoint.x(),clickedPoint.y()));
            pts = &clickParam->clickedPoints[0][0];
            fillConvexPoly(clickParam->refImg, pts, clickParam->leftClickedCounts, Scalar(0,0,255));
	    	break;

	    case Qt::RightButton:
	    	clickParam->rightClickedCounts++;
            clickParam->clickedPoints[1].push_back(Point(clickedPoint.x(),clickedPoint.y()));
            pts = &clickParam->clickedPoints[1][0];
            fillConvexPoly(clickParam->refImg, pts, clickParam->rightClickedCounts, Scalar(0,255,0));
	    	break;
        default:
            break;
    }

    show(clickParam->refImg);

}

void CalibrateDialog::on_buttonBox_accepted() {

    if(!captureStatus) {
        _calibrationController.calibrate(clickParam);
    }
    
}

void CalibrateDialog::on_buttonBox_rejected() {

}

void CalibrateDialog::on_resetButton_clicked() {

    clickParam->refImg = clickParam->srcBGRImg.clone();
    clickParam->clickedPoints.clear();
    clickParam->leftClickedCounts = 0;
    clickParam->rightClickedCounts = 0;
    vector<vector<Point> > points(2);
    clickParam->clickedPoints = points;
    show(clickParam->refImg);
    
}
