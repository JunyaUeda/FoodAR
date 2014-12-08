#ifndef WINDOWMANAGER_H
#define WINDOWMANAGER_H

#include <QString>
#include <QVector>
#include <QMap>
#include "../Param/window.h"
#include "manager.h"
#include "../SDK/opencv/opencvApi.h"


class WindowManager : public Manager {

/*method*/
public:
    static WindowManager& getInstance();
    void createWindow(QString name);
    void fullScreen();
    void unFullScreen();
    string windowName(int index);
    void save(QXmlStreamWriter& writer);

private:
	WindowManager();
    WindowManager(const WindowManager&);
   
/*property*/
private:
    QMap<string, Window> _windows;
    QVector<string> _windowNames;
    Size _output;
};

#endif // WINDOWMANAGER_H
