#ifndef REGIONMANAGER_H
#define REGIONMANAGER_H

#include "../Param/region.h"

class RegionManager {
    
/*method*/
public:
    static RegionManager& getInstance();

    Region& currentRegion() {
        return _currentRegion;
    }

    void setPreviousRegion(Region& region) {
        _previousRegion = region;
    }

    Region& previousRegion() {
        return _previousRegion;
    }

    bool isPreviousRegionExisted() {
        if(_previousRegion.isExisted()) {
            return true;
        }
        return false;
    }

    vector<Point> previousPointList() {
        return _previousRegion.points();
    }
    
private:
	RegionManager();
    RegionManager(const RegionManager&);

/*property*/
private:
    Region _currentRegion;
    Region _previousRegion;
};

#endif // REGIONMANAGER_H
