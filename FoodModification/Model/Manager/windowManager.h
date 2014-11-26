#ifndef WINDOWMANAGER_H
#define WINDOWMANAGER_H

#include <QString>
#include <QVector>
#include <QMap>
#include <QXmlStreamWriter>
#include "../Param/window.h"
#include "manager.h"
#include "../SDK/opencv/opencvApi.h"


class WindowManager : public Manager {

/*method*/
public:
    static WindowManager& getInstance();
    void createWindow(QString name);
    void fullScreen(QString name);
    void fullScreen(string name);
    void unFullScreen(string name);
    void unFullScreen(QString name);
    string windowName(int index);
    void save(string filePath);
private:
	WindowManager();
    WindowManager(const WindowManager&);
    XmlElement createXmlElement();
/*property*/
private:
    QMap<string, Window> _windows;
    QVector<string> _windowNames;
    Size _input;
    Size _output;
};

#endif // WINDOWMANAGER_H
