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

    _edgeWidgetChannelMap.insert(make_pair(0, JU_S));
    _edgeWidgetChannelMap.insert(make_pair(1, JU_Cr));
    _edgeWidgetChannelMap.insert(make_pair(2, JU_V));
    //ui->ch0EdgeThreshold_groupBox->setTitle
    
}

MainWindow::~MainWindow() {

    delete ui;

}

/**
    * ホームタブ
    */
void MainWindow::on_startPushButton_clicked()
{
    mainController.start();
}

void MainWindow::on_stopPushButton_clicked()
{
    mainController.stop();
}

void MainWindow::on_CalibrateButton_clicked()
{

    CalibrateDialog* calibrateDialog = new CalibrateDialog();
  	calibrateDialog->QWidget::show();

}

void MainWindow::on_colorMapButton_clicked()
{

	ColorDialog* colorDialog = new ColorDialog();
	colorDialog->QWidget::show();
}


void MainWindow::on_plot3DPushButton_clicked()
{
// // Instantiate the viewer.
//   BGR3DPlotController bgr3DPlotController;

  _bgr3DPlotController.setWindowTitle("simpleViewer");

  // Make the viewer window visible on screen.
  _bgr3DPlotController.show();

}


//alpha
void MainWindow::on_alphaLineEdit_textChanged(const QString &arg1)
{
    double alpha = arg1.toDouble(); // TODO ：ユーザーが整数以外を入力した場合の処理を書くべし
    ui->alphaSlider->setSliderPosition(alpha*100);
    _convertController.updateAlpha(alpha);
}
void MainWindow::on_alphaSlider_valueChanged(int value)
{
    double alpha = (double)value/100.0;
    ui->alphaLineEdit->setText(QString::number(alpha));
    _convertController.updateAlpha(alpha);
}

void MainWindow::on_hueLineEdit_textChanged(const QString &arg1)
{

}

void MainWindow::on_hueSlider_valueChanged(int value)
{

}

void MainWindow::on_saturationLineEdit_textChanged(const QString &arg1)
{

}

void MainWindow::on_saturationSlider_valueChanged(int value)
{

}

void MainWindow::on_valueLineEdit_textChanged(const QString &arg1)
{

}

void MainWindow::on_valueSlider_valueChanged(int value)
{

}
//テクスチャ切り替え
void MainWindow::on_textureComboBox_currentIndexChanged(const QString &arg1) {
    if(arg1.contains(".")) {
        QString path = DIRPATH;
        path.append(arg1);
        QByteArray cStr = path.toLocal8Bit();
        _textureController.changeTextureImg(cStr.data());
    } else {
        String dirPath = DIRPATH;
        String cStr = dirPath.append("NoTexture");
       _textureController.changeTextureImg(cStr);
    }
}

//フルクリーン
void MainWindow::on_fullScreenPushButton_toggled(bool checked)
{
    if(checked) {
        _windowController.fullScreen();
    } else {
        _windowController.unFullScreen();
    }
}
//ショートカットセッティング
void MainWindow::on_maguroRadioButton_clicked()
{
    _convertController.setUpForMaguro();
}

void MainWindow::on_coffeeRadioButton_clicked(bool checked)
{
    _convertController.setUpForCoffee();
}

/**
* 画面サイズタブ
*/
void MainWindow::on_radioButton_captureSizeLarge_clicked() {
	//srcController.setVCaptureSize(SIZE_LARGE);
}

void MainWindow::on_radioButton_captureSizeSmall_clicked() {
	//srcController.setVCaptureSize(SIZE_SMALL);
}

void MainWindow::on_radioButton_dstSizeSmall_clicked() {
	// if(ui->radioButton_captureSizeSmall->isChecked()) {
	// 	mainController.setResizeFlag(false);
	// } else {
	// 	mainController.setResizeFlag(true);
	// 	mainController.setDstSize(SIZE_SMALL);
	// }
}

void MainWindow::on_radioButton_dstSizeLarge_clicked() {
	// if(ui->radioButton_captureSizeSmall->isChecked()){
	// 	mainController.setResizeFlag(true);
	// 	mainController.setDstSize(SIZE_LARGE);
	// } else {
	// 	mainController.setResizeFlag(false);
	// }
}



void MainWindow::on_illuminationSlider_valueChanged(int value) {
	//convertController.changeIntensityParam(true, value);
}

