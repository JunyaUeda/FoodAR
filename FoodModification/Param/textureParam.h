#ifndef TEXTUREPARAM_H
#define TEXTUREPARAM_H

class TextureParam
{
public:
    TextureParam();

    void setShift(int h_shift, int s_shift, int v_shift);

    int getH_shift();
    void setH_shift(int value);

    int getS_shift();
    void setS_shift(int value);

    int getV_shift();
    void setV_shift(int value);

    double getAlpha() const;
    void setAlpha(double value);

private:
    int h_shift = 0;
    int s_shift = 0;
    int v_shift = 0;
    double alpha = 0.4;
};

#endif // TEXTUREPARAM_H
