#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QDir>
#include <QMainWindow>
#include <QDebug>
#include "../Utils/opencvUtils.h"
#include "./colorDialog.h"
#include "./calibrateDialog.h"
#include "../Controller/mainController.h"
#include "../Controller/edgeController.h"
#include "../Controller/extractionController.h"
#include "../Param/cannyThreshold.h"
#include "../definition.h"

#define DIRPATH "../FoodModification/Images/"

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow {

    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    
private slots:
    void on_startPushButton_clicked();
    void on_stopPushButton_clicked();
    void on_convertButton_clicked();
    void on_CalibrateButton_clicked();
    void on_colorMapButton_clicked();
    void on_alphaSlider_actionTriggered(int action);

    void on_radioButton_captureSizeLarge_clicked();
    void on_radioButton_captureSizeSmall_clicked();
    void on_radioButton_dstSizeSmall_clicked();
    void on_radioButton_dstSizeLarge_clicked();
    
    void on_textureComboBox_currentIndexChanged(const QString &arg1);
    void on_illuminationSlider_valueChanged(int value);
    void on_horizontalSlider_valueChanged(int value);

    
	void on_toleranceShiftSlider_0_valueChanged(int value);
	void on_toleranceShiftSlider_1_valueChanged(int value);
	void on_toleranceShiftSlider_2_valueChanged(int value);

	void on_splitColorSpaceComboBox_currentIndexChanged(int index);

    //edgeの閾値UIのイベント処理
    void changeThreshold(int channelIndex, int value1, int value2);
    void on_ch0EdgeThreshold1_LineEdit_textChanged(const QString &arg1);
    void on_ch0EdgeThreshold2_LineEdit_textChanged(const QString &arg1);
	void on_ch1EdgeThreshold1_LineEdit_textChanged(const QString &arg1);
	void on_ch1EdgeThreshold2_LineEdit_textChanged(const QString &arg1);
    void on_ch2EdgeThreshold1_LineEdit_textChanged(const QString &arg1);
    void on_ch2EdgeThreshold2_LineEdit_textChanged(const QString &arg1);
    void on_ch0EdgeThreshold1_Slider_valueChanged(int value);
    void on_ch0EdgeThreshold2_Slider_valueChanged(int value);
	void on_ch1EdgeThreshold1_Slider_valueChanged(int value);
	void on_ch1EdgeThreshold2_Slider_valueChanged(int value);
	void on_ch2EdgeThreshold1_Slider_valueChanged(int value);
    void on_ch2EdgeThreshold2_Slider_valueChanged(int value);

	/*抽出チャンネルチェックボックス*/
	void on_colorBlueCheckBox_clicked();
	void on_colorGreenCheckBox_clicked();
	void on_colorRedCheckBox_clicked();
	void on_colorHueCheckBox_clicked();
	void on_colorSaturationCheckBox_clicked();
    void on_colorValueCheckBox_clicked();
	void on_colorYCheckBox_clicked();
	void on_colorCrCheckBox_clicked();
	void on_colorCbCheckBox_clicked();

    /*抽出エッジチャンネルチェックボックス*/
	void on_edgeBlueCheckBox_clicked();
	void on_edgeGreenCheckBox_clicked();
	void on_edgeRedCheckBox_clicked();
	void on_edgeHueCheckBox_clicked();
	void on_edgeSaturationCheckBox_clicked();
	void on_edgeValueCheckBox_clicked();
	void on_edgeYCheckBox_clicked();
    void on_edgeCrCheckBox_clicked();
	void on_edgeCbCheckBox_clicked();
private:
    vector<ChannelType> collectColorCheckBoxStatus();
    vector<ChannelType> collectEdgeChannelCheckBoxStatus();

/*property*/
private:
    Ui::MainWindow *ui;

    MainController& mainController               = MainController::getInstance();
    CalibrationController& calibrationController = CalibrationController::getInstance();
    ConvertController& convertController         = ConvertController::getInstance();
    EdgeController& edgeController               = EdgeController::getInstance();
    SrcController& srcController                 = SrcController::getInstance();
    ExtractionController& _extractionController  = ExtractionController::getInstance();
    

    map<int, int> _edgeWidgetChannelMap;
    //map<int, string> _channelIndexNameMap;
};

#endif // MAINWINDOW_H
