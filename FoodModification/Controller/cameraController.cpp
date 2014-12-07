#include "cameraController.h"

CameraController::CameraController() {
}

CameraController& CameraController::getInstance() {
    static CameraController instance;
    return instance;
}

void CameraController::setCaptureSize(Size size) {
    _cameraManager.setCaptureSize(size);
}

void CameraController::setCaptureSaturation(double value) {
    _cameraManager.setCaptureSaturation(value);
}

void CameraController::setCaptureExposure(double value) {
    _cameraManager.setCaptureExposure(value);
}

void CameraController::setCaptureGain(double value) {
    _cameraManager.setCaptureGain(value);
}

void CameraController::setCaptureBrightness(double value) {
    _cameraManager.setCaptureBrightness(value);
}

void CameraController::setCaptureContrast(double value) {
    _cameraManager.setCaptureContrast(value);
}