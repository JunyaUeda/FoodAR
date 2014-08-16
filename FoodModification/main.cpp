#include "mainwindow.h"
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
#include "finddialog.h"
#include "ImgProc\\opencvManager.h"
#include <QtCore>
#include "propertyController.h"
#include "./ImgProc/opencvBase.h"

#define FILEPATH ".\\ExtractParam.xml"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    MainWindow w;

    QWidget *window = new QWidget;
    window->setWindowTitle("Enter your feel");


    QSpinBox *spinBox = new QSpinBox;
    spinBox->setRange(0,130);
    QSlider *slider = new QSlider(Qt::Horizontal);
    slider->setRange(0,130);
    QObject::connect(spinBox,SIGNAL(valueChanged(int)),slider,SLOT(setValue(int)));
    QObject::connect(slider,SIGNAL(valueChanged(int)),spinBox, SLOT(setValue(int)));
    spinBox->setValue(35);
    QHBoxLayout *layout = new QHBoxLayout;
    layout->addWidget(spinBox);
    layout->addWidget(slider);
    window->setLayout(layout);
    window->show();
    qDebug() << "Debug Message";
    qWarning() << "Warning Message";
    qCritical() << "Critical Error Message";
    

    FindDialog *dialog = new FindDialog;
    dialog->show();

    QString filePath = FILEPATH;
    PropertyController* propertyController = new PropertyController(filePath);

    qDebug() << propertyController->getExtractParamManager()->criterion[0].getHue();
    qDebug() << propertyController->getExtractParamManager()->criterion[1].getHue();
    qDebug() << propertyController->getExtractParamManager()->colorExtractTolerance[0].getHueTolerance();
    qDebug() << propertyController->getExtractParamManager()->colorExtractTolerance[1].getHueTolerance();


   OpenCVManager *manager = new OpenCVManager(propertyController->getExtractParamManager());
   manager->doConvertion();

   return app.exec();
   
}
