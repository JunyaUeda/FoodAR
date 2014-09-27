#include "textureParam.h"

TextureParam::TextureParam()
{
}

void TextureParam::setShift(int h_shift, int s_shift, int v_shift) {

	this->h_shift = h_shift;
	this->s_shift = s_shift;
	this->v_shift = v_shift;

}

int TextureParam::getH_shift() {

    return h_shift;

}

void TextureParam::setH_shift(int value)
{
    h_shift = value;
}

int TextureParam::getS_shift()
{
    return s_shift;
}

void TextureParam::setS_shift(int value)
{
    s_shift = value;
}

int TextureParam::getV_shift()
{
    return v_shift;
}

void TextureParam::setV_shift(int value)
{
    v_shift = value;
}

double TextureParam::getAlpha() const
{
    return alpha;
}

void TextureParam::setAlpha(double value)
{
    alpha = value;
}
