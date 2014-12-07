#include "convertController.h"
#include <QDebug>

ConvertController::ConvertController() {
	
}

ConvertController& ConvertController::getInstance() {
	static ConvertController instance;
	return instance;
}

int ConvertController::changeIllumination(int currentValue, double intensityFactor) {

	if(currentValue * intensityFactor > 255) {
		return 255;
	} else {
		return (int)currentValue * intensityFactor;
	}

}

void ConvertController::changeIntensityParam(bool change, int intensityFactor) {

	double d_IntensityFactor = (double)intensityFactor/100.0;
	_illuminationParam->setIntensityChange(change);
	_illuminationParam->setIntensityFactor(d_IntensityFactor);

}

void ConvertController::changeZParam(bool change, int ZFactor) {

	double d_ZFactor = (double)ZFactor/100.0;
	_illuminationParam->setZChange(change);
	_illuminationParam->setZFactor(d_ZFactor);

}

void ConvertController::updateAlpha(double alpha) {
	_converter.updateAlpha(alpha);
}