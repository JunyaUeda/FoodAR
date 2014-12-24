#include "thresholdManager.h"

ThresholdManager::ThresholdManager() {
    _binarizationThreshold[ChannelType::blue] = 50;  //Blue
    _binarizationThreshold[ChannelType::green] = 90;  //Green
    _binarizationThreshold[ChannelType::red] = 180;  //Red
    _binarizationThreshold[ChannelType::hue] = 45;  //Hue
    _binarizationThreshold[ChannelType::saturation] = 164; //Saturation
    _binarizationThreshold[ChannelType::value] = 180; //Value
    _binarizationThreshold[ChannelType::y] = 127;  //Y
    _binarizationThreshold[ChannelType::cr] = 172; //Cr
    _binarizationThreshold[ChannelType::cb] = 30;  //Cb
}

ThresholdManager& ThresholdManager::getInstance() {
    static ThresholdManager instance;
    return instance;
}