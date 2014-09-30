#include "colorDialog.h"
#include "ui_colorDialog.h"

ColorDialog::ColorDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ColorDialog)
{
    ui->setupUi(this);
    Mat colorMapImg(180, 256, CV_8UC3);
    cvtColor(colorMapImg, colorMapImg, CV_BGR2HSV);
    for(int y=0; y<colorMapImg.rows; y++) {
    	for(int x=0; x<colorMapImg.cols; x++) {
    		H(colorMapImg,x,y) = x;
    		S(colorMapImg,x,y) = 255-y;
    		V(colorMapImg,x,y) = 200;
    	}
    }
    cvtColor(colorMapImg, colorMapImg, CV_HSV2RGB);
    Mat resizeImg(360, 512, CV_8UC3);
    cv::resize(colorMapImg, resizeImg, resizeImg.size(), 0, 0, INTER_NEAREST);
    QImage image(resizeImg.data, resizeImg.cols, resizeImg.rows, QImage::Format_RGB888);
    ui->colorMapLabel->setPixmap(QPixmap::fromImage(image));
}

ColorDialog::~ColorDialog()
{
    delete ui;
}

void ColorDialog::on_hShiftSlider_actionTriggered(int action) {

	int value = ui->hShiftSlider->value();
	ui->hShiftLabel->setText(QString::number(value));
	const int HUE = 0;
	mainController.changeShiftValue(value, HUE);

}

void ColorDialog::on_sShiftSlider_actionTriggered(int action) {

	int value = ui->sShiftSlider->value();
	ui->sShiftLabel->setText(QString::number(value));
	const int SATURATION = 1;
	mainController.changeShiftValue(value, SATURATION);

}

void ColorDialog::on_vShiftSlider_actionTriggered(int action) {

	int value = ui->vShiftSlider->value();
	ui->vShiftLabel->setText(QString::number(value));
	const int VALUE = 2;
	mainController.changeShiftValue(value, VALUE);

}