void MainWindow::on_horizontalSlider_valueChanged(int value) {
	//convertController.changeZParam(true, value);
}

/**
* 抽出タブ
*/

/**色領域抽出時使用チャンネルボックスのイベントハンドラ*/
vector<ChannelType> MainWindow::collectColorCheckBoxStatus() {
	vector<ChannelType> channelList;
	if(ui->colorBlueCheckBox->isChecked()) channelList.push_back(ChannelType::blue);
	if(ui->colorGreenCheckBox->isChecked()) channelList.push_back(ChannelType::green);
	if(ui->colorRedCheckBox->isChecked()) channelList.push_back(ChannelType::red);
	if(ui->colorHueCheckBox->isChecked()) channelList.push_back(ChannelType::hue);
	if(ui->colorSaturationCheckBox->isChecked()) channelList.push_back(ChannelType::saturation);
	if(ui->colorValueCheckBox->isChecked()) channelList.push_back(ChannelType::value);
	if(ui->colorYCheckBox->isChecked()) channelList.push_back(ChannelType::y);
	if(ui->colorCrCheckBox->isChecked()) channelList.push_back(ChannelType::cr);
	if(ui->colorCbCheckBox->isChecked()) channelList.push_back(ChannelType::cb);
    return channelList;
}

void MainWindow::on_colorBlueCheckBox_clicked()
{
   _extractionController.updateEngagedColorChannels(collectColorCheckBoxStatus());
}

void MainWindow::on_colorGreenCheckBox_clicked()
{
    _extractionController.updateEngagedColorChannels(collectColorCheckBoxStatus());
}

void MainWindow::on_colorRedCheckBox_clicked()
{
    _extractionController.updateEngagedColorChannels(collectColorCheckBoxStatus());
}

void MainWindow::on_colorHueCheckBox_clicked()
{
    _extractionController.updateEngagedColorChannels(collectColorCheckBoxStatus());
}

void MainWindow::on_colorSaturationCheckBox_clicked()
{
    _extractionController.updateEngagedColorChannels(collectColorCheckBoxStatus());
}

void MainWindow::on_colorValueCheckBox_clicked()
{
    _extractionController.updateEngagedColorChannels(collectColorCheckBoxStatus());
}

void MainWindow::on_colorYCheckBox_clicked()
{
    _extractionController.updateEngagedColorChannels(collectColorCheckBoxStatus());
}

void MainWindow::on_colorCrCheckBox_clicked()
{
    _extractionController.updateEngagedColorChannels(collectColorCheckBoxStatus());
}

void MainWindow::on_colorCbCheckBox_clicked()
{
    _extractionController.updateEngagedColorChannels(collectColorCheckBoxStatus());
}


/**エッジ抽出時使用チャンネルボックスのイベントハンドラ*/
vector<ChannelType> MainWindow::collectEdgeChannelCheckBoxStatus() {
    vector<ChannelType> channelList;
    if(ui->edgeBlueCheckBox->isChecked()) channelList.push_back(ChannelType::blue);
    if(ui->edgeGreenCheckBox->isChecked()) channelList.push_back(ChannelType::green);
    if(ui->edgeRedCheckBox->isChecked()) channelList.push_back(ChannelType::red);
    if(ui->edgeHueCheckBox->isChecked()) channelList.push_back(ChannelType::hue);
    if(ui->edgeSaturationCheckBox->isChecked()) channelList.push_back(ChannelType::saturation);
    if(ui->edgeValueCheckBox->isChecked()) channelList.push_back(ChannelType::value);
    if(ui->edgeYCheckBox->isChecked()) channelList.push_back(ChannelType::y);
    if(ui->edgeCrCheckBox->isChecked()) channelList.push_back(ChannelType::cr);
    if(ui->edgeCbCheckBox->isChecked()) channelList.push_back(ChannelType::cb);
    return channelList;
}
void MainWindow::on_edgeBlueCheckBox_clicked()
{
    _extractionController.updateEngagedEdgeChannels(collectEdgeChannelCheckBoxStatus());
}

void MainWindow::on_edgeGreenCheckBox_clicked()
{
    _extractionController.updateEngagedEdgeChannels(collectEdgeChannelCheckBoxStatus());
}

