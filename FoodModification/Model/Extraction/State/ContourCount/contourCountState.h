#ifndef CONTOURCOUNTSTATE_H
#define CONTOURCOUNTSTATE_H

#include "../../../TypeDef.h"
#include "../../../SDK/opencv/opencvApi.h"

class ContourCountState {
public:
	ContourCountState();
    virtual void drawAndCalcRegion(Mat& maskImg, vector<int>& indexiesOfTop3Area, vPs contours) {}
};

#endif // CONTOURCOUNTSTATE_H
