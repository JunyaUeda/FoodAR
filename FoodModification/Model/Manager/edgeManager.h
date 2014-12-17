#ifndef EDGEMANAGER_H
#define EDGEMANAGER_H

#include "../Param/edge.h"

class EdgeManager {
/*method*/
public:
    static EdgeManager& getInstance();
    Edge& currentEdge() {
        return _currentEdge;
    }
private:
	EdgeManager();
    EdgeManager(const EdgeManager&);
/*property*/
private:
    Edge _currentEdge;
};

#endif // EDGEMANAGER_H
