#include "bgr3dPlotDialog.h"
#include "ui_bgr3dPlotDialog.h"

BGR3DPlotDialog::BGR3DPlotDialog(QWidget *parent) :
	QDialog(parent),
	ui(new Ui::BGR3DPlotDialog)
{
    
	ui->setupUi(this);

    _bgr3DPlotController.prepareBGR3dPlot(ui->bgrPlot3dView);


    
}

BGR3DPlotDialog::~BGR3DPlotDialog()
{
	delete ui;
}
