#ifndef COLORDIALOG_H
#define COLORDIALOG_H

#include <QDialog>
#include <Model/Util/cvUtil.h>
#include "Controller/mainController.h"

namespace Ui {
class ColorDialog;
}

class ColorDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ColorDialog(QWidget *parent = 0);
    ~ColorDialog();

private slots:


   

private:
    Ui::ColorDialog *ui;
    MainController& mainController = MainController::getInstance();

};

#endif // COLORDIALOG_H
