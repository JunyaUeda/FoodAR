#ifndef THRESHOLDMANAGER_H
#define THRESHOLDMANAGER_H

#include "../TypeDef.h"
#define NUM_OF_CHANNEL 9

class ThresholdManager {
/*method*/
public:
    static ThresholdManager& getInstance();
    
    void updateBinarizationThreshold(int value ,int index) {
        _binarizationThreshold[index] = value;
    }

	int b() {
        return _binarizationThreshold[ChannelType::blue];
    }
    int g() {
        return _binarizationThreshold[ChannelType::green];
    }
    int r() {
        return _binarizationThreshold[ChannelType::red];
    }
    int h() {
        return _binarizationThreshold[ChannelType::hue];
    }
    int s() {
        return _binarizationThreshold[ChannelType::saturation];
    }
    int v() {
        return _binarizationThreshold[ChannelType::value];
    }
    int y() {
        return _binarizationThreshold[ChannelType::y];
    }
    int cr() {
        return _binarizationThreshold[ChannelType::cr];
    }
    int cb() {
        return _binarizationThreshold[ChannelType::cb];
    }
private:
    ThresholdManager();
    ThresholdManager(const ThresholdManager&);

/*property*/
private:
    int _binarizationThreshold[NUM_OF_CHANNEL];
};

#endif // THRESHOLDMANAGER_H