void MainWindow::on_edgeRedCheckBox_clicked()
{
    _extractionController.updateEngagedEdgeChannels(collectEdgeChannelCheckBoxStatus());
}

void MainWindow::on_edgeHueCheckBox_clicked()
{
    _extractionController.updateEngagedEdgeChannels(collectEdgeChannelCheckBoxStatus());
}

void MainWindow::on_edgeSaturationCheckBox_clicked()
{
    _extractionController.updateEngagedEdgeChannels(collectEdgeChannelCheckBoxStatus());
}

void MainWindow::on_edgeValueCheckBox_clicked()
{
    _extractionController.updateEngagedEdgeChannels(collectEdgeChannelCheckBoxStatus());
}

void MainWindow::on_edgeYCheckBox_clicked()
{
    _extractionController.updateEngagedEdgeChannels(collectEdgeChannelCheckBoxStatus());
}

void MainWindow::on_edgeCrCheckBox_clicked()
{
    _extractionController.updateEngagedEdgeChannels(collectEdgeChannelCheckBoxStatus());
}

void MainWindow::on_edgeCbCheckBox_clicked()
{
    _extractionController.updateEngagedEdgeChannels(collectEdgeChannelCheckBoxStatus());
}

void MainWindow::on_channelMatPushButton_toggled(bool checked)
{
    if(checked) {
        mainController.showChannelMat();
    } else {
        mainController.closeChannelMat();
    }
}
void MainWindow::on_binarizedMatPushButton_toggled(bool checked)
{
    if(checked) {
        mainController.showBinarizationImgs();
    } else {
        mainController.closeBinarizationImgs();
    }
}
void MainWindow::on_cannyEdgeMatPushButton_toggled(bool checked)
{
    if(checked) {
        mainController.showCannyImgs();
    } else {
        mainController.closeCannyImgs();
    }
}


 /**
 * チャンネル閾値強度調整
 * TODO : indexを識別する機能を追加すべし
 */
void MainWindow::on_channelThresholdHorizontalSlider_valueChanged(int value)
{
    int degree = value;
    ChannelType type = aqcuireChannelType(ui->channelThresholdComboBox->currentIndex() );
    int index = 0;
    _extractionController.updateChannelThresholdValue(degree,type,index);
    ui->channelThresholdLineEdit->setText(QString::number(value));
}

void MainWindow::on_channelThresholdLineEdit_textChanged(const QString &arg1)
{
    int degree = arg1.toInt(); // TODO ：ユーザーが整数以外を入力した場合の処理を書くべし
    ChannelType type = aqcuireChannelType(ui->channelThresholdComboBox->currentIndex() );
    int index = 0;
    _extractionController.updateChannelThresholdValue(degree, type, index);
    ui->channelThresholdHorizontalSlider->setSliderPosition(arg1.toInt());
}

void MainWindow::on_channelThresholdComboBox_currentIndexChanged(int index)
{
    int degree = _extractionController.channelThresholdComboBox_currentIndexChanged(aqcuireChannelType(index));
    ui->channelThresholdLineEdit->setText(QString::number(degree));
    ui->channelThresholdHorizontalSlider->setSliderPosition(degree);
}

//TODO comboBoxのリストの順番が変わったら成り立たなくなるので別の方法を考えるべし
ChannelType MainWindow::aqcuireChannelType(int channelNumber) {
    switch(channelNumber) {
        case 0:
            return ChannelType::blue;
        case 1:
            return ChannelType::green;
        case 2:
            return ChannelType::red;
        case 3:
            return ChannelType::hue;
        case 4:
            return ChannelType::saturation;
        case 5:
            return ChannelType::value;
        case 6:
            return ChannelType::y;
        case 7:
            return ChannelType::cr;
        case 8:
            return ChannelType::cb;

    }
}

/**モルフォロジー変換*/
void MainWindow::on_dilateSpinBox_valueChanged(int arg1)
{
    _extractionController.updateDilateCount(arg1);
}

void MainWindow::on_erodeSpinBox_valueChanged(int arg1)
{
    _extractionController.updateErodeCount(arg1);
}

/** 二値化閾値調整*/
void MainWindow::on_blueBinarizationThresholdLineEdit_textChanged(const QString &arg1)
{
    int value = arg1.toInt(); // TODO ：ユーザーが数以外を入力した場合の処理を書くべし
    _extractionController.updateBinarizationThreshold(value, 0);
    ui->blueBinarizationThresholdSlider->setSliderPosition(value);
}

