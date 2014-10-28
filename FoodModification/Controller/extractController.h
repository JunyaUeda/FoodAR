#ifndef EXTRACTCONTROLLER_H
#define EXTRACTCONTROLLER_H
#include "../Utils/opencvBase.h"
#include "../extractParamManager.h"
#include "../Service/contourService.h"
#include "../Service/colorExtractService.h"
#include "../Param/targetParam.h"
#include "../Service/edgeService.h"
#include "../definition.h"


class ExtractController {

public:
    static ExtractController& getInstance();
    void extract(Mat srcBGRImg, Mat srcHSVImg, Mat srcYCrCbImg, Mat srcGrayImg,
                                       Mat dstImg, vector<vector<Point> >& dstContours, Mat* edgeImgs);
    void extractByColor(Mat srcBGRImg, Mat srcHSVImg, Mat dstImg);
    void extractByContour(Mat srcGrayImg, Mat dstImg);
    
private:
    ExtractController();
    ExtractController(const ExtractController&);    
    void getIntegratedImage(Mat dstImg, Mat dstEdgeImg, Mat *Edges, vector<vector<Point> >& contours);
    
    ExtractParamManager& extractParamManager = ExtractParamManager::getInstance();
    ColorExtractService* _extractService;
    EdgeService* _edgeService;
    ContourService* _contourService;
    TargetParam* targetParam;

};

#endif // EXTRACTCONTROLLER_H
