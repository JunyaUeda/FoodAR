#include "mainWindow.h"
#include "ui_mainWindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //ui->alphaValueLabel->setText(QString::number(alpha));

}

MainWindow::~MainWindow() {

    delete ui;

}

void MainWindow::on_convertButton_clicked() {

    mainController.doConvertion();

}


void MainWindow::on_CalibrateButton_clicked() {

    CalibrateDialog* calibrateDialog = new CalibrateDialog();
  	calibrateDialog->QWidget::show();

}

void MainWindow::on_colorMapButton_clicked() {

	ColorDialog* colorDialog = new ColorDialog();
	colorDialog->QWidget::show();
}

void MainWindow::on_alphaSlider_actionTriggered(int action)
{
	int value = ui->alphaSlider->value();
	double alpha = (double)value/100.0;
	ui->alphaValueLabel->setText(QString::number(alpha));
	convertController.setAlpha(alpha);
}

void MainWindow::on_radioButton_captureSizeLarge_clicked()
{

}
