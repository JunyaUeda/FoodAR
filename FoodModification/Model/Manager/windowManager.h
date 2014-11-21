#ifndef WINDOWMANAGER_H
#define WINDOWMANAGER_H

#include <QString>
#include <QVector>
#include <QMap>
#include "../Param/window.h"
#include "../SDK/opencv/opencvApi.h"

class WindowManager {

/*property*/
public:
    QMap<string, Window> _windows;
    QVector<string> _windowNames;
    Size _input;
    Size _output;

/*method*/
public:
    static WindowManager& getInstance();
    void createWindow(QString name);
    void fullScreen(QString name);
    void fullScreen(string name);
    void unFullScreen(string name);
    void unFullScreen(QString name);
private:
	WindowManager();
    WindowManager(const WindowManager&);
};

#endif // WINDOWMANAGER_H
