#include "extractor.h"

Extractor::Extractor() {
}

Extractor& Extractor::getInstance() {
    static Extractor instance;
    return instance;
}

void Extractor::extract(MatSet* srcSet) {

}