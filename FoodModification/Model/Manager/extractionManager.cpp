#include "extractionManager.h"

ExtractionManager::ExtractionManager() {
  
}

ExtractionManager& ExtractionManager::getInstance() {
    static ExtractionManager instance;
    return instance;
}

void ExtractionManager::save(QXmlStreamWriter& writer) {

}


