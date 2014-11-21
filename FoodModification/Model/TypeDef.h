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
typedef vector<Point>            vP;

enum ChannelType {
    blue = 0,
    green = 1,
    red = 2,
    hue = 3,
    saturation = 4,
    value = 5,
    y = 6,
    cr = 7,
    cb = 8,
};

enum SpaceType {
	bgr = 0,
	hsv = 1,
	ycrcb = 2,
};

enum MediaType {
	no = 0,
    still = 1,
	movie = 2,
};

#endif // TYPEDEF_H
