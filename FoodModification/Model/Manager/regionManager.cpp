#include "regionManager.h"

RegionManager::RegionManager() {
}

RegionManager& RegionManager::getInstance() {
    static RegionManager instance;
    return instance;
}
