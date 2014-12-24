#ifndef XYYCOLOR_H
#define XYYCOLOR_H

class xyYColor {
/*method*/
public:
	xyYColor();
    xyYColor(double xValue, double yValue, double YValue) {
        x = xValue;
        y = yValue;
        Y = YValue;
    }

/*property*/
public:
    double x;
    double y;
    double Y;
};

#endif // XYYCOLOR_H
