#ifndef COLORCRITERION_H
#define COLORCRITERION_H

class ColorCriterion {
public:
    ColorCriterion();
private:
    int hue;
    int saturation;
    int value;
    int Y;
    int Cr;
    int Cb;
public:
    int getHue() {
        return this->hue;
    }
    void setHue(int hue) {
        this->hue = hue;
    }
    int getSaturation() {
        return this->saturation;
    }
    void setSaturation(int saturation) {
        this->saturation = saturation;
    }
    int getValue() {
        return this->value;
    }
    void setValue(int value) {
        this->value = value;
    }
    int getY() {
        return this->Y;
    }
    void setY(int Y){
        this->Y = Y;
    }
    int getCr() {
        return Cr;
    }
    void setCr(int Cr) {
        this->Cr = Cr;
    }
    int getCb() {
        return Cb;
    }
    void setCb(int Cb) {
        this->Cb = Cb;
    }
};

#endif // COLORCRITERION_H
