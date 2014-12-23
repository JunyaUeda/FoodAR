#include "bgr3dPlotViewer.h"
#include <QDebug>

using namespace std;
using namespace qglviewer;

BGR3dPlotViewer::BGR3dPlotViewer(QWidget *parent) :
	QGLViewer(parent)
{
           
}


// Draws a spiral
void BGR3dPlotViewer::draw() {

    //Place light at camera position
    const Vec cameraPos = camera()->position();
    const GLfloat pos[4] = {cameraPos[0], cameraPos[1], cameraPos[2], 1.0};
    glLightfv(GL_LIGHT1, GL_POSITION, pos);

    //Orientate light along view direction
    glLightfv(GL_LIGHT1, GL_SPOT_DIRECTION, camera()->viewDirection());

    glPushMatrix();
        glColor3f(0.5f, 0.5f, 0.5f);
        drawGrid(1.0, 256);
    glPopMatrix();

    glPushMatrix();
    glPointSize(5.0);
    float normalizeScale = 1.0/255.0;
    glBegin(GL_POINTS);
        for(BGRColor color : _colors) {
            glColor3ub(color.r, color.g, color.b);
            float normalizedR = (static_cast<float>(color.r)/255.0);
            float normalizedG = (static_cast<float>(color.g)/255.0);
            float normalizedB = (static_cast<float>(color.b)/255.0);
            glVertex3d(normalizedR, normalizedG, normalizedB);
        }
    glEnd(); 
    glPopMatrix();

    drawRainbowWireCube();
}

void BGR3dPlotViewer::init() {

    //Light setup
    glDisable(GL_LIGHT0);
    glEnable(GL_LIGHT1);

    //Light default parameters
    const GLfloat light_ambient[]  = {1.0, 1.0, 1.0};
    const GLfloat light_specular[] = {1.0, 1.0, 1.0, 1.0};
    const GLfloat light_diffuse[]  = {1.0, 1.0, 1.0, 1.0};

    glLightf( GL_LIGHT1, GL_SPOT_EXPONENT, 0.0);
    glLightf( GL_LIGHT1, GL_SPOT_CUTOFF, 100.0);
    glLightf( GL_LIGHT1, GL_CONSTANT_ATTENUATION, 0.1f);
    glLightf( GL_LIGHT1, GL_LINEAR_ATTENUATION, 0.3f);
    glLightf( GL_LIGHT1, GL_QUADRATIC_ATTENUATION, 0.3f);
	glLightfv( GL_LIGHT1, GL_AMBIENT, light_ambient);
	glLightfv( GL_LIGHT1, GL_SPECULAR, light_specular);
	glLightfv( GL_LIGHT1, GL_DIFFUSE, light_diffuse);


    // Restore previous BGR3dPlotViewer state.
    //restoreStateFromFile();

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
    float normalizeScale = 1.0/255.0;
    glScalef(normalizeScale, normalizeScale, normalizeScale); 
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
	glScalef(1.0, 1.0, 1.0f);
    glPopMatrix();
}
