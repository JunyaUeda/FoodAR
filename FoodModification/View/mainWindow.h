#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "../Controller/mainController.h"
#include "./calibrateDialog.h"
#include "./colorDialog.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
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

private:
    Ui::MainWindow *ui;
    MainController& mainController = MainController::getInstance();
    CalibrationController& calibrationController = CalibrationController::getInstance();
    ConvertController& convertController = ConvertController::getInstance();
};

#endif // MAINWINDOW_H
