#include "edgeManager.h"

EdgeManager::EdgeManager() {
}

EdgeManager& EdgeManager::getInstance() {
    static EdgeManager instance;
    return instance;
}