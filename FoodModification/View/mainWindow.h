#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QDir>
#include <QMainWindow>
#include <QDebug>
#include "Model/Util/cvUtil.h"
#include "colorDialog.h"
#include "calibrateDialog.h"
#include "bgr3dPlotDialog.h"
#include "Controller/mainController.h"
#include "Controller/edgeController.h"
#include "Controller/extractionController.h"
#include "definition.h"
#include "Controller/textureController.h"
#include "Controller/cameraController.h"
#include "Controller/windowController.h"


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
    /**
    * ホームタブ
    */
    void on_startPushButton_clicked();
    void on_stopPushButton_clicked();
    void on_CalibrateButton_clicked();
    void on_colorMapButton_clicked();
    void on_plot3DPushButton_clicked();

    //色調整コントロール
    //alpha
    void on_alphaLineEdit_textChanged(const QString &arg1);
    void on_alphaSlider_valueChanged(int value);
    void on_hueLineEdit_textChanged(const QString &arg1);
    void on_hueSlider_valueChanged(int value);
    void on_saturationLineEdit_textChanged(const QString &arg1);
    void on_saturationSlider_valueChanged(int value);
    void on_valueLineEdit_textChanged(const QString &arg1);
    void on_valueSlider_valueChanged(int value);
    //テクスチャ切り替え
    void on_textureComboBox_currentIndexChanged(const QString &arg1);
    //フルスクリーン
    void on_fullScreenPushButton_toggled(bool checked);
    //ショートカットセッティング
    void on_maguroRadioButton_clicked();    
    void on_coffeeRadioButton_clicked(bool checked);
    /**
    * 画面サイズタブ
    */
    void on_radioButton_captureSizeLarge_clicked();
    void on_radioButton_captureSizeSmall_clicked();
    void on_radioButton_dstSizeSmall_clicked();
    void on_radioButton_dstSizeLarge_clicked();
    
    void on_illuminationSlider_valueChanged(int value);
    void on_horizontalSlider_valueChanged(int value);

	/**
    * 抽出タブ
    */
    /**抽出チャンネルチェックボックス*/
	void on_colorBlueCheckBox_clicked();
	void on_colorGreenCheckBox_clicked();
	void on_colorRedCheckBox_clicked();
	void on_colorHueCheckBox_clicked();
	void on_colorSaturationCheckBox_clicked();
    void on_colorValueCheckBox_clicked();
	void on_colorYCheckBox_clicked();
	void on_colorCrCheckBox_clicked();
	void on_colorCbCheckBox_clicked();
    /**抽出エッジチャンネルチェックボックス*/
	void on_edgeBlueCheckBox_clicked();
	void on_edgeGreenCheckBox_clicked();
	void on_edgeRedCheckBox_clicked();
	void on_edgeHueCheckBox_clicked();
	void on_edgeSaturationCheckBox_clicked();
	void on_edgeValueCheckBox_clicked();
	void on_edgeYCheckBox_clicked();
    void on_edgeCrCheckBox_clicked();
	void on_edgeCbCheckBox_clicked();
	void on_channelMatPushButton_toggled(bool checked);
    void on_binarizedMatPushButton_toggled(bool checked);
    void on_cannyEdgeMatPushButton_toggled(bool checked);
    /**チャンネル閾値強度調整*/
	void on_channelThresholdHorizontalSlider_valueChanged(int value);
	void on_channelThresholdLineEdit_textChanged(const QString &arg1);
	void on_channelThresholdComboBox_currentIndexChanged(int index);
    /**モルフォロジー変換*/
	void on_dilateSpinBox_valueChanged(int arg1);
	void on_erodeSpinBox_valueChanged(int arg1);
    /**二値化閾値調整*/
    void on_blueBinarizationThresholdLineEdit_textChanged(const QString &arg1);
    void on_blueBinarizationThresholdSlider_valueChanged(int value);
    void on_greenBinarizationThresholdLineEdit_textChanged(const QString &arg1);
    void on_greenBinarizationThresholdSlider_valueChanged(int value);
    void on_redBinarizationThresholdLineEdit_textChanged(const QString &arg1);
    void on_redBinarizationThresholdSlider_valueChanged(int value);
    void on_hueBinarizationThresholdLineEdit_textChanged(const QString &arg1);
    void on_hueBinarizationThresholdSlider_valueChanged(int value);
    void on_saturationBinarizationThresholdLineEdit_textChanged(const QString &arg1);
    void on_saturationBinarizationThresholdSlider_valueChanged(int value);
    void on_valueBinarizationThresholdLineEdit_textChanged(const QString &arg1);
    void on_valueBinarizationThresholdSlider_valueChanged(int value);
    void on_yBinarizationThresholdLineEdit_textChanged(const QString &arg1);
    void on_yBinarizationThresholdSlider_valueChanged(int value);
    void on_crBinarizationThresholdLineEdit_textChanged(const QString &arg1);
    void on_crBinarizationThresholdSlider_valueChanged(int value);
    void on_cbBinarizationThresholdLineEdit_textChanged(const QString &arg1);
    void on_cbBinarizationThresholdSlider_valueChanged(int value);
    


    void on_upperRatioSlider_valueChanged(int value);
    void on_upperRatioLineEdit_textChanged(const QString &arg1);
    void on_underRatioSlider_valueChanged(int value);
    void on_underRatioLineEdit_textChanged(const QString &arg1);

    /**
    * カメラタブ
    */
	void on_captureContrastLineEdit_textChanged(const QString &arg1);
	void on_captureContrastSlider_valueChanged(int value);
	void on_captureBrightnessLineEdit_textChanged(const QString &arg1);
	void on_captureBrightnessSlider_valueChanged(int value);
	void on_captureGaineLineEdit_textChanged(const QString &arg1);
	void on_captureGainSlider_valueChanged(int value);
	void on_captureExposureLineEdit_textChanged(const QString &arg1);
	void on_captureExposureSlider_valueChanged(int value);
	void on_captureSaturationLineEdit_textChanged(const QString &arg1);
	void on_captureSaturationSlider_valueChanged(int value);



	

	

private:
    vector<ChannelType> collectColorCheckBoxStatus();
    vector<ChannelType> collectEdgeChannelCheckBoxStatus();
    ChannelType aqcuireChannelType(int channelNumber);

/*property*/
private:
	Ui::MainWindow *ui;
	MainController& mainController               = MainController::getInstance();
    CalibrationController& calibrationController = CalibrationController::getInstance();
    ConvertController& _convertController         = ConvertController::getInstance();
    EdgeController& edgeController               = EdgeController::getInstance();
    ExtractionController& _extractionController  = ExtractionController::getInstance();
	TextureController& _textureController = TextureController::getInstance();
    CameraController& _cameraController = CameraController::getInstance();
    WindowController& _windowController = WindowController::getInstance();
    
    map<int, int> _edgeWidgetChannelMap;
    
};

#endif // MAINWINDOW_H
