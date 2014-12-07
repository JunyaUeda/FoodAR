#ifndef CALIBRATEDIALOG_H
#define CALIBRATEDIALOG_H

#include <QDialog>
#include "../Controller/calibrationController.h"
#include "../Utils/opencvBase.h"
#include "../Param/calibrateClickParam.h"
#include "../Model/Manager/cameraManager.h"

namespace Ui {
class CalibrateDialog;
}

class CalibrateDialog : public QDialog {

    Q_OBJECT

/*method*/
public:
    explicit CalibrateDialog(QWidget *parent = 0);
    ~CalibrateDialog();
private:
    void show(Mat img);
private slots: 
    void on_captureButton_clicked();
    void timerEvent(QTimerEvent *evennt);
    void mousePressEvent(QMouseEvent *event);
    void on_buttonBox_accepted();
    void on_buttonBox_rejected();
    void on_resetButton_clicked();

/*property*/
private:
    Ui::CalibrateDialog *ui;
    CalibrationController& _calibrationController = CalibrationController::getInstance();
    CameraManager& _cameraManager = CameraManager::getInstance();//TODO: controllerをかませる
    Mat srcBGRImg, srcRGBImg, srcHSVImg;
    int timerId;
    bool captureStatus = true;
    CalibrateClickParam* clickParam;
    


};

#endif // CALIBRATEDIALOG_H
