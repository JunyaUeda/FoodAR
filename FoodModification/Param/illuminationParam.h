#ifndef ILLUMINATIONPARAM_H
#define ILLUMINATIONPARAM_H

class IlluminationParam
{
public:
    IlluminationParam();
    

    double intensityFactor() const;
    void setIntensityFactor(double intensityFactor);

    bool intensityChange() const;
    void setIntensityChange(bool intensityChange);

    bool ZChange() const;
    void setZChange(bool ZChange);

    double ZFactor() const;
    void setZFactor(double ZFactor);

private:
    bool _intensityChange = false;
    double _intensityFactor;
    bool _ZChange = false;
    double _ZFactor;
};

#endif // ILLUMINATIONPARAM_H
