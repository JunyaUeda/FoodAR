#include "illuminationParam.h"

IlluminationParam::IlluminationParam()
{
}


double IlluminationParam::intensityFactor() const
{
    return _intensityFactor;
}

void IlluminationParam::setIntensityFactor(double intensityFactor)
{
    _intensityFactor = intensityFactor;
}

bool IlluminationParam::intensityChange() const
{
    return _intensityChange;
}

void IlluminationParam::setIntensityChange(bool intensityChange)
{
    _intensityChange = intensityChange;
}

bool IlluminationParam::ZChange() const
{
    return _ZChange;
}

void IlluminationParam::setZChange(bool ZChange)
{
    _ZChange = ZChange;
}

double IlluminationParam::ZFactor() const
{
    return _ZFactor;
}

void IlluminationParam::setZFactor(double ZFactor)
{
    _ZFactor = ZFactor;
}
