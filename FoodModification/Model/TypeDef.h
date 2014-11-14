#ifndef TYPEDEF_H
#define TYPEDEF_H
#include <QVector>
#include <QList>
#include "./SDK/opencv/opencvApi.h"

using namespace cv;
using namespace std;

typedef QVector<int>            QVi;
typedef QVector<QVector<int> >  QVis;
typedef QList<Point>            QLP;
typedef QList<QList<Point> >    QLPs;
typedef QVector<Scalar>         QVS;
typedef vector<vector<Point> >  vPs;

#endif // TYPEDEF_H