void MainWindow::on_blueBinarizationThresholdSlider_valueChanged(int value)
{
    _extractionController.updateBinarizationThreshold(value, 0);
    ui->blueBinarizationThresholdLineEdit->setText(QString::number(value));
}

void MainWindow::on_greenBinarizationThresholdLineEdit_textChanged(const QString &arg1)
{
    int value = arg1.toInt(); // TODO ：ユーザーが数以外を入力した場合の処理を書くべし
    _extractionController.updateBinarizationThreshold(value, 1);
    ui->greenBinarizationThresholdSlider->setSliderPosition(value);
}

void MainWindow::on_greenBinarizationThresholdSlider_valueChanged(int value)
{
    _extractionController.updateBinarizationThreshold(value, 1);
    ui->greenBinarizationThresholdLineEdit->setText(QString::number(value));
}

void MainWindow::on_redBinarizationThresholdLineEdit_textChanged(const QString &arg1)
{
    int value = arg1.toInt(); // TODO ：ユーザーが数以外を入力した場合の処理を書くべし
    _extractionController.updateBinarizationThreshold(value, 2);
    ui->redBinarizationThresholdSlider->setSliderPosition(value);
}

void MainWindow::on_redBinarizationThresholdSlider_valueChanged(int value)
{
    _extractionController.updateBinarizationThreshold(value, 2);
    ui->redBinarizationThresholdLineEdit->setText(QString::number(value));
}
void MainWindow::on_hueBinarizationThresholdLineEdit_textChanged(const QString &arg1)
{
     _extractionController.updateBinarizationThreshold(value, 3);
    ui->hueBinarizationThresholdLineEdit->setText(QString::number(value));
}

void MainWindow::on_hueBinarizationThresholdSlider_valueChanged(int value)
{
     _extractionController.updateBinarizationThreshold(value, 3);
    ui->hueBinarizationThresholdLineEdit->setText(QString::number(value));
}

void MainWindow::on_saturationBinarizationThresholdLineEdit_textChanged(const QString &arg1)
{
     _extractionController.updateBinarizationThreshold(value, 4);
    ui->saturationBinarizationThresholdLineEdit->setText(QString::number(value));
}

void MainWindow::on_saturationBinarizationThresholdSlider_valueChanged(int value)
{
     _extractionController.updateBinarizationThreshold(value, 4);
    ui->saturationBinarizationThresholdLineEdit->setText(QString::number(value));
}

void MainWindow::on_valueBinarizationThresholdLineEdit_textChanged(const QString &arg1)
{
     _extractionController.updateBinarizationThreshold(value, 5);
    ui->valueBinarizationThresholdLineEdit->setText(QString::number(value));
}   

void MainWindow::on_valueBinarizationThresholdSlider_valueChanged(int value)
{
     _extractionController.updateBinarizationThreshold(value, 5);
    ui->valueBinarizationThresholdLineEdit->setText(QString::number(value));
}

void MainWindow::on_yBinarizationThresholdLineEdit_textChanged(const QString &arg1)
{
    int value = arg1.toInt(); // TODO ：ユーザーが数以外を入力した場合の処理を書くべし
    _extractionController.updateBinarizationThreshold(value, 6);
    ui->yBinarizationThresholdSlider->setSliderPosition(value);
}

void MainWindow::on_yBinarizationThresholdSlider_valueChanged(int value)
{
    _extractionController.updateBinarizationThreshold(value, 6);
    ui->yBinarizationThresholdLineEdit->setText(QString::number(value));
}

void MainWindow::on_crBinarizationThresholdLineEdit_textChanged(const QString &arg1)
{
    int value = arg1.toInt(); // TODO ：ユーザーが数以外を入力した場合の処理を書くべし
    _extractionController.updateBinarizationThreshold(value, 7);
    ui->crBinarizationThresholdSlider->setSliderPosition(value);
}

void MainWindow::on_crBinarizationThresholdSlider_valueChanged(int value)
{
    _extractionController.updateBinarizationThreshold(value, 7);
    ui->crBinarizationThresholdLineEdit->setText(QString::number(value));
}

