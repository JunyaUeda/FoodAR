#include "histogram3dViewer.h"

using namespace std;
using namespace qglviewer;

#define A_TEXTURE_PATH "../FoodModification/Images/GL/colormap.png"

Histogram3dViewer::Histogram3dViewer(QWidget *parent) :
    QGLViewer(parent) 
{
    _textureSrcImg = imread(A_TEXTURE_PATH, 1);
}

// Draws a spiral
void Histogram3dViewer::draw() {

    //Place light at camera position
	// const qglviewer::Vec cameraPos = camera()->position(); //OpenCVにもVecの定義があるため明示的に指定する
 //    const GLfloat pos[4] = {cameraPos[0], cameraPos[1], cameraPos[2], 1.0};
 //    glLightfv(GL_LIGHT1, GL_POSITION, pos);

    //Orientate light along view direction
    //glLightfv(GL_LIGHT1, GL_SPOT_DIRECTION, camera()->viewDirection());

    // const float nbSteps = 200.0;
    // glBegin(GL_QUAD_STRIP);
    //     for (int i=0; i<nbSteps; ++i) {
    //         const float ratio = i/nbSteps;
    //         const float angle = 21.0*ratio;
    //         const float c = cos(angle);
    //         const float s = sin(angle);
    //         const float r1 = 1.0 - 0.8f*ratio;
    //         const float r2 = 0.8f - 0.8f*ratio;
    //         const float alt = ratio - 0.5f;
    //         const float nor = 0.5f;
    //         const float up = sqrt(1.0-nor*nor);
    //         glColor3f(1.0-ratio, 0.2f , ratio);
    //         glNormal3f(nor*c, up, nor*s);
    //         glVertex3f(r1*c, alt, r1*s);
    //         glVertex3f(r2*c, alt+0.05f, r2*s);
    //     }
    // glEnd();

    glEnable(GL_TEXTURE_2D);

    // glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, _textureSrcImg.cols, _textureSrcImg.rows,
    //                 0, GL_BGR, GL_UNSIGNED_BYTE,  _textureSrcImg.ptr());

    // glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP);
    // glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP);
    // glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    // glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_REPLACE);
    // glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);

    GLuint imageTex = matToTexture(_textureSrcImg, GL_LINEAR_MIPMAP_LINEAR,   GL_LINEAR, GL_CLAMP);
    glBindTexture(GL_TEXTURE_2D, imageTex);
    
    glBegin(GL_QUADS);
    // glTexCoord2f(0,1); glVertex3f(0.0, 1.0, 0.0);//左上
    // glTexCoord2f(0,0); glVertex3f(0.0, 0.0, 0.0);//左下
    // glTexCoord2f(1,0); glVertex3f(1.0, 0.0, 0.0);//右下
    // glTexCoord2f(1,1); glVertex3f(1.0, 1.0, 0.0);//右上
    glTexCoord2f(1,1); glVertex3f(0.0, 1.0, 0.0);
    glTexCoord2f(1,0); glVertex3f(0.0, 0.0, 0.0);
    glTexCoord2f(0,0); glVertex3f(1.0, 0.0, 0.0); 
    glTexCoord2f(0,1); glVertex3f(1.0, 1.0, 0.0);
    glEnd();
    glDisable(GL_TEXTURE_2D);
}

void Histogram3dViewer::init() {

    //Light setup
    // glDisable(GL_LIGHT0);
    // glEnable(GL_LIGHT1);

    // //Light default parameters
    // const GLfloat light_ambient[]  = {1.0, 1.0, 1.0};
    // const GLfloat light_specular[] = {1.0, 1.0, 1.0, 1.0};
    // const GLfloat light_diffuse[]  = {1.0, 1.0, 1.0, 1.0};

    // glLightf( GL_LIGHT1, GL_SPOT_EXPONENT, 0.0);
    // glLightf( GL_LIGHT1, GL_SPOT_CUTOFF, 100.0);
    // glLightf( GL_LIGHT1, GL_CONSTANT_ATTENUATION, 0.1f);
    // glLightf( GL_LIGHT1, GL_LINEAR_ATTENUATION, 0.3f);
    // glLightf( GL_LIGHT1, GL_QUADRATIC_ATTENUATION, 0.3f);
    // glLightfv( GL_LIGHT1, GL_AMBIENT, light_ambient);
    // glLightfv( GL_LIGHT1, GL_SPECULAR, light_specular);
    // glLightfv( GL_LIGHT1, GL_DIFFUSE, light_diffuse);


    glPixelStorei(GL_UNPACK_ALIGNMENT, 4);
    // glGenTextures(1, &_texture);
    // glBindTexture(GL_TEXTURE_2D, _texture);


    // Restore previous Histogram3dViewer state.
    //restoreStateFromFile();

    // Opens help window
    //help();
}

QString Histogram3dViewer::helpString() const
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

GLuint Histogram3dViewer::matToTexture(cv::Mat &mat, GLenum minFilter, GLenum magFilter, GLenum wrapFilter)
{
    // Generate a number for our textureID's unique handle
    GLuint textureID;
    glGenTextures(1, &textureID);

    // Bind to our texture handle
    glBindTexture(GL_TEXTURE_2D, textureID);

    // Catch silly-mistake texture interpolation method for magnification
    if (magFilter == GL_LINEAR_MIPMAP_LINEAR  ||
        magFilter == GL_LINEAR_MIPMAP_NEAREST ||
        magFilter == GL_NEAREST_MIPMAP_LINEAR ||
        magFilter == GL_NEAREST_MIPMAP_NEAREST)
    {
        // You can't use MIPMAPs for magnification - setting filter to GL_LINEAR"
        cout << "You can't use MIPMAPs for magnification - setting filter to GL_LINEAR" << endl;
        magFilter = GL_LINEAR;
    }

    // Set texture interpolation methods for minification and magnification
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, minFilter);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, magFilter);

    // Set texture clamping method
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, wrapFilter);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, wrapFilter);

    // Set incoming texture format to:
    // GL_BGR       for CV_CAP_OPENNI_BGR_IMAGE,
    // GL_LUMINANCE for CV_CAP_OPENNI_DISPARITY_MAP,
    // Work out other mappings as required ( there's a list in comments in main() )
    GLenum inputColourFormat = GL_BGR;

    // todo check the format of the picture and set this approriately this is where it screws up for some pics...
    if (mat.channels() == 1)
    {
        inputColourFormat = GL_LUMINANCE;
    }

    // Create the texture
    glTexImage2D(GL_TEXTURE_2D,     // Type of texture
                 0,                 // Pyramid level (for mip-mapping) - 0 is the top level
                 GL_RGB,            // Internal colour format to convert to
                 mat.cols,          // Image width  i.e. 640 for Kinect in standard mode
                 mat.rows,          // Image height i.e. 480 for Kinect in standard mode
                 0,                 // Border width in pixels (can either be 1 or 0)
                 inputColourFormat, // Input image format (i.e. GL_RGB, GL_RGBA, GL_BGR etc.)
                 GL_UNSIGNED_BYTE,  // Image data type
                 mat.ptr());        // The actual image data itself
    
    // If we're using mipmaps then generate them. Note: This requires OpenGL 3.0 or higher
    if (minFilter == GL_LINEAR_MIPMAP_LINEAR  ||
        minFilter == GL_LINEAR_MIPMAP_NEAREST ||
        minFilter == GL_NEAREST_MIPMAP_LINEAR ||
        minFilter == GL_NEAREST_MIPMAP_NEAREST)
    {
        //glGenerateMipmap(GL_TEXTURE_2D); //todo link glew for this
    }
    return textureID;
}