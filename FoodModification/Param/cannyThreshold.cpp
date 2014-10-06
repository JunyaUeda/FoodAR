#include "cannyThreshold.h"

CannyThreshold::CannyThreshold() {
}

CannyThreshold::CannyThreshold(int value1, int value2) {
	_value1 = value1;
	_value2 = value2;
}

int CannyThreshold::value1() const {
	return _value1;
}

void CannyThreshold::setValue1(int value1) {
	_value1 = value1;
}

int CannyThreshold::value2() const {
	return _value2;
}

void CannyThreshold::setValue2(int value2) {
	_value2 = value2;
}
