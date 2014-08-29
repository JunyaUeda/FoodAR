#include "colorCriterion.h"

ColorCriterion::ColorCriterion() {
}

int ColorCriterion::getBlue() const
{
    return blue;
}

void ColorCriterion::setBlue(int value)
{
    blue = value;
}

int ColorCriterion::getGreen() const
{
    return green;
}

void ColorCriterion::setGreen(int value)
{
    green = value;
}

int ColorCriterion::getRed() const
{
    return red;
}

void ColorCriterion::setRed(int value)
{
    red = value;
}
