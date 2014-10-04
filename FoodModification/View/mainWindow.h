#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDir>
#include "../Controller/mainController.h"
#include "../Controller/edgeController.h"
#include "./calibrateDialog.h"
#include "./colorDialog.h"
#include "../Utils/opencvUtils.h"

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
    void on_edgeThresholdSlider_1_valueChanged(int value);

	void on_edgeThresholdSlider_2_valueChanged(int value);

private:
    Ui::MainWindow *ui;
    MainController& mainController = MainController::getInstance();
    CalibrationController& calibrationController = CalibrationController::getInstance();
    ConvertController& convertController = ConvertController::getInstance();
    EdgeController& edgeController = EdgeController::getInstance();
    SrcController& srcController = SrcController::getInstance();
    
};

#endif // MAINWINDOW_H
