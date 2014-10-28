#ifndef CALIBRATIONCONTROLLER_H
#define CALIBRATIONCONTROLLER_H
#include "../Utils/opencvUtils.h"
#include "../Param/calibrateClickParam.h"
#include "../Param/colorCriterion.h"
#include "../Param/colorExtractTolerance.h"
#include "../extractParamManager.h"
#include "../Service/calibrationService.h"
#include "./propertyController.h"

class CalibrationController {

public:
    static CalibrationController& getInstance();
    void calibrate_old();
    void calibrate(CalibrateClickParam* param);
    void autoCalibrate(Mat refImg, Mat maskImg, vector<Rect>& roiRects, ExtractParamManager* extractParamManager);
    void videoInput();
    void capture();
    void stopDrawing();
    
private:
    bool inputFlag = true;
    bool drawingFlag = true;
    CalibrateClickParam* clickParam;
    ExtractParamManager& extractParamManager = ExtractParamManager::getInstance();
    PropertyController& propertyController = PropertyController::getInstance();
    CalibrationService* calibrationService;

    CalibrationController();
    CalibrationController(const CalibrationController&);
    int calculateAverages(Mat srcImg, Mat refImg, int* result, Scalar color);
    void setHistogramArray(Mat srcImg, Mat refImg, int colorIndex, int* histogram, int histogramSize, Scalar color);
    void calculateTolerance(int* tolerance, int average, int pixcelNum, int* histogram);
    int setTolerance(Mat srcImg, Mat refImg,int* average,int pixcelNum, int colorIndex, int* tolerance, Scalar color);
    Mat getDistribution(Mat srcImg, Mat refImg, int pixelNum, Scalar color);
    void setExtractParam(Mat srcImg, Mat refImg, int colorSpaceIndex);
    void setExtractBGRParam(Mat srcImg, Mat refImg, Scalar color, int paramIndex);
    void setExtractHSVParam(Mat srcImg, Mat refImg, Scalar color, int paramIndex);
    //void my_button_cb(int state, void* userdata);
    
};

#endif // CALIBRATIONCONTROLLER_H
