#ifndef CALIBRATEDIALOG_H
#define CALIBRATEDIALOG_H

#include <QDialog>
#include "../Controller/calibrationController.h"

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
private slots: 
    void on_videoInputButton_clicked();
    void on_captureButton_clicked();
    void on_calculateButton_clicked();
};

#endif // CALIBRATEDIALOG_H
