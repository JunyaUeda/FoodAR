#ifndef XYZCOLOR_H
#define XYZCOLOR_H

#include "./xyYColor.h"

class XYZColor {
/*method*/
public:
	XYZColor();
    XYZColor(double xValue, double yValue, double zValue) {
        X = xValue;
        Y = yValue;
        Z = zValue;
    }

    xyYColor convert2xyY() {
        xyYColor result;
        result.x = X/(X+Y+Z);
        result.y = Y/(X+Y+Z);
        result.Y = Y;

        return result;
    }
/*property*/
public:
    double X;
    double Y;
    double Z;
};

#endif // XYZCOLOR_H
