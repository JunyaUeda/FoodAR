#ifndef COLORDIALOG_H
#define COLORDIALOG_H

#include <QDialog>
#include "../Utils/opencvUtils.h"
#include "../Controller/convertController.h"

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
 	void on_hShiftSlider_actionTriggered(int action);
    void on_sShiftSlider_actionTriggered(int action);
    void on_vShiftSlider_actionTriggered(int action);

   

private:
    Ui::ColorDialog *ui;
    ConvertController& convertController = ConvertController::getInstance();

};

#endif // COLORDIALOG_H
