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
    void setCaptureSaturation(double value);
    void setCaptureExposure(double value);
    void setCaptureGain(double value);
    void setCaptureBrightness(double value);
    void setCaptureContrast(double value);
    Size size() { return _size; }
    Mat& getFrame() {
        _capture.set(CV_CAP_PROP_SATURATION, _captureSaturation);
        _capture.set(CV_CAP_PROP_EXPOSURE, _captureExposure);
        _capture.set(CV_CAP_PROP_GAIN, _captureGain);
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
    double _captureSaturation = 255.0;
    double _captureExposure = -5.0;
    double _captureGain = 30.0;
    double _captureBrightness = 128.0;
    double _captureContrast = 100.0;

    Mat _inputMat;
    Extractor& _extractor = Extractor::getInstance();

};

#endif // CAMERAMANAGER_H
