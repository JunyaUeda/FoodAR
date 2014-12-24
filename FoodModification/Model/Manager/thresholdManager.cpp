#include "thresholdManager.h"

ThresholdManager::ThresholdManager() {

    //E404
    _binarizationThreshold[ChannelType::blue] = 50;  //Blue
    _binarizationThreshold[ChannelType::green] = 49;  //Green
    _binarizationThreshold[ChannelType::red] = 180;  //Red
    _binarizationThreshold[ChannelType::hue] = 45;  //Hue
    _binarizationThreshold[ChannelType::saturation] = 144; //Saturation
    _binarizationThreshold[ChannelType::value] = 180; //Value
    _binarizationThreshold[ChannelType::y] = 135;  //Y
    _binarizationThreshold[ChannelType::cr] = 190; //Cr
    _binarizationThreshold[ChannelType::cb] = 30;  //Cb

//      _binarizationThreshold[ChannelType::blue] = 50;  //Blue
//     _binarizationThreshold[ChannelType::green] = 33;  //Green
//     _binarizationThreshold[ChannelType::red] = 180;  //Red
//     _binarizationThreshold[ChannelType::hue] = 45;  //Hue
//     _binarizationThreshold[ChannelType::saturation] = 164; //Saturation
//     _binarizationThreshold[ChannelType::value] = 180; //Value
//     _binarizationThreshold[ChannelType::y] = 57;  //Y
//     _binarizationThreshold[ChannelType::cr] = 166; //Cr
//     _binarizationThreshold[ChannelType::cb] = 30;  //Cb
}

ThresholdManager& ThresholdManager::getInstance() {
    static ThresholdManager instance;
    return instance;
}