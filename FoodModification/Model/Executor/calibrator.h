#ifndef CALIBRATOR_H
#define CALIBRATOR_H

#include "../SDK/opencv/opencvApi.h"
#include "../Param/color.h"
#include "../Service/regionService.h"
#include "../Param/matSet.h"
#include "../featureReference.h"
#include "../TypeDef.h"
#include "../Param/region.h"
#include "../Executor/extractor.h"
#include "../Service/contourService.h"

class Calibrator {

/*mehthod*/
public:
    static Calibrator& getInstance();
    bool calibrate(Mat srcImg, Mat refImg, QVS refColor);
    void setAverageUsedFlag(bool flag) {
        _isAverageUsed = flag;
    }
private:
    Calibrator();
    Calibrator(const Calibrator&);

/*property*/
private:
    bool _isAverageUsed = false;
	RegionService* _regionService;
    ContourService* _contourService;
    FeatureReference&  _featureReference = FeatureReference::getInstance();
    Extractor& _extractor = Extractor::getInstance();//ここに依存関係は作るべきではない
};

#endif // CALIBRATOR_H
