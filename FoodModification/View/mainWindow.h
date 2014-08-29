#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "../Controller/mainController.h"

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
    
private slots:
    void on_convertButton_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
