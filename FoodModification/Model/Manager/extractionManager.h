#ifndef EXTRACTIONMANAGER_H
#define EXTRACTIONMANAGER_H

#include <vector>
#include "manager.h"
#include "../TypeDef.h"
#include "../Param/edgeThreshold.h"

class ExtractionManager : public Manager {

/*method*/
public:
    static ExtractionManager& getInstance();
    void save(QXmlStreamWriter& writer);
private:
    ExtractionManager();
    ExtractionManager(const ExtractionManager&);

/*property*/
private:

};

#endif // EXTRACTIONMANAGER_H
