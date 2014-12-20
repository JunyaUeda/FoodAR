#ifndef BGR3DPLOTCONTROLLER_H
#define BGR3DPLOTCONTROLLER_H
#include <qglviewer.h>

class BGR3DPlotController : public QGLViewer {
public:
    static BGR3DPlotController& getInstance();
private:
	BGR3DPlotController();
    BGR3DPlotController(const BGR3DPlotController&);
protected:
	virtual void draw();
	virtual void init();
	virtual QString helpString() const;

};

#endif // BGR3DPLOTCONTROLLER_H

