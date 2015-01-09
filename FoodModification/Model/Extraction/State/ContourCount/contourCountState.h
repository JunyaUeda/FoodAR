#ifndef CONTOURCOUNTSTATE_H
#define CONTOURCOUNTSTATE_H

#include "../../../TypeDef.h"
#include "../../../SDK/opencv/opencvApi.h"
#include "../../../Param/contours.h"
class ContourCountState {
public:
	ContourCountState();
    virtual void drawAndCalcRegion(Contours& contours)=0;
};

#endif // CONTOURCOUNTSTATE_H
