#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "../Controller/mainController.h"
#include "./calibrateDialog.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    MainController* mainController;
    CalibrationController* calibrationController;
    
private slots:
    void on_convertButton_clicked();

    void on_CalibrateButton_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
