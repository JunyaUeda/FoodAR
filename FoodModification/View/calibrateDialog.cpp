#include "calibrateDialog.h"
#include "ui_calibrateDialog.h"
#include <QImage>
#include <QMouseEvent>

CalibrateDialog::CalibrateDialog(QWidget *parent) :
    QDialog(parent), 
    ui(new Ui::CalibrateDialog)
{
	this->clickParam = new CalibrateClickParam;
    ui->setupUi(this);
    this->videoCapture = VideoCapture(0);
     //Mat srcBGRImg, srcHSVImg;

    videoCapture >> srcBGRImg;
    cvtColor(srcBGRImg, srcHSVImg, CV_BGR2HSV);
    QImage image(srcBGRImg.data, srcBGRImg.cols, srcBGRImg.rows, QImage::Format_RGB888);
    image = image.rgbSwapped();
    ui->label_2->setPixmap(QPixmap::fromImage(image));

    this->timerId = startTimer(33);

}

CalibrateDialog::~CalibrateDialog() {

    delete ui;

}

void CalibrateDialog::on_videoInputButton_clicked() {

    calibrationController->videoInput();

}

void CalibrateDialog::on_captureButton_clicked() {

    // calibrationController->capture();
    clickParam->img = srcBGRImg.clone();
    killTimer(this->timerId);

}

void CalibrateDialog::on_calculateButton_clicked() {

    calibrationController->stopDrawing();

}

/**
*startTimer()によって呼ばれるtimerEvent.
*@note QObjectの持っているtimerのtimerEvent。startTimer(33)とすれば、自分のメンバメソッドのtimerEventが呼ばれる
*/
void CalibrateDialog::timerEvent(QTimerEvent *event) {

	//Mat srcBGRImg, srcRGBImg, srcHSVImg;
	this->videoCapture >> srcBGRImg;
	cvtColor(srcBGRImg, srcHSVImg, CV_BGR2HSV);
	cvtColor(srcBGRImg, srcRGBImg, CV_BGR2RGB);
    QImage image(srcRGBImg.data, srcRGBImg.cols, srcRGBImg.rows, QImage::Format_RGB888);
    ui->label_2->setPixmap(QPixmap::fromImage(image));

}

/**
*マウスクリックによって呼ばれるEvent.
*/
void CalibrateDialog::mousePressEvent(QMouseEvent* event) {

	QPoint clickedPoint = event->pos();
	qDebug() << "x =" << clickedPoint.x();
	qDebug() << "y =" << clickedPoint.y();

	switch(event->button()) {

	    case Qt::LeftButton:
	        clickParam->leftClickedCounts++;
	        clickParam->clickedPoints[0][clickParam->leftClickedCounts-1] = cv::Point(clickedPoint.x(),clickedPoint.y());
	        cv::fillConvexPoly(clickParam->img, clickParam->clickedPoints[0], clickParam->leftClickedCounts, cv::Scalar(0,0,255));
	    	break;
	    case Qt::RightButton:
	    	clickParam->rightClickedCounts++;
	        clickParam->clickedPoints[1][clickParam->rightClickedCounts-1] = cv::Point(clickedPoint.x(),clickedPoint.y());
	        cv::fillConvexPoly(clickParam->img, clickParam->clickedPoints[1], clickParam->rightClickedCounts, cv::Scalar(0,255,0));
	    	break;

    }

	cvtColor(clickParam->img, clickParam->RGBImg, CV_BGR2RGB);
    QImage image(clickParam->RGBImg.data, clickParam->RGBImg.cols, clickParam->RGBImg.rows, QImage::Format_RGB888);
    ui->label_2->setPixmap(QPixmap::fromImage(image));
}

