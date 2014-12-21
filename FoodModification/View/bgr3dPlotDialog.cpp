#include "bgr3dPlotDialog.h"
#include "ui_bgr3dPlotDialog.h"

BGR3DPlotDialog::BGR3DPlotDialog(QWidget *parent) :
	QDialog(parent),
	ui(new Ui::BGR3DPlotDialog)
{
    _bgr3DPlotController.prepareBGR3dPlot(_bgr3dPlotViewer);
    _bgr3dPlotViewer.show();
	ui->setupUi(this);
    // // Instantiate the viewer.
//   BGR3DPlotController bgr3DPlotController;

  //_bgr3dPlotViewer.setWindowTitle("simpleViewer");

  // Make the viewer window visible on screen.
 
}

BGR3DPlotDialog::~BGR3DPlotDialog()
{
	delete ui;
}
