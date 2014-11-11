#ifndef CALIBRATOR_H
#define CALIBRATOR_H

#include "./SDK/opencv/opencvApi.h"
#include "./Param/color.h"
#include "./Service/regionService.h"

class Calibrator {
/*property*/
private:
	RegionService* _regionService;
/*mehthod*/
public:
    Calibrator();
    bool calibrate(Mat srcImg, Mat refImg, Scalar refColor);
};

#endif // CALIBRATOR_H
