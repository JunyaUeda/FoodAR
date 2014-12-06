#ifndef CALIBRATEDIALOG_H
#define CALIBRATEDIALOG_H

#include <QDialog>
#include "../Controller/calibrationController.h"
#include "../Utils/opencvBase.h"
#include "../Param/calibrateClickParam.h"

namespace Ui {
class CalibrateDialog;
}

class CalibrateDialog : public QDialog {

    Q_OBJECT

public:
    explicit CalibrateDialog(QWidget *parent = 0);
    ~CalibrateDialog();

    

private:
    Ui::CalibrateDialog *ui;
    CalibrationController& _calibrationController = CalibrationController::getInstance();
    VideoCapture videoCapture;
    Mat srcBGRImg, srcRGBImg, srcHSVImg;
    int timerId;
    bool captureStatus = true;
    CalibrateClickParam* clickParam;
    void show(Mat img);

private slots: 
    void on_captureButton_clicked();
    void timerEvent(QTimerEvent *evennt);
    void mousePressEvent(QMouseEvent *event);
    void on_buttonBox_accepted();
    void on_buttonBox_rejected();
    void on_resetButton_clicked();
};

#endif // CALIBRATEDIALOG_H
