#ifndef BINARIZATIONVIEWER_H
#define BINARIZATIONVIEWER_H

#include "./SDK/opencv/opencvApi.h"
#include "./Manager/cameraManager.h"

class BinarizationViewer {

/*method*/
public:
	BinarizationViewer();
	void showBinarizedImgs(int thresholds[]);
    void closeBinarizedImgs();
private:

/*property*/
private:
	bool _isShowing = true;
    CameraManager& _cameraManager = CameraManager::getInstance();
};

#endif // BINARIZATIONVIEWER_H