void MainWindow::on_cbBinarizationThresholdLineEdit_textChanged(const QString &arg1)
{
     _extractionController.updateBinarizationThreshold(value, 8);
    ui->cbBinarizationThresholdLineEdit->setText(QString::number(value));
}

void MainWindow::on_cbBinarizationThresholdSlider_valueChanged(int value)
{
     _extractionController.updateBinarizationThreshold(value, 8);
    ui->cbBinarizationThresholdLineEdit->setText(QString::number(value));
}













void MainWindow::on_underRatioLineEdit_textChanged(const QString &arg1)
{
    double underRatio = arg1.toDouble(); // TODO ：ユーザーが整数以外を入力した場合の処理を書くべし
    double upperRatio = ui->upperRatioLineEdit->text().toDouble();
    _extractionController.updateRatioOfPixelNum(upperRatio, underRatio);
    ui->underRatioSlider->setSliderPosition((int)(underRatio*100));
}

void MainWindow::on_underRatioSlider_valueChanged(int value)
{
    double underRatio = (double)((double)value/100.0);
    double upperRatio = ui->upperRatioLineEdit->text().toDouble();
    _extractionController.updateRatioOfPixelNum(upperRatio, underRatio);
    ui->underRatioLineEdit->setText(QString::number(underRatio));
}

void MainWindow::on_upperRatioLineEdit_textChanged(const QString &arg1)
{
    double upperRatio = arg1.toDouble(); // TODO ：ユーザーが整数以外を入力した場合の処理を書くべし
    double underRatio = ui->upperRatioLineEdit->text().toDouble();
    _extractionController.updateRatioOfPixelNum(upperRatio, underRatio);
    ui->upperRatioSlider->setSliderPosition((int)(upperRatio*100));
}

void MainWindow::on_upperRatioSlider_valueChanged(int value)
{
    double upperRatio = (double)((double)value/100.0);
    double underRatio = ui->underRatioLineEdit->text().toDouble();
    _extractionController.updateRatioOfPixelNum(upperRatio, underRatio);
    ui->upperRatioLineEdit->setText(QString::number(upperRatio));
}



/**
* カメラタブ
*/
void MainWindow::on_captureSaturationSlider_valueChanged(int value)
{
     ui->captureSaturationLineEdit->setText(QString::number(value));
     _cameraController.setCaptureSaturation((double)value);
}

void MainWindow::on_captureSaturationLineEdit_textChanged(const QString &arg1)
{
    ui->captureSaturationSlider->setSliderPosition(arg1.toInt());
    _cameraController.setCaptureSaturation(arg1.toDouble());
}

void MainWindow::on_captureExposureSlider_valueChanged(int value)
{
    ui->captureExposureLineEdit->setText(QString::number(value));
     _cameraController.setCaptureExposure((double)value);
}

void MainWindow::on_captureExposureLineEdit_textChanged(const QString &arg1)
{
    ui->captureExposureSlider->setSliderPosition(arg1.toInt());
    _cameraController.setCaptureExposure(arg1.toDouble());
}

void MainWindow::on_captureGainSlider_valueChanged(int value)
{
	ui->captureGaineLineEdit->setText(QString::number(value));
     _cameraController.setCaptureGain((double)value);
}

void MainWindow::on_captureGaineLineEdit_textChanged(const QString &arg1)
{
     ui->captureGainSlider->setSliderPosition(arg1.toInt());
    _cameraController.setCaptureGain(arg1.toDouble());
}

void MainWindow::on_captureBrightnessSlider_valueChanged(int value)
{
    ui->captureBrightnessLineEdit->setText(QString::number(value));
     _cameraController.setCaptureBrightness((double)value);
}

void MainWindow::on_captureBrightnessLineEdit_textChanged(const QString &arg1)
{
     ui->captureBrightnessSlider->setSliderPosition(arg1.toInt());
    _cameraController.setCaptureBrightness(arg1.toDouble());
}

void MainWindow::on_captureContrastSlider_valueChanged(int value)
{
     ui->captureContrastLineEdit->setText(QString::number(value));
     _cameraController.setCaptureContrast((double)value);
}

void MainWindow::on_captureContrastLineEdit_textChanged(const QString &arg1)
{
    ui->captureContrastSlider->setSliderPosition(arg1.toInt());
    _cameraController.setCaptureContrast(arg1.toDouble());
}
 


