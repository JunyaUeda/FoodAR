#ifndef MAINCONTROLLER_H
#define MAINCONTROLLER_H
#include "opencv2/opencv.hpp"
#include "./extractController.h"
#include "../Utils/opencvUtils.h"
#include "./textureController.h"
#include "./convertController.h"

using namespace cv;
using namespace std;

class MainController {

private:
    ExtractController* extractController;
    TextureController* textureController;
    ConvertController* convertController;

public:
    MainController(ExtractParamManager *extractParamManager);
    void doConvertion();
    
};

#endif // MAINCONTROLLER_H
