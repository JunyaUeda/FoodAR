#ifndef BGR3DPLOTAREAWIDGET_H
#define BGR3DPLOTAREAWIDGET_H

#include <QWidget>
#include "bgr3dPlotViewer.h"

class BGR3dPlotAreaWidget : public QWidget
{
    Q_OBJECT
public:
    explicit BGR3dPlotAreaWidget(QWidget *parent = 0);
    BGR3dPlotViewer *_viewer;

signals:

public slots:
};

#endif // BGR3DPLOTAREAWIDGET_H
