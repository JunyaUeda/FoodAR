#ifndef BGR3DPLOTCONTROLLER_H
#define BGR3DPLOTCONTROLLER_H

#include <QDebug>
#include "../View/bgr3dPlotViewer.h"
#include "../Model/Manager/inputManager.h"
#include "../Model/Manager/regionManager.h"
#include "../Model/Param/bgrColor.h"
#include "../Model/Util/cvUtil.h"

class BGR3DPlotController {
/*method*/
public:
    static BGR3DPlotController& getInstance();
    void prepareBGR3dPlot(BGR3dPlotViewer& _viewer) {
        // Mat bgrMat = _inputManager.currentBGRMat();
        // vector<Point> points = _regionManager.previousPointList();
        // for(Point point : points) {
        //     BGRColor color(B(bgrMat, point.x, point.y), G(bgrMat, point.x, point.y), R(bgrMat, point.x, point.y));
        //     _viewer.addColorPoint(color);
        // }

        
        
            // BGRColor color(100,60,70);
            // _viewer.addColorPoint(color);
            // BGRColor color1(30,40, 50);
            // _viewer.addColorPoint(color1);
            // BGRColor color2(90,40,200);
            // _viewer.addColorPoint(color2);
            // BGRColor color3(150,40,90);
            // _viewer.addColorPoint(color3);
            // BGRColor color4(100,130,50);
            // _viewer.addColorPoint(color4);
            // BGRColor color5(70,80,90);
            // _viewer.addColorPoint(color5);

        vector<BGRColor> points;
        BGRColor color(100,60,70);
        points.push_back(color);
        BGRColor color1(30,40, 50);
        points.push_back(color1);
        BGRColor color2(90,40,200);
        points.push_back(color2);
        BGRColor color3(150,40,90);
        points.push_back(color3);
        BGRColor color4(100,130,50);
        points.push_back(color4);
        BGRColor color5(70,80,90);
        points.push_back(color5);

        _viewer.setColorList(points);
          
    }
private:
	BGR3DPlotController();
    BGR3DPlotController(const BGR3DPlotController&);

/*property*/
private:
    InputManager& _inputManager = InputManager::getInstance();
    RegionManager& _regionManager = RegionManager::getInstance();
};

#endif // BGR3DPLOTCONTROLLER_H

