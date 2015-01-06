#ifndef BGR3DPLOTVIEWER_H
#define BGR3DPLOTVIEWER_H

#include <../libQGLViewer-2.6.0/QGLViewer/qglviewer.h>
#include "../Model/Param/bgrColor.h"

using namespace std;

class BGR3dPlotViewer : public QGLViewer {
	Q_OBJECT

/*method*/    
public:
	explicit BGR3dPlotViewer(QWidget *parent = 0);
    void setColorList(vector<BGRColor> colors) {
        _colors = colors;
    }
    void addColorPoint(BGRColor color) {
        _colors.push_back(color);
    }
    
protected:
    virtual void draw();
    virtual void init();
    virtual QString helpString() const;

private:
    void drawRainbowWireCube();
    
signals:

public slots:

/*property*/
private:
    vector<BGRColor> _colors;
};

#endif // BGR3DPLOTVIEWER_H
