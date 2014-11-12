#ifndef CALIBRATOR_H
#define CALIBRATOR_H

#include "./SDK/opencv/opencvApi.h"
#include "./Param/color.h"
#include "./Service/regionService.h"
#include "./Param/matSet.h"
#include "./featureReference.h"
#include "./TypeDef.h"

class Calibrator {
/*property*/
private:
	RegionService* _regionService;
    FeatureReference&  _featureReference = FeatureReference::getInstance();
/*mehthod*/
public:
	static Calibrator& getInstance();
    bool calibrate(Mat srcImg, Mat refImg, QVS refColor);
private:
	Calibrator();
	Calibrator(const Calibrator&);
};

#endif // CALIBRATOR_H
