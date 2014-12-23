#ifndef BGR3DPLOTDIALOG_H
#define BGR3DPLOTDIALOG_H

#include <QDialog>
#include "../Controller/bgr3dPlotController.h"

namespace Ui {
	class BGR3DPlotDialog;
}

class BGR3DPlotDialog : public QDialog
{

	Q_OBJECT

public:
	explicit BGR3DPlotDialog(QWidget *parent = 0);
	~BGR3DPlotDialog();

private:
	Ui::BGR3DPlotDialog *ui;
    BGR3DPlotController& _bgr3DPlotController = BGR3DPlotController::getInstance();
};

#endif // BGR3DPLOTDIALOG_H
