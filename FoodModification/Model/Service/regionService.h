#ifndef REGIONSERVICE_H
#define REGIONSERVICE_H

#include <QVector>
#include "../SDK/opencv/opencvApi.h"
#include "../Param/color.h"
#include "../Param/channel.h"
#include "../Param/matSet.h"
#include "../TypeDef.h"

class RegionService {

/*method*/
public:
    RegionService();
    QVis calcAverages(const MatSet& matSet, QLPs regions);
    QVis calcTolerances(const MatSet& matSet, QLPs regions, QVis averages);
    QLPs toPointList(Mat refImg, QVS refColor);
private:
    QLP toPointList(Mat refImg, Scalar refColor);
    QVi calcAverage(const MatSet& matSet, QLP region);
    QVi calcAverage(Mat srcBGRImg, QLP region);
	QVi countSum(const MatSet& matSet, QLP region);
	QVi countSum(Mat srcBGRImg, QLP region);
	QVi countSum(Mat srcBGRImg, Mat refImg, Scalar refColor);
    QVi calcTolerance(const MatSet& matSet, QLP region, QVi averages);
    QVis createHistogram(const MatSet& matSet, QLP region);
	QVis createHistogram(Mat srcBGRImg, QLP region);
    int findTolerance(int average, QVi histogram, int pixcelNum);
};
#endif // REGIONSERVICE_H
