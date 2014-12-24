#ifndef HISTOGRAM3DVIEWER_H
#define HISTOGRAM3DVIEWER_H

#include <../QGLViewer/qglviewer.h>
#include "../Model/Param/bgrColor.h"
#include "../Model/Util/cvUtil.h"

using namespace std;

class Histogram3dViewer : public QGLViewer {
    Q_OBJECT

/*method*/
public:
    explicit Histogram3dViewer(QWidget *parent = 0);

protected:
    virtual void draw();
    virtual void init();
    virtual QString helpString() const;

private:
	GLuint matToTexture(cv::Mat &mat, GLenum minFilter, GLenum magFilter, GLenum wrapFilter);

signals:

public slots:

/*property*/
private:
    // GLuint _texture;
    Mat _textureSrcImg;
};

#endif // HISTOGRAM3DVIEWER_H
