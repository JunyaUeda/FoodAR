    #ifndef CONVERTCONTROLLER_H
#define CONVERTCONTROLLER_H

#include "../Utils/opencvBase.h"
#include "../Param/textureParam.h"
#include "../Param/illuminationParam.h"

class ConvertController
{	
public:
    static ConvertController& getInstance();
    void changeIntensityParam(bool change, int intensityFactor);
    void changeZParam(bool change, int ZFactor);

private:
    IlluminationParam* _illuminationParam = new IlluminationParam();
	ConvertController();
	ConvertController(const ConvertController&);
    int changeIllumination(int currentValue, double intensityFactor);
};

#endif // CONVERTCONTROLLER_H
