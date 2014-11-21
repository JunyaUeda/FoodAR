#ifndef WINDOW_H
#define WINDOW_H

#include <QString>
#include <QDebug>
#include "../SDK/opencv/opencvApi.h"

class Window {

/*property*/
private:
    std::string _name;
    Size _size;
/*method*/    
public:
	Window(QString name, Size size = Size(640, 480));
    void show(Mat img);
    Size size() const;
    void reSize(const Size& size);
    std::string name() const;
    void changeName(const QString& name);
    void setMouseFunction(Mat img);

private:
    void create();
};

#endif // WINDOW_H
