#include "windowManager.h"

#define DEFAULT_WIDTH 640
#define DEFAULT_HEIGHT 480

WindowManager::WindowManager() {
    _output = Size(DEFAULT_WIDTH, DEFAULT_HEIGHT);
	//createWindow("SourceImage");
}

WindowManager& WindowManager::getInstance() {
    static WindowManager instance;
    return instance;
}

void WindowManager::createWindow(QString name) {
	std::string windowName = name.toLocal8Bit();
	_windowNames.push_back(windowName);
    namedWindow(windowName, CV_WINDOW_NORMAL);
    resizeWindow(windowName, DEFAULT_WIDTH, DEFAULT_HEIGHT);
}

void WindowManager::fullScreen() {
    destroyWindow(String("dst"));
    namedWindow(String("full"), 0);
    setWindowProperty(String("full"), CV_WND_PROP_FULLSCREEN,CV_WINDOW_FULLSCREEN);
	moveWindow("full",640,0);
	resizeWindow("full", 1280, 720);
}


void WindowManager::unFullScreen() {
    destroyWindow(String("full"));
    namedWindow(String("dst"), CV_WINDOW_NORMAL);
    setWindowProperty(String("dst"), CV_WND_PROP_FULLSCREEN,CV_WINDOW_NORMAL);
}

string WindowManager::windowName(int index) {
    return _windowNames[index];
}

void WindowManager::save(QXmlStreamWriter& writer) {
    
   
    writer.writeStartElement("Window"); 

    writer.writeStartElement("output size");
    QXmlStreamAttributes outputSizes;
    outputSizes.append("width", QtUtil::toQString(_output.width));
    outputSizes.append("height", QtUtil::toQString(_output.width));
    writer.writeAttributes(outputSizes);
    writer.writeEndElement();

    writer.writeEndElement();

}
