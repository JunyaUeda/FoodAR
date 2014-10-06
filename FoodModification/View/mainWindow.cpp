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

void MainWindow::on_alphaSlider_actionTriggered(int action) {
	int value = ui->alphaSlider->value();
	double alpha = (double)value/100.0;
	ui->alphaValueLabel->setText(QString::number(alpha));
    mainController.setAlpha(alpha);
}

void MainWindow::on_radioButton_captureSizeLarge_clicked() {
	srcController.setVCaptureSize(SIZE_LARGE);
}

void MainWindow::on_radioButton_captureSizeSmall_clicked() {
	srcController.setVCaptureSize(SIZE_SMALL);
}

void MainWindow::on_radioButton_dstSizeSmall_clicked() {
	if(ui->radioButton_captureSizeSmall->isChecked()) {
		mainController.setResizeFlag(false);
	} else {
		mainController.setResizeFlag(true);
		mainController.setDstSize(SIZE_SMALL);
	}
}

void MainWindow::on_radioButton_dstSizeLarge_clicked() {
	if(ui->radioButton_captureSizeSmall->isChecked()){
		mainController.setResizeFlag(true);
		mainController.setDstSize(SIZE_LARGE);
	} else {
		mainController.setResizeFlag(false);
	}
	
}

void MainWindow::on_textureComboBox_currentIndexChanged(const QString &arg1) {
    if(arg1.contains(".")) {
        QString path = DIRPATH;
        path.append(arg1);
        qDebug() << "changed" << path;
		String cStr = path.toLocal8Bit();
		srcController.changeTextureImg(cStr);
		mainController.setNoTexture(false);
	} else {
		String cStr = "noTexture";
		srcController.changeTextureImg(cStr);
		mainController.setNoTexture(true);
	}
}

void MainWindow::on_illuminationSlider_valueChanged(int value) {
	convertController.changeIntensityParam(true, value);
}

void MainWindow::on_horizontalSlider_valueChanged(int value) {
	convertController.changeZParam(true, value);
}

void MainWindow::on_toleranceShiftSlider_0_valueChanged(int value) {
	vector<int> shift = extractParamManager.toleranceShift();
	shift[0] = value;
	extractParamManager.setToleranceShift(shift);
}

void MainWindow::on_toleranceShiftSlider_1_valueChanged(int value) {
	vector<int> shift = extractParamManager.toleranceShift();
	shift[1] = value;
	extractParamManager.setToleranceShift(shift);
}

void MainWindow::on_toleranceShiftSlider_2_valueChanged(int value) {
	vector<int> shift = extractParamManager.toleranceShift();
	shift[2] = value;
	extractParamManager.setToleranceShift(shift);
}

void MainWindow::on_splitColorSpaceComboBox_currentIndexChanged(int index) {
	srcController.changeSplitColorSpace(index);
}


//Edge Event 
void MainWindow::changeThreshold(int channelIndex, int value1, int value2) {
	CannyThreshold* novel = new CannyThreshold(value1, value2);
	edgeController.changeCannyThreshold(channelIndex, novel);
}

void MainWindow::on_ch0EdgeThreshold1_LineEdit_textChanged(const QString &arg1) {
	changeThreshold(0, arg1.toInt(), ui->ch0EdgeThreshold2_Slider->value());
	ui->ch0EdgeThreshold1_Slider->setSliderPosition(arg1.toInt());
}

void MainWindow::on_ch0EdgeThreshold2_LineEdit_textChanged(const QString &arg1) {
	changeThreshold(0, ui->ch0EdgeThreshold1_Slider->value(), arg1.toInt());
	ui->ch0EdgeThreshold2_Slider->setSliderPosition(arg1.toInt());
}

void MainWindow::on_ch1EdgeThreshold1_LineEdit_textChanged(const QString &arg1) {
	changeThreshold(1, arg1.toInt(), ui->ch1EdgeThreshold2_Slider->value());
	ui->ch1EdgeThreshold1_Slider->setSliderPosition(arg1.toInt());
}

void MainWindow::on_ch1EdgeThreshold2_LineEdit_textChanged(const QString &arg1) {
	changeThreshold(1, ui->ch1EdgeThreshold1_Slider->value(), arg1.toInt());
	ui->ch1EdgeThreshold2_Slider->setSliderPosition(arg1.toInt());
}

void MainWindow::on_ch2EdgeThreshold1_LineEdit_textChanged(const QString &arg1) {
	changeThreshold(2, arg1.toInt(), ui->ch2EdgeThreshold2_Slider->value());
	ui->ch2EdgeThreshold1_Slider->setSliderPosition(arg1.toInt());
}

void MainWindow::on_ch2EdgeThreshold2_LineEdit_textChanged(const QString &arg1) {
	changeThreshold(2, ui->ch2EdgeThreshold1_Slider->value(), arg1.toInt());
	ui->ch2EdgeThreshold2_Slider->setSliderPosition(arg1.toInt());
}

void MainWindow::on_ch0EdgeThreshold1_Slider_valueChanged(int value) {
	changeThreshold(0, value, ui->ch0EdgeThreshold2_Slider->value());
	ui->ch0EdgeThreshold1_LineEdit->setText(QString::number(value));
}

void MainWindow::on_ch0EdgeThreshold2_Slider_valueChanged(int value) {
	changeThreshold(0, ui->ch0EdgeThreshold1_Slider->value(),value);
	ui->ch0EdgeThreshold2_LineEdit->setText(QString::number(value));
}

void MainWindow::on_ch1EdgeThreshold1_Slider_valueChanged(int value) {
	changeThreshold(1, value, ui->ch1EdgeThreshold2_Slider->value());
	ui->ch1EdgeThreshold1_LineEdit->setText(QString::number(value));
}

void MainWindow::on_ch1EdgeThreshold2_Slider_valueChanged(int value) {
	changeThreshold(1, ui->ch1EdgeThreshold1_Slider->value(),value);
	ui->ch1EdgeThreshold2_LineEdit->setText(QString::number(value));
}

void MainWindow::on_ch2EdgeThreshold1_Slider_valueChanged(int value) {
	changeThreshold(2, value, ui->ch2EdgeThreshold2_Slider->value());
	ui->ch2EdgeThreshold1_LineEdit->setText(QString::number(value));
}

void MainWindow::on_ch2EdgeThreshold2_Slider_valueChanged(int value) {
	changeThreshold(2, ui->ch2EdgeThreshold1_Slider->value(),value);
	ui->ch2EdgeThreshold2_LineEdit->setText(QString::number(value));
}
