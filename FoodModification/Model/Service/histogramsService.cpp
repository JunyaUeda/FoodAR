#include "histogramService.h"

HistogramService::HistogramService() {
}

HistogramService& HistogramService::getInstance() {
    static HistogramService instance;
    return instance;
}

