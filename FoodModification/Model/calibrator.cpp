#include "calibrator.h"
#include <qDebug>


Calibrator::Calibrator() {
}

Calibrator& Calibrator::getInstance() {
	static Calibrator instance;
	return instance;
}

bool Calibrator::calibrate(Mat srcImg, Mat refImg, Scalar refColor) {

	QList<Point> region = _regionService->toPointList(refImg, refColor);
	MatSet matSet(srcImg);
	QVector<int> averages = _regionService->calculateAverage(&matSet, region);
	
 	QVector<int>::iterator it;
 	for(it = averages.begin(); it != averages.end(); ++it) {
 		qDebug() << "average =" << (*it);
 	}
 	
	return true;
}
