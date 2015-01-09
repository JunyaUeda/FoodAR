#ifndef CONVERTCONTROLLER_H
#define CONVERTCONTROLLER_H

#include "Model/Util/cvUtil.h"
#include "../Model/Executor/converter.h"
#include "../Model/Executor/calibrator.h"

class ConvertController {

/*method*/	
public:
    static ConvertController& getInstance();
    void changeIntensityParam(bool change, int intensityFactor);
    void changeZParam(bool change, int ZFactor);
    void updateAlpha(double alpha);
    void updateVariableHSVShift (int hue, int saturation, int value);
    void setUpForCoffee();
    void setUpForMaguro();
private:
	ConvertController();
	ConvertController(const ConvertController&);
    int changeIllumination(int currentValue, double intensityFactor);

/*property*/
private:
    Converter& _converter = Converter::getInstance();//TODO : ConvertionManagerをかませたほうがよい。
    Calibrator& _calibrator = Calibrator::getInstance();
};

#endif // CONVERTCONTROLLER_H
