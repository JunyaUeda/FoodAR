#include "multiContour.h"

MultiContour::MultiContour() {
}

MultiContour& MultiContour::getInstance() {
    static MultiContour instance;
    return instance;
}