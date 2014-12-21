#include "bgr3dPlotViewer.h"
#include <QDebug>

using namespace std;
using namespace qglviewer;

BGR3dPlotViewer::BGR3dPlotViewer(QWidget *parent) :
	QGLViewer(parent)
{
            // BGRColor color(200,30,40);
            // _colors.push_back(color);
            // BGRColor color1(255,80,80);
            // _colors.push_back(color1);
            // BGRColor color2(100,45,0);
            // _colors.push_back(color2);
            // BGRColor color3(5,4,3);
            // _colors.push_back(color3);
            // BGRColor color4(10,3,5);
            // _colors.push_back(color4);
            // BGRColor color5(7,8,9);
            // _colors.push_back(color5);
}


// Draws a spiral
void BGR3dPlotViewer::draw() {

    //Place light at camera position
//    const qglviewer::Vec cameraPos = camera()->position();
//    const GLfloat pos[4] = {cameraPos[0], cameraPos[1], cameraPos[2], 1.0};
//    glLightfv(GL_LIGHT1, GL_POSITION, pos);

//    //Orientate light along view direction
//    glLightfv(GL_LIGHT1, GL_SPOT_DIRECTION, camera()->viewDirection());

    glColor3f(1.0, 1.0, 1.0);
    drawGrid(1.0, 256);

    float normalizeScale = 1.0/256;
    glScalef(normalizeScale, normalizeScale, normalizeScale);


    // const float nbSteps = 200.0;
    // glBegin(GL_QUAD_STRIP);
    // for (int i=0; i<nbSteps; ++i) {
    //     const float ratio = i/nbSteps;
    //     const float angle = 21.0*ratio;
    //     const float c = cos(angle);
    //     const float s = sin(angle);
    //     const float r1 = 1.0 - 0.8f*ratio;
    //     const float r2 = 0.8f - 0.8f*ratio;
    //     const float alt = ratio - 0.5f;
    //     const float nor = 0.5f;
    //     const float up = sqrt(1.0-nor*nor);
    //     glColor3f(1.0-ratio, 0.2f , ratio);
    //     glNormal3f(nor*c, up, nor*s);
    //     glVertex3f(r1*c, alt, r1*s);
    //     glVertex3f(r2*c, alt+0.05f, r2*s);
    // }
    // glEnd();

    glPointSize(5.0);
    glColor3f(1.0, 0.0, 0.0);
    glBegin(GL_POINTS);

        for(BGRColor color : _colors) {

            
            glVertex3d(color.b, color.g, color.r);
        }
    glEnd();

    //glutWireCube(256);
    
    glBegin(GL_LINE_LOOP);
        glColor3d(1.0, 0.2, 0.0);
        glVertex3d(_colors[0].b, _colors[0].g, _colors[0].r);
        glVertex3d(_colors[1].b, _colors[1].g, _colors[1].r);
        glVertex3d(_colors[2].b, _colors[2].g, _colors[2].r);
    glEnd();

    drawRainbowWireCube();
}

void BGR3dPlotViewer::init() {

    //Light setup
    //glDisable(GL_LIGHT0);
    glEnable(GL_LIGHT1);

    //Light default parameters
    const GLfloat light_ambient[]  = {1.0, 1.0, 1.0, 1.0};
    const GLfloat light_specular[] = {1.0, 1.0, 1.0, 1.0};
    const GLfloat light_diffuse[]  = {1.0, 1.0, 1.0, 1.0};

    glLightf( GL_LIGHT1, GL_SPOT_EXPONENT, 3.0);
    glLightf( GL_LIGHT1, GL_SPOT_CUTOFF, 10.0);
    glLightf( GL_LIGHT1, GL_CONSTANT_ATTENUATION, 0.1f);
    glLightf( GL_LIGHT1, GL_LINEAR_ATTENUATION, 0.3f);
    glLightf( GL_LIGHT1, GL_QUADRATIC_ATTENUATION, 0.3f);
	glLightfv( GL_LIGHT1, GL_AMBIENT, light_ambient);
	glLightfv( GL_LIGHT1, GL_SPECULAR, light_specular);
	glLightfv( GL_LIGHT1, GL_DIFFUSE, light_diffuse);



    // Restore previous BGR3dPlotViewer state.
    restoreStateFromFile();

    // Opens help window
    //help();
}

