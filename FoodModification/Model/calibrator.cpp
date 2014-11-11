#include "calibrator.h"
#include <qDebug>

Calibrator::Calibrator() {
}

bool Calibrator::calibrate(Mat srcImg, Mat refImg, Scalar refColor) {

	QList<Point> region = _regionService->toPointList(refImg, refColor);
	//QVector<int>* averages = _regionService->calculateAverage(srcImg, region);
	
 	//qDebug() << "average =" << (*averages)[0];
	return true;
}
