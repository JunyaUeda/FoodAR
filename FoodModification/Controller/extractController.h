#ifndef EXTRACTCONTROLLER_H
#define EXTRACTCONTROLLER_H
#include "../Utils/opencvBase.h"
#include "../extractParamManager.h"
#include "../Service/colorExtractService.h"
#include "../Service/contourService.h"
#include "../Param/targetParam.h"
#include "../Service/edgeService.h"


class ExtractController {

public:
    static ExtractController& getInstance();
    ExtractController(ExtractParamManager *extractParamManager);
    void ExtractController::extract(Mat srcBGRImg, Mat srcHSVImg, Mat srcYCrCbImg, Mat srcGrayImg,
	Mat dstImg, vector<vector<Point>>& dstContours, Mat* BGRChannels);
    void extractByColor(Mat srcBGRImg, Mat srcHSVImg, Mat dstImg);
    void extractByContour(Mat srcGrayImg, Mat dstImg);
private:
    ExtractController();
    ExtractController(const ExtractController&);    
    void fillContours(Mat filledImg, vector<vector<Point> >& contours, int lineType, int minSize);
    void calcurateCenter(vector<vector<Point>>& contours, vector<Point>& mCenters);
    void getROI(Size size, Rect rect, Rect roi, double scaleRatio);
    void getIntegratedImage(Mat dstImg, Mat dstEdgeImg, Mat *Edges, vector<vector<Point> >& contours);
    void getAreaAndCenters(vector<vector<Point> >& contours, vector<double>& areas, vector<Point>& mCenters);
    void compAndFill(Mat dstImg, Mat dstEdgeImg, Mat *Edges, vector<vector<Point> >& contours, int lineType, int minSize);
    void selectContoursWithPoints(Mat srcImg, vector<vector<Point> >& selectedContours, vector<Point>& points, int minSize);
    void drawEdge(Mat srcImg, Mat edgeImg, int luminance);

    ExtractParamManager& extractParamManager = ExtractParamManager::getInstance();
    ColorExtractService* extractService;
    EdgeService* edgeService;
    ContourService* contourService;
    TargetParam* targetParam;

};

#endif // EXTRACTCONTROLLER_H
