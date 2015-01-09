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


