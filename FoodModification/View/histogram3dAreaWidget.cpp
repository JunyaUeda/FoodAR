#include "histogram3dAreaWidget.h"

#include <QGridLayout>

Histogram3dAreaWidget::Histogram3dAreaWidget(QWidget *parent) : QWidget(parent)
{
    _viewer = new Histogram3dViewer();
    QGridLayout *layout = new QGridLayout();
    layout->addWidget(_viewer);

    setLayout(layout);
}


