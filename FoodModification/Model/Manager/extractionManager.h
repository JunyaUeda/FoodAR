#ifndef EXTRACTIONMANAGER_H
#define EXTRACTIONMANAGER_H

#include "../../definition.h"
#include "manager.h"

class ExtractionManager : public Manager {

/*method*/
public:
    static ExtractionManager& getInstance();
    void save(string filePath){}
    int splitColorSpace() const;
    void setSplitColorSpace(int splitColorSpace);
private:
    ExtractionManager();
    ExtractionManager(const ExtractionManager&);
    XmlElement createXmlElement(){
        return (*new XmlElement);
    }

/*property*/
private:
    int _splitColorSpace = JU_YCrCb;
    

};

#endif // EXTRACTIONMANAGER_H
