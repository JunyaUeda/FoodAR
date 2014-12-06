#include "calibrator.h"

Calibrator::Calibrator() {
}

Calibrator& Calibrator::getInstance() {
	static Calibrator instance;
	return instance;
}

//TODO : 処理が多いので分割すべし
bool Calibrator::calibrate(Mat srcImg, Mat refImg, QVS refColor) {

    MatSet matSet(srcImg);

	QLPs regions    = _regionService->toPointList(refImg, refColor);
	QVis averages   = _regionService->calcAverages(matSet, regions);
	QVis tolerances = _regionService->calcTolerances(matSet, regions, averages);

    _featureReference.updateThresholds(averages, tolerances);
    

    Mat resultMaskImg = Mat::zeros(srcImg.size(), CV_8UC1);
    _regionService->acquireMaskImg(refImg, refColor, resultMaskImg);
    Region region(resultMaskImg);
    region.calcContours();
    region.calcRois();
    region.calcRotatedRects();
    _extractor.setPreviousRegion(region);

	return true;
}

void Calibrator::calibrate(Region& region) {
    
}