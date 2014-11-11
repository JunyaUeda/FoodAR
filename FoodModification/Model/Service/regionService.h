#ifndef REGIONSERVICE_H
#define REGIONSERVICE_H

#include <QVector>
#include "../SDK/opencv/opencvApi.h"
#include "../Param/color.h"
#include "../Param/channel.h"
#include "../Param/matSet.h"

class RegionService {

/*method*/
public:
    RegionService();
    QVector<int> calculateAverage(const MatSet* matSet, QList<Point> region);
    QVector<int> calculateAverage(Mat srcBGRImg, QList<Point> region);
    QVector<int> calculateTolerance(Mat srcBGRImg, QList<Point> region);
    QList<Point> toPointList(Mat refImg, Scalar refColor);
private:
	QVector<int> countSum(const MatSet* matSet, QList<Point> region);
	QVector<int> countSum(Mat srcBGRImg, QList<Point> region);
	QVector<int> countSum(Mat srcBGRImg, Mat refImg, Scalar refColor);
    QVector<QVector<int> > createHistogram(const MatSet* matSet, QList<Point> region);
	QVector<QVector<int> > createHistogram(Mat srcBGRImg, QList<Point> region);
};
#endif // REGIONSERVICE_H
