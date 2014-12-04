#include "calibrator.h"

Calibrator::Calibrator() {
}

Calibrator& Calibrator::getInstance() {
	static Calibrator instance;
	return instance;
}

bool Calibrator::calibrate(Mat srcImg, Mat refImg, QVS refColor) {

    MatSet matSet(srcImg);

	QLPs regions    = _regionService->toPointList(refImg, refColor);
	QVis averages   = _regionService->calcAverages(matSet, regions);
	QVis tolerances = _regionService->calcTolerances(matSet, regions, averages);

    _featureReference.updateThresholds(averages, tolerances);


	return true;
}
