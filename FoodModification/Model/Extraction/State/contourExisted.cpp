#include "contourExisted.h"

ContourExisted::ContourExisted()
{
}

ContourExisted& ContourExisted::getInstance() {
    static ContourExisted instance;
    return instance;
}