#ifndef BGR3DPLOTDIALOG_H
#define BGR3DPLOTDIALOG_H

#include <QDialog>
#include "./bgr3dPlotViewer.h"

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
    BGR3dPlotViewer _bgr3dPlotViewer;
};

#endif // BGR3DPLOTDIALOG_H
