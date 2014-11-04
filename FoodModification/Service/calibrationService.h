#ifndef CALIBRATIONSERVICE_H
#define CALIBRATIONSERVICE_H

#include "../Utils/opencvBase.h"
#include "../extractParamManager.h"
class CalibrationService {

public:
    CalibrationService();
    void calculateFeatures();
    void calculateAverage(Mat refImg, Mat maskImg, vector<Rect>& roiRects, ExtractParamManager* extractParamManager);
};

#endif // CALIBRATIONSERVICE_H
