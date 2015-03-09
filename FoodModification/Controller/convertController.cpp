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

//void ConvertController::changeIntensityParam(bool change, int intensityFactor) {

//	double d_IntensityFactor = (double)intensityFactor/100.0;
//	_illuminationParam->setIntensityChange(change);
//	_illuminationParam->setIntensityFactor(d_IntensityFactor);

//}

//void ConvertController::changeZParam(bool change, int ZFactor) {

//	double d_ZFactor = (double)ZFactor/100.0;
//	_illuminationParam->setZChange(change);
//	_illuminationParam->setZFactor(d_ZFactor);

//}

void ConvertController::updateAlpha(double alpha) {
	_converter.updateAlpha(alpha);
}

void ConvertController::updateVariableHSVShift (int hue, int saturation, int value) {
	_converter.updateVariableHSVShift(hue, saturation, value);
}

void ConvertController::updateVariableHueShift (int hue) {
	_converter.updateVariableHueShift(hue);
}
void ConvertController::updateVariableSaturationShift (int saturation) {
	_converter.updateVariableSaturationShift(saturation);
}
void ConvertController::updateVariableValueShift (int value) {
	_converter.updateVariableValueShift(value);
}

void ConvertController::setUpForCoffee() {
	_calibrator.setAverageUsedFlag(true);
	_converter.setOriginalValueUsedFlag(false);
}

void ConvertController::setUpForMaguro() {
	_calibrator.setAverageUsedFlag(false);
	_converter.setOriginalValueUsedFlag(true);
}
