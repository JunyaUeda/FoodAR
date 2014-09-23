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
#include "View/mainWindow.h"
#include "Controller/mainController.h"
#include <QtCore>
#include "Controller/propertyController.h"
#include "Utils/opencvBase.h"
#include "extractParamManager.h"

#define FILEPATH "ExtractParam.xml"

class App
{
public:
	ExtractParamManager* extractParamManager;
	PropertyController* propertyController;
	CalibrationController* calibrationController;
    MainController* mainController;
public:
    App();
    int start(int argc, char *argv[]);
};

#endif // APP_H
