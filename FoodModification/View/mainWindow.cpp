#include "mainWindow.h"
#include "ui_mainWindow.h"

#define SIZE_SMALL cv::Size(640, 480)
#define SIZE_LARGE cv::Size(1280, 720)

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    
    QString path = DIRPATH;
    QDir textureDirectory(path);
    QStringList fileList;
    if(textureDirectory.exists()) {
    	fileList = textureDirectory.entryList();
    }
    for(QString s : fileList) {
    	if(s == "." || s== "..") continue;
    	ui->textureComboBox->addItem(s);
    }
    
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
    mainController.setAlpha(alpha);
}

void MainWindow::on_radioButton_captureSizeLarge_clicked()
{
	mainController.setVCaptureSize(SIZE_LARGE);
}

void MainWindow::on_radioButton_captureSizeSmall_clicked()
{
	mainController.setVCaptureSize(SIZE_SMALL);
}

void MainWindow::on_radioButton_dstSizeSmall_clicked()
{
	if(ui->radioButton_captureSizeSmall->isChecked()) {
		mainController.setResizeFlag(false);
	} else {
		mainController.setResizeFlag(true);
		mainController.setDstSize(SIZE_SMALL);
	}
}

void MainWindow::on_radioButton_dstSizeLarge_clicked()
{
	if(ui->radioButton_captureSizeSmall->isChecked()){
		mainController.setResizeFlag(true);
		mainController.setDstSize(SIZE_LARGE);
	} else {
		mainController.setResizeFlag(false);
	}
	
}

void MainWindow::on_textureComboBox_currentIndexChanged(const QString &arg1)
{
    if(arg1.contains(".")) {
        QString path = DIRPATH;
        path.append(arg1);
        qDebug() << "changed" << path;
		String cStr = path.toLocal8Bit();
		mainController.setPicturePath(cStr);
		mainController.setNoTexture(false);
	} else {
		String cStr = "noTexture";
		mainController.setPicturePath(cStr);
		mainController.setNoTexture(true);
	}
}

void MainWindow::on_illuminationSlider_valueChanged(int value)
{
	convertController.changeIntensityParam(true, value);
}

void MainWindow::on_horizontalSlider_valueChanged(int value)
{
	convertController.changeZParam(true, value);
}
