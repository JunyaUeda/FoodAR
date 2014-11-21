#include "extractionManager.h"

ExtractionManager::ExtractionManager() {
}

ExtractionManager& ExtractionManager::getInstance() {
    static ExtractionManager instance;
    return instance;
}

int ExtractionManager::splitColorSpace() const {
    return _splitColorSpace;
}

void ExtractionManager::setSplitColorSpace(int splitColorSpace) {
    _splitColorSpace = splitColorSpace;
}
