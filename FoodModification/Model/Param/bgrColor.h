#ifndef BGRCOLOR_H
#define BGRCOLOR_H

class BGRColor {
/*method*/
public:
	BGRColor();
    BGRColor(int bValue, int gValue, int rValue) {
        b = bValue;
        g = gValue;
        r = rValue;
    }
/*property*/
public:
    int b;
    int g;
    int r;
};

#endif // BGRCOLOR_H
