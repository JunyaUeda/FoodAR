#ifndef CALIBRATIONCONTROLLER_H
#define CALIBRATIONCONTROLLER_H
#include "../Utils/opencvUtils.h"
#include "../Param/calibrateClickParam.h"
#include "../Param/colorCriterion.h"
#include "../Param/colorExtractTolerance.h"
#include "../extractParamManager.h"

class CalibrationController {

private:
	bool inputFlag = true;
	bool drawingFlag = true;
    CalibrateClickParam* clickParam;
    ExtractParamManager* extractParamManager;

public:
    CalibrationController(ExtractParamManager* extractParamManager);
    void calibrate();
    void videoInput();
    void capture();
    void stopDrawing();

private:
    int calculateAverages(cv::Mat srcImg, cv::Mat refImg, int* result, cv::Scalar color);
    void setHistogramArray(cv::Mat srcImg, cv::Mat refImg, int colorIndex, int* histogram, int histogramSize, cv::Scalar color);
    void calculateTolerance(int* tolerance, int average, int pixcelNum, int* histogram);
    int setTolerance(cv::Mat srcImg, cv::Mat refImg,int* average,int pixcelNum,int colorIndex, int* tolerance, cv::Scalar color);
    cv::Mat getDistribution(cv::Mat srcImg, cv::Mat refImg, int pixelNum, cv::Scalar color);
    void CalibrationController::setExtractParam(cv::Mat srcImg, cv::Mat refImg, int colorSpaceIndex);
    void CalibrationController::setExtractBGRParam(cv::Mat srcImg, cv::Mat refImg, cv::Scalar color, int paramIndex);
    void CalibrationController::setExtractHSVParam(cv::Mat srcImg, cv::Mat refImg, cv::Scalar color, int paramIndex);
    
};

#endif // CALIBRATIONCONTROLLER_H
