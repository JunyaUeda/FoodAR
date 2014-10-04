#include "edgeParam.h"

EdgeParam::EdgeParam()
{
}

int EdgeParam::cannyThreshold_1() const
{
	return _cannyThreshold_1;
}

void EdgeParam::setCannyThreshold_1(int cannyThreshold_1)
{
	_cannyThreshold_1 = cannyThreshold_1;
}

int EdgeParam::cannyThreshold_2() const
{
	return _cannyThreshold_2;
}

void EdgeParam::setCannyThreshold_2(int cannyThreshold_2)
{
	_cannyThreshold_2 = cannyThreshold_2;
}
