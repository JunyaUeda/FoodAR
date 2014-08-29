#ifndef COLOREXTRACTTOLERANCE_H
#define COLOREXTRACTTOLERANCE_H

class ColorExtractTolerance {
private:
    int hueHighTolerance;
    int hueLowTolerance;
    int saturationHighTolerance;
    int saturationLowTolerance;
    int valueHighTolerance;
    int valueLowTolerance;

    int blueHighTolerance;
    int blueLowTolerance;
    int greenHighTolerance;
    int greenLowTolerance;
    int redHighTolerance;
    int redLowTolerance;

public:

    ColorExtractTolerance();
    
    int getHueHighTolerance() const;
    void setHueHighTolerance(int value);
    int getHueLowTolerance() const;
    void setHueLowTolerance(int value);
    int getSaturationHighTolerance() const;
    void setSaturationHighTolerance(int value);
    int getSaturationLowTolerance() const;
    void setSaturationLowTolerance(int value);
    int getValueHighTolerance() const;
    void setValueHighTolerance(int value);
    int getValueLowTolerance() const;
    void setValueLowTolerance(int value);
    int getBlueHighTolerance() const;
    void setBlueHighTolerance(int value);
    int getBlueLowTolerance() const;
    void setBlueLowTolerance(int value);
    int getGreenHighTolerance() const;
    void setGreenHighTolerance(int value);
    int getGreenLowTolerance() const;
    void setGreenLowTolerance(int value);
    int getRedHighTolerance() const;
    void setRedHighTolerance(int value);
    int getRedLowTolerance() const;
    void setRedLowTolerance(int value);
};

#endif // COLOREXTRACTTOLERANCE_H
