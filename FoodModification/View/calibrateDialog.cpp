#include "calibrateDialog.h"
#include "ui_calibrateDialog.h"

CalibrateDialog::CalibrateDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CalibrateDialog)
{
    ui->setupUi(this);
}

CalibrateDialog::~CalibrateDialog()
{
    delete ui;
}

void CalibrateDialog::on_videoInputButton_clicked()
{
    calibrationController->videoInput();
}

void CalibrateDialog::on_captureButton_clicked()
{
    calibrationController->capture();
}

void CalibrateDialog::on_calculateButton_clicked()
{
    calibrationController->stopDrawing();
}
