#ifndef COLORCRITERION_H
#define COLORCRITERION_H

class ColorCriterion {

private:
    int blue;
    int green;
    int red;
    int hue;
    int saturation;
    int value;
    int Y;
    int Cr;
    int Cb;
public:
    ColorCriterion();
    int getBlue() const;
    void setBlue(int value);
    int getGreen() const;
    void setGreen(int value);
    int getRed() const;
    void setRed(int value);
    int getHue() const;
    void setHue(int value);
    int getSaturation() const;
    void setSaturation(int value);
    int getValue() const;
    void setValue(int value);
    int getY() const;
    void setY(int value);
    int getCr() const;
    void setCr(int value);
    int getCb() const;
    void setCb(int value);
};

#endif // COLORCRITERION_H
