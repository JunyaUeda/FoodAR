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
/*Home Tab*/
void MainWindow::on_startPushButton_clicked()
{
    mainController.start();
}

void MainWindow::on_stopPushButton_clicked()
{
    mainController.stop();
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
// 	int value = ui->alphaSlider->value();
// 	double alpha = (double)value/100.0;
// 	ui->alphaValueLabel->setText(QString::number(alpha));
//     mainController.setAlpha(alpha);
}

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

void MainWindow::on_textureComboBox_currentIndexChanged(const QString &arg1) {
 //    if(arg1.contains(".")) {
 //        QString path = DIRPATH;
 //        path.append(arg1);
 //        qDebug() << "changed" << path;
 //        QByteArray cStr = path.toLocal8Bit();
 //        srcController.changeTextureImg(cStr.data());
	// 	mainController.setNoTexture(false);
	// } else {
	// 	String cStr = "noTexture";
	// 	srcController.changeTextureImg(cStr);
	// 	mainController.setNoTexture(true);
	// }
}

void MainWindow::on_illuminationSlider_valueChanged(int value) {
	//convertController.changeIntensityParam(true, value);
}

void MainWindow::on_horizontalSlider_valueChanged(int value) {
	//convertController.changeZParam(true, value);
}

void MainWindow::on_toleranceShiftSlider_0_valueChanged(int value) {
	// vector<int> shift = extractParamManager.toleranceShift();
	// shift[0] = value;
	// extractParamManager.setToleranceShift(shift);
}

void MainWindow::on_toleranceShiftSlider_1_valueChanged(int value) {
	// vector<int> shift = extractParamManager.toleranceShift();
	// shift[1] = value;
	// extractParamManager.setToleranceShift(shift);
}

void MainWindow::on_toleranceShiftSlider_2_valueChanged(int value) {
	// vector<int> shift = extractParamManager.toleranceShift();
	// shift[2] = value;
	// extractParamManager.setToleranceShift(shift);
}

void MainWindow::on_splitColorSpaceComboBox_currentIndexChanged(int index) {
	//srcController.changeSplitColorSpace(index);
}


/**
 *エッジ閾値ウィジェットのハンドラ
 *
*/
void MainWindow::changeThreshold(int widgetIndex, int value1, int value2) {
	// CannyThreshold* novel = new CannyThreshold(value1, value2);
	// int channelKey = _edgeWidgetChannelMap.find(widgetIndex)->second;
	// edgeController.changeCannyThreshold(channelKey, novel);
}

void MainWindow::on_ch0EdgeThreshold1_LineEdit_textChanged(const QString &arg1) {
	// changeThreshold(0, arg1.toInt(), ui->ch0EdgeThreshold2_Slider->value());
	// ui->ch0EdgeThreshold1_Slider->setSliderPosition(arg1.toInt());
}

void MainWindow::on_ch0EdgeThreshold2_LineEdit_textChanged(const QString &arg1) {
	// changeThreshold(0, ui->ch0EdgeThreshold1_Slider->value(), arg1.toInt());
	// ui->ch0EdgeThreshold2_Slider->setSliderPosition(arg1.toInt());
}

void MainWindow::on_ch0EdgeThreshold1_Slider_valueChanged(int value) {
	// changeThreshold(0, value, ui->ch0EdgeThreshold2_Slider->value());
	// ui->ch0EdgeThreshold1_LineEdit->setText(QString::number(value));
}

void MainWindow::on_ch0EdgeThreshold2_Slider_valueChanged(int value) {
	// changeThreshold(0, ui->ch0EdgeThreshold1_Slider->value(),value);
	// ui->ch0EdgeThreshold2_LineEdit->setText(QString::number(value));
}



/**
 *色領域抽出時使用チャンネルボックスのイベントハンドラ
 *
*/
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


/**
 *エッジ抽出時使用チャンネルボックスのイベントハンドラ
 *
*/
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

/**
 *チャンネル画像出力ボタンのハンドラ
 *
*/
void MainWindow::on_channelMatPushButton_toggled(bool checked)
{
    if(checked) {
        mainController.showChannelMat();
    } else {
        mainController.closeChannelMat();
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