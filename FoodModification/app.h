#ifndef APP_H
#define APP_H
#include <QApplication>
//#ifdef __DEBUG_PROPERTYLOADER
#include <iostream>
#include <stdio.h>
#include <fstream>
#include <vector>
#include <QDebug>
#include <QFile>
#include <QLabel>
#include <QPushButton>
#include <QTextStream>
#include <QHBoxLayout>
#include <QSlider>
#include <QSpinBox>
#include <QtCore>
#include "View/mainWindow.h"
#include "Controller/mainController.h"
#include "Controller/propertyController.h"
#include "Controller/calibrationController.h"
#include "Utils/opencvBase.h"
#include "extractParamManager.h"

#define FILEPATH "ExtractParam.xml"

class App
{
public:
    App();
    static QString getParamFilePath() {
        return FILEPATH;
	}
    int start(int argc, char *argv[]);

private:
    QString paramFilePath = FILEPATH;
    PropertyController& propertyController = PropertyController::getInstance();
    ExtractParamManager& extractParamManager = ExtractParamManager::getInstance();
	CalibrationController& calibrationController = CalibrationController::getInstance();
    MainController& mainController = MainController::getInstance();
    
};

#endif // APP_H
