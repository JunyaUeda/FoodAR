#ifndef BGR3DPLOTCONTROLLER_H
#define BGR3DPLOTCONTROLLER_H

#include <QDebug>
#include "View/bgr3dPlotViewer.h"
#include "View/histogram3dViewer.h"
#include "Model/Manager/inputManager.h"
#include "Model/Manager/regionManager.h"
#include "Model/Param/bgrColor.h"
#include "Model/Param/xyzColor.h"
#include "Model/Param/xyYColor.h"
#include "Model/Util/cvUtil.h"
#include "Model/mainProcedure.h"

class BGR3DPlotController {
/*method*/
public:
    static BGR3DPlotController& getInstance();
    void prepareBGR3dPlot(BGR3dPlotViewer* viewer) {
        Mat bgrMat = _inputManager.currentBGRMat();
        vector<Point> points = _regionManager.previousPointList();
        for(Point point : points) {
            BGRColor color(B(bgrMat, point.x, point.y), G(bgrMat, point.x, point.y), R(bgrMat, point.x, point.y));
            viewer->addColorPoint(color);
        }

        
        _mainProcedure.stop();
   
        // vector<BGRColor> points;
        // BGRColor color(100,60,70);
        // points.push_back(color);
        // BGRColor color1(30,40, 50);
        // points.push_back(color1);
        // BGRColor color2(90,40,200);
        // points.push_back(color2);
        // BGRColor color3(150,40,90);
        // points.push_back(color3);
        // BGRColor color4(100,130,50);
        // points.push_back(color4);
        // BGRColor color5(70,80,90);
        // points.push_back(color5);

        //viewer->setColorList(points);
          
    }

    void prepare_xyHistogram(Histogram3dViewer* viewer) {
        Mat bgrMat = _inputManager.currentBGRMat();
        Mat XYZMat;
        if(bgrMat.empty()) {
            return;
        }
        cvtColor(bgrMat, XYZMat, CV_BGR2XYZ);
        vector<Point> points = _regionManager.previousPointList();
        vector<vector<int> > xyHistogram;
       xyHistogram = vector<vector<int> >(1000, vector<int>(1000, 0));
        for(Point point : points) {
            XYZColor color_XYZ(B(XYZMat, point.x, point.y), G(XYZMat, point.x, point.y), R(XYZMat, point.x, point.y));
            xyYColor color_xyY = color_XYZ.convert2xyY();
            viewer->addColorPoint(color_xyY);

            int result_x_Bin=0;
            int result_y_Bin=0;
            for(int xBin=0; xBin<1000; xBin++) {
                if(color_xyY.x*1000 > xBin ){
                    continue;
                } else {
                    result_x_Bin = xBin;
                    break;
                }
            }
            for(int yBin=0; yBin<1000; yBin++) {
                if(color_xyY.y*1000 > yBin ) {
                    continue;
                } else {
                    result_y_Bin = yBin;
                    break;
                }
            }
            xyHistogram[result_x_Bin][result_y_Bin]++;
        } 
        viewer->xyHistogram = xyHistogram;
    }
private:
	BGR3DPlotController();
    BGR3DPlotController(const BGR3DPlotController&);

/*property*/
private:
    InputManager& _inputManager = InputManager::getInstance();
    RegionManager& _regionManager = RegionManager::getInstance();
    MainProcedure& _mainProcedure = MainProcedure::getInstance();
};

#endif // BGR3DPLOTCONTROLLER_H

