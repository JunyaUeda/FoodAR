#ifndef CAMERAMANAGER_H
#define CAMERAMANAGER_H

#include <QString>
#include "../SDK/opencv/opencvApi.h"
#include "manager.h"
#include "../Executor/extractor.h"

class CameraManager : public Manager {

/*method*/
public:
    VideoCapture _capture;
    static CameraManager& getInstance();
    bool setUp();
    void setCaptureSize(Size size);
    Size size() {
        return _size;
    }
    Mat& getFrame() {
        _capture >> _inputMat;
        return _inputMat;
    }
    void save(QXmlStreamWriter& writer);
private:
    CameraManager();
    CameraManager(const CameraManager&);
    void bindCamera(int port);
    
/*property*/
private:
    Size _size = Size(640, 480);
	Size _defaultSize = Size(640, 480);
    Mat _inputMat;
    Extractor& _extractor = Extractor::getInstance();

};

#endif // CAMERAMANAGER_H
