#include "windowController.h"

WindowController::WindowController() {
}

WindowController& WindowController::getInstance() {
    static WindowController instance;
    return instance;
}
void WindowController::fullScreen() {
    _windowManager.fullScreen(QString("dst"));
    _outputer.fullScreen();
}
void WindowController::unFullScreen() {
    _windowManager.unFullScreen(QString("dst"));
    _outputer.unFullScreen();
}