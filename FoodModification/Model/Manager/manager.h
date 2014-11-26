#ifndef MANAGER_H
#define MANAGER_H

#include <string>
#include "../Param/xmlElement.h"

using namespace std;

class Manager {

/*method*/
public:
    virtual void save(string filePath)=0;
protected:
	Manager();
    virtual XmlElement createXmlElement()=0;
};

#endif // MANAGER_H
