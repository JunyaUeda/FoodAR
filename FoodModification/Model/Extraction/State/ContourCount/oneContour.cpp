#include "oneContour.h"

OneContour::OneContour() {
}

OneContour& OneContour::getInstance() {
    static OneContour instance;
    return instance;
}