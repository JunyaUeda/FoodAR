#ifndef BINARIZATIONVIEWER_H
#define BINARIZATIONVIEWER_H

#include "./SDK/opencv/opencvApi.h"

class BinarizationViewer {

/*method*/
public:
	BinarizationViewer();
    void showBinarizedImgs();
    void closeBinarizedImgs();
private:

/*property*/
private:
	bool BinarizationViewer::_isShowing = true;
};

#endif // BINARIZATIONVIEWER_H
