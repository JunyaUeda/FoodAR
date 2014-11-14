#include "extractor.h"

Extractor::Extractor() {
}

Extractor& Extractor::getInstance() {
    static Extractor instance;
    return instance;
}

void Extractor::extract(MatSet* srcSet) {
      Region* region = _extractService.extractRegionByColor(srcSet, &_featureReference);
      imshow("new extract", region->maskImg());
}
