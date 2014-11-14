#ifndef REGION_H
#define REGION_H

#include "../TypeDef.h"

class Region {

/*property*/
private:
	Mat _maskImg;
    vPs _contours;

public:
    Region();
    Region(Size size);
    Mat maskImg() const;
    void setMaskImg(const Mat &maskImg);
    vPs contours() const;
    void setContours(const vPs &contours);
    void calcContours();
};

#endif // REGION_H
