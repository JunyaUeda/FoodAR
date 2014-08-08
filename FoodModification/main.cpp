#include "mainwindow.h"
#include <QApplication>
//#ifdef __DEBUG_PROPERTYLOADER
#include <iostream>
#include <stdio.h>
#include <fstream>
#include <stdio.h>
#include <QDebug>
#include <QFile>
#include <QLabel>
#include <QPushButton>
#include <QTextStream>
#include <QHBoxLayout>
#include <QSlider>
#include <QSpinBox>
#include "finddialog.h"
#include "opencvManager.h"
#include <QtCore>
#include "propertyController.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    MainWindow w;

//    QLabel *label = new QLabel("HelloEveryone",0);
//    label->show();
//    QPushButton *button = new QPushButton("quit");
//    QObject::connect(button,SIGNAL(clicked()),&app,SLOT(quit()));
//    button->show();
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
    //qFatal() << "Fatal Error Message";

    FindDialog *dialog = new FindDialog;
    dialog->show();

    ExtractParamManager *extractParamManager = new ExtractParamManager;
    PropertyController *propertyController = new PropertyController(extractParamManager);
    QString filePath ="C:\\cygwin64\\home\\ueda\\git\\VisualTextureC\\FoodModification\\FoodModification\\ExtractParam.xml";
    propertyController->readParameters(filePath);

    qDebug() << extractParamManager->criterion[0]->getHue();
    qDebug() << extractParamManager->criterion[1]->getHue();

   // OpenCVManager *manager = new OpenCVManager(extractParamManager);
   // manager->doConvertion();
    return app.exec();
}
