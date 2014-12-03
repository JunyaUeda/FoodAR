#include "edge.h"

Edge::Edge() {
}

Edge::Edge(const Mat &mat) {
    _mat = mat;
}

Mat Edge::mat() const {
    return _mat;
}

void Edge::setMat(const Mat &mat) {
    _mat = mat;
}

vPs Edge::contours() const {
    return _contours;
}

void Edge::setContours(const vPs &contours) {
    _contours = contours;
}

