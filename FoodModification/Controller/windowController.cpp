#include "windowController.h"

WindowController::WindowController() {
}

WindowController& WindowController::getInstance() {
    static WindowController instance;
    return instance;
}
void WindowController::fullScreen() {
    _windowManager.fullScreen();
    _outputer.fullScreen();
}
void WindowController::unFullScreen() {
    _windowManager.unFullScreen();
    _outputer.unFullScreen();
}