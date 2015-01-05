#pragma once
#ifndef SAVER_H
#define SAVER_H

#include "../Manager/cameraManager.h"
#include "../Manager/windowManager.h"

class Saver {

/*method*/    
public:
	static Saver& getInstance();
    void save();
private:
    Saver();
    Saver(const Saver&);

/*property*/
private:
    WindowManager& _windowManager = WindowManager::getInstance();
    CameraManager& _cameraManager = CameraManager::getInstance();
};

#endif // SAVER_H
