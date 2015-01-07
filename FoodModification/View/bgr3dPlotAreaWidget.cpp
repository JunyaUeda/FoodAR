#include "bgr3dPlotAreaWidget.h"

#include <QGridLayout>

BGR3dPlotAreaWidget::BGR3dPlotAreaWidget(QWidget *parent) : QWidget(parent)
{
    _viewer = new BGR3dPlotViewer();
    QGridLayout *layout = new QGridLayout();
    layout->addWidget(_viewer);

    setLayout(layout);
}

