#ifndef REGIONMANAGER_H
#define REGIONMANAGER_H

#include "../Param/region.h"

class RegionManager {
/*method*/
public:
    static RegionManager& getInstance();

    void setPreviousRegion(Region& region) {
        _previousRegion = region;
    }

    Region& previousRegion() {
        return _previousRegion;
    }
    
private:
	RegionManager();
    RegionManager(const RegionManager&);

/*property*/
private:
    Region _previousRegion;
};

#endif // REGIONMANAGER_H
