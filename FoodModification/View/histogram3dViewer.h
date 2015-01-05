#pragma once
#ifndef HISTOGRAM3DVIEWER_H
#define HISTOGRAM3DVIEWER_H

#include <../QGLViewer/qglviewer.h>
#include "../Model/Param/xyYColor.h"
#include "../Model/Util/cvUtil.h"

using namespace std;

class Histogram3dViewer : public QGLViewer {
    Q_OBJECT

/*method*/
public:
    explicit Histogram3dViewer(QWidget *parent = 0);
    void addColorPoint(xyYColor color) {
        _colors.push_back(color);
    }
protected:
    virtual void draw();
    virtual void init();
    virtual QString helpString() const;

private:
	GLuint matToTexture(cv::Mat &mat, GLenum minFilter, GLenum magFilter, GLenum wrapFilter);
    void drawColorDiagram();
signals:

public slots:

/*property*/
public:
    vector<vector<int> > xyHistogram;
private:
    GLuint _texture;
    Mat _textureSrcImg;
    vector<xyYColor> _colors;
};

#endif // HISTOGRAM3DVIEWER_H
