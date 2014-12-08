#ifndef WINDOWCONTROLLER_H
#define WINDOWCONTROLLER_H

#include "../Model/Manager/windowManager.h"
#include "../Model/Executor/outputer.h"

class WindowController {

/*method*/
public:
    static WindowController& getInstance();
    void fullScreen();
    void unFullScreen();
private:
	WindowController();
    WindowController(const WindowController&);

/*property*/
private:
    WindowManager& _windowManager = WindowManager::getInstance();
    Outputer& _outputer = Outputer::getInstance();
};

#endif // WINDOWCONTROLLER_H
