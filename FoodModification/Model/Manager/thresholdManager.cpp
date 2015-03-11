#include "thresholdManager.h"

ThresholdManager::ThresholdManager() {

    //E404
	_binarizationThreshold[ChannelType::blue] = 90;  //Blue
	_binarizationThreshold[ChannelType::green] = 115;  //Green
	_binarizationThreshold[ChannelType::red] = 195;  //Red
    _binarizationThreshold[ChannelType::hue] = 45;  //Hue
	_binarizationThreshold[ChannelType::saturation] = 110; //Saturation
    _binarizationThreshold[ChannelType::value] = 195; //Value
	_binarizationThreshold[ChannelType::y] = 110;  //Y
	_binarizationThreshold[ChannelType::cr] = 150; //Cr
	_binarizationThreshold[ChannelType::cb] = 120;  //Cb

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
