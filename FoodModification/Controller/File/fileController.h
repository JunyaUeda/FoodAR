#ifndef FILECONTROLLER_H
#define FILECONTROLLER_H

#include <QString>
#include <QDomElement>

class FileController{

public:
    FileController();
    virtual void readFile() = 0;
};

#endif // FILECONTROLLER_H
