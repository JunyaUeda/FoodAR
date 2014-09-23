#include "mainWindow.h"
#include "ui_mainWindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_convertButton_clicked()
{
    mainController->doConvertion();
}


void MainWindow::on_CalibrateButton_clicked()
{
	//calibrationController->calibrate();
	CalibrateDialog* calibrateDialog = new CalibrateDialog();
  	calibrateDialog->calibrationController = this->calibrationController;
  	calibrateDialog->show();
}
