#include "edge.h"

Edge::Edge() {
}

Mat Edge::edgeImg() const {
    return _edgeImg;
}

void Edge::setEdgeImg(const Mat &edgeImg) {
    _edgeImg = edgeImg;
}

vPs Edge::contours() const {
    return _contours;
}

void Edge::setContours(const vPs &contours) {
    _contours = contours;
}

