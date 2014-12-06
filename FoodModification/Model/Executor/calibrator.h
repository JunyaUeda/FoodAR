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

class Calibrator {

/*mehthod*/
public:
    static Calibrator& getInstance();
    bool calibrate(Mat srcImg, Mat refImg, QVS refColor);
private:
    Calibrator();
    Calibrator(const Calibrator&);

/*property*/
private:
	RegionService* _regionService;
    FeatureReference&  _featureReference = FeatureReference::getInstance();
    Extractor& _extractor = Extractor::getInstance();//ここに依存関係は作るべきではない
};

#endif // CALIBRATOR_H