QString BGR3dPlotViewer::helpString() const
{
  QString text("<h2>3DPlotDiagram</h2>");
  text += QObject::tr("マウスを使ってカメラを移動させる. ");
  text += "You can respectively revolve around, zoom and translate with the three mouse buttons. ";
  text += "Left and middle buttons pressed together rotate around the camera view direction axis<br><br>";
  text += "Pressing <b>Alt</b> and one of the function keys (<b>F1</b>..<b>F12</b>) defines a camera keyFrame. ";
  text += "Simply press the function key again to restore it. Several keyFrames define a ";
  text += "camera path. Paths are saved when you quit the application and restored at next start.<br><br>";
  text += "Press <b>F</b> to display the frame rate, <b>A</b> for the world axis, ";
  text += "<b>Alt+Return</b> for full screen mode and <b>Control+S</b> to save a snapshot. ";
  text += "See the <b>Keyboard</b> tab in this window for a complete shortcut list.<br><br>";
  text += "Double clicks automates single click actions: A left button double click aligns the closer axis with the camera (if close enough). ";
  text += "A middle button double click fits the zoom of the camera and the right button re-centers the scene.<br><br>";
  text += "A left button double click while holding right button pressed defines the camera <i>Revolve Around Point</i>. ";
  text += "See the <b>Mouse</b> tab and the documentation web pages for details.<br><br>";
  text += "Press <b>Escape</b> to exit the viewer.";
  return text;
}


void BGR3dPlotViewer::drawRainbowWireCube() {
    glPushMatrix();
    glLineWidth(400);
    //RGB=0から３本
    glBegin(GL_LINES);
        glColor3d(0.0f, 0.0f, 0.0f);
        glVertex3d(0.0f, 0.0f, 0.0f);
        glColor3d(1.0f, 0.0f, 0.0f);
        glVertex3d(256.0f, 0.0f, 0.0f);
    glEnd();
    glBegin(GL_LINES);
        glColor3d(0.0f, 0.0f, 0.0f);
        glVertex3d(0.0f, 0.0f, 0.0f);
        glColor3d(0.0f, 1.0f, 0.0f);
        glVertex3d(0.0f, 256.0f, 0.0f);
    glEnd();
    glBegin(GL_LINES);
        glColor3d(0.0f, 0.0f, 0.0f);
        glVertex3d(0.0f, 0.0f, 0.0f);
        glColor3d(0.0f, 0.0f, 1.0f);
        glVertex3d(0.0f, 0.0f, 256.0f);
    glEnd();
    //R256から２本
    glBegin(GL_LINES);
        glColor3d(1.0f, 0.0f, 0.0f);
        glVertex3d(256.0f, 0.0f, 0.0f);
        glColor3d(1.0f, 0.0f, 1.0f);
        glVertex3d(256.0f, 0.0f, 256.0f);
    glEnd();
    glBegin(GL_LINES);
        glColor3d(1.0f, 0.0f, 0.0f);
        glVertex3d(256.0f, 0.0f, 0.0f);
        glColor3d(1.0f, 1.0f, 0.0f);
        glVertex3d(256.0f, 256.0f, 0.0f);
    glEnd();
    //G256から２本
    glBegin(GL_LINES);
        glColor3d(0.0f, 1.0f, 0.0f);
        glVertex3d(0.0f, 256.0f, 0.0f);
        glColor3d(1.0f, 1.0f, 0.0f);
        glVertex3d(256.0f, 256.0f, 0.0f);
    glEnd();
    glBegin(GL_LINES);
        glColor3d(0.0f, 1.0f, 0.0f);
        glVertex3d(0.0f, 256.0f, 0.0f);
        glColor3d(0.0f, 1.0f, 1.0f);
        glVertex3d(0.0f, 256.0f, 256.0f);
    glEnd();
    //B256から２本
    glBegin(GL_LINES);
        glColor3d(0.0f, 0.0f, 1.0f);
        glVertex3d(0.0f, 0.0f, 256.0f);
        glColor3d(1.0f, 0.0f, 1.0f);
        glVertex3d(256.0f, 0.0f, 256.0f);
    glEnd();
    glBegin(GL_LINES);
        glColor3d(0.0f, 0.0f, 1.0f);
        glVertex3d(0.0f, 0.0f, 256.0f);
        glColor3d(0.0f, 1.0f, 1.0f);
        glVertex3d(0.0f, 256.0f, 256.0f);;
    glEnd();
    //RGB=256から３本
    glBegin(GL_LINES);
        glColor3d(1.0f, 1.0f, 1.0f);
        glVertex3d(256.0f, 256.0f, 256.0f);
        glColor3d(1.0f, 1.0f, 0.0f);
        glVertex3d(256.0f, 256.0f, 0.0f);
    glEnd();
    glBegin(GL_LINES);
        glColor3d(1.0f, 1.0f, 1.0f);
        glVertex3d(256.0f, 256.0f, 256.0f);
        glColor3d(1.0f, 0.0f, 1.0f);
        glVertex3d(256.0f, 0.0f, 256.0f);
    glEnd();
    glBegin(GL_LINES);
        glColor3d(1.0f, 1.0f, 1.0f);
        glVertex3d(256.0f, 256.0f, 256.0f);
        glColor3d(0.0f, 1.0f, 1.0f);
        glVertex3d(0.0f, 256.0f, 256.0f);
    glEnd();
    glLineWidth(1.0);
    glPopMatrix();
}
