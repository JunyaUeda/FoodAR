#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QDir>
#include <QMainWindow>
#include "../Utils/opencvUtils.h"
#include "./colorDialog.h"
#include "./calibrateDialog.h"
#include "../Controller/mainController.h"
#include "../Controller/edgeController.h"
#include "../Param/cannyThreshold.h"

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

private:
    Ui::MainWindow *ui;
    MainController& mainController = MainController::getInstance();
    CalibrationController& calibrationController = CalibrationController::getInstance();
    ConvertController& convertController = ConvertController::getInstance();
    EdgeController& edgeController = EdgeController::getInstance();
    SrcController& srcController = SrcController::getInstance();
    ExtractParamManager& extractParamManager = ExtractParamManager::getInstance();
    
};

#endif // MAINWINDOW_H
