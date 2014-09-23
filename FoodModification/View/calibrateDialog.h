#ifndef CALIBRATEDIALOG_H
#define CALIBRATEDIALOG_H

#include <QDialog>
#include "../Controller/calibrationController.h"
#include "../Utils/opencvBase.h"
#include "../Param/calibrateClickParam.h"

namespace Ui {
class CalibrateDialog;
}

class CalibrateDialog : public QDialog
{
    Q_OBJECT

public:
    explicit CalibrateDialog(QWidget *parent = 0);
    ~CalibrateDialog();

    CalibrationController* calibrationController;

private:
    Ui::CalibrateDialog *ui;
    VideoCapture videoCapture;
    Mat srcBGRImg, srcRGBImg, srcHSVImg;
    int timerId;
    CalibrateClickParam* clickParam;

private slots: 
    void on_videoInputButton_clicked();
    void on_captureButton_clicked();
    void on_calculateButton_clicked();
    void timerEvent(QTimerEvent *evennt);
    void mousePressEvent(QMouseEvent *event);
};

#endif // CALIBRATEDIALOG_H
