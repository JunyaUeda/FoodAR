#ifndef EXTRACTCONTROLLER_H
#define EXTRACTCONTROLLER_H
#include "../Utils/opencvBase.h"
#include "../extractParamManager.h"
#include "../Service/colorExtractService.h"
#include "../Service/contourService.h"
#include "../Param/targetParam.h"
#include "../Service/edgeService.h"

using namespace cv;
using namespace std;

class ExtractController {

private:
    ExtractParamManager* extractParamManager;
    ColorExtractService* extractService;
    EdgeService* edgeService;
    ContourService* contourService;
    TargetParam* targetParam;

public:
    ExtractController(ExtractParamManager *extractParamManager);
    void ExtractController::extract(Mat srcBGRImg, Mat srcHSVImg, Mat srcYCrCbImg, Mat srcGrayImg,
	Mat dstImg, vector<vector<Point>>& dstContours, Mat* BGRChannels);
    void extractByColor(Mat srcBGRImg, Mat srcHSVImg, Mat dstImg);
    void extractByContour(Mat srcGrayImg, Mat dstImg);
private:    
    void fillContours(Mat filledImg, vector<vector<Point> >& contours, int lineType, int minSize);
    void calcurateCenter(vector<vector<Point>>& contours, vector<Point>& mCenters);
    void getROI(Size size, Rect rect, Rect roi, double scaleRatio);
    void getIntegratedImage(Mat dstImg, Mat dstEdgeImg, Mat *Edges, vector<vector<Point> >& contours);
    void getAreaAndCenters(vector<vector<Point> >& contours, vector<double>& areas, vector<Point>& mCenters);
    void compAndFill(Mat dstImg, Mat dstEdgeImg, Mat *Edges, vector<vector<Point> >& contours, int lineType, int minSize);
    void selectContoursWithPoints(Mat srcImg, vector<vector<Point> >& selectedContours, vector<Point>& points, int minSize);
    void drawEdge(Mat srcImg, Mat edgeImg, int luminance);

};

#endif // EXTRACTCONTROLLER_H
