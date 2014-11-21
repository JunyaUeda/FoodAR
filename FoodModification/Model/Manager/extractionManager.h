#ifndef EXTRACTIONMANAGER_H
#define EXTRACTIONMANAGER_H

#include "../../definition.h"

class ExtractionManager {

/*property*/
private:
    int _splitColorSpace = JU_YCrCb;
/*method*/
public:
     static ExtractionManager& getInstance();
     int splitColorSpace() const;
    void setSplitColorSpace(int splitColorSpace);
private:
	ExtractionManager();
    ExtractionManager(const ExtractionManager&);
};

#endif // EXTRACTIONMANAGER_H
