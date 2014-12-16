#include "contourNonExisted.h"

ContourNonExisted::ContourNonExisted()
{
}

ContourNonExisted& ContourNonExisted::getInstance() {
    static ContourNonExisted instance;
    return instance;
}