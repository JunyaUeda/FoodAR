#ifndef BGR3DPLOTVIEWER_H
#define BGR3DPLOTVIEWER_H

#include <../QGLViewer/qglviewer.h>

class BGR3dPlotViewer : public QGLViewer
{
	Q_OBJECT
public:
	explicit BGR3dPlotViewer(QWidget *parent = 0);

protected:
    virtual void draw();
    virtual void init();
    virtual QString helpString() const;

signals:

public slots:

};

#endif // BGR3DPLOTVIEWER_H
