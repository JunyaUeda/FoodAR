#ifndef CALIBRATOR_H
#define CALIBRATOR_H

#include "./SDK/opencv/opencvApi.h"
#include "./Param/color.h"
#include "./Service/regionService.h"
#include "./Param/matSet.h"

class Calibrator {
/*property*/
private:
	RegionService* _regionService;
/*mehthod*/
public:
	static Calibrator& getInstance();
    bool calibrate(Mat srcImg, Mat refImg, Scalar refColor);
private:
	Calibrator();
	Calibrator(const Calibrator&);
};

#endif // CALIBRATOR_H
