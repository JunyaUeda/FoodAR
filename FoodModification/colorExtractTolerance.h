#ifndef COLOREXTRACTTOLERANCE_H
#define COLOREXTRACTTOLERANCE_H

class ColorExtractTolerance {
private:
    int hueTolerance;
    int saturationTolerance;
    int valueTolerance;
    int crTolerance;

public:

    ColorExtractTolerance();

    int getHueTolerance() {
        return hueTolerance;
    }

    void setHueTolerance(int hueTolerance) {
        this->hueTolerance = hueTolerance;
    }

    int getSaturationTolerance() {
        return saturationTolerance;
    }

    void setSaturationTolerance(int saturationTolerance) {
        this->saturationTolerance = saturationTolerance;
    }

    int getValueTolerance() {
        return valueTolerance;
    }

    void setValueTolerance() {
        this->valueTolerance;
    }

    int getCrTolerance() {
        return crTolerance;
    }

    void setCrTolerance(int crTolerance) {
        this->crTolerance = crTolerance;
    }
};

#endif // COLOREXTRACTTOLERANCE_H
