#ifndef MANAGER_H
#define MANAGER_H

#include <QString>
#include <QFile>
#include <QDebug>
#include <QXmlStreamWriter>
#include "../Util/qtUtil.h"

using namespace std;

class Manager {

/*method*/
public:
    virtual void save(QXmlStreamWriter& writer)=0;
protected:
	Manager();
    //virtual XmlElement createXmlElement()=0;
};

#endif // MANAGER_H
