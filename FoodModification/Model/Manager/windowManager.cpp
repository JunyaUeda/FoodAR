#include "windowManager.h"

WindowManager::WindowManager() {
    createWindow("myWindow");
}

WindowManager& WindowManager::getInstance() {
    static WindowManager instance;
    return instance;
}

void WindowManager::createWindow(QString name) {
	std::string windowName = name.toLocal8Bit();
	_windowNames.push_back(windowName);
    namedWindow(windowName, CV_WINDOW_NORMAL);
    resizeWindow(windowName, 640, 480);
}

void WindowManager::fullScreen(string name) {
    setWindowProperty(name, CV_WND_PROP_FULLSCREEN,CV_WINDOW_FULLSCREEN);
}

void WindowManager::fullScreen(QString name) {
    std::string windowName = name.toLocal8Bit();
    fullScreen(windowName);
}

void WindowManager::unFullScreen(string name) {
    setWindowProperty(name, CV_WND_PROP_FULLSCREEN,CV_WINDOW_NORMAL);
}

void WindowManager::unFullScreen(QString name) {
    std::string windowName = name.toLocal8Bit();
    unFullScreen(windowName);
}