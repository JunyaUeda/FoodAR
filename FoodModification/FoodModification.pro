#-------------------------------------------------
#
# Project created by QtCreator 2014-07-23T22:04:07
#
#-------------------------------------------------

QT       += core gui
QT += xml
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = FoodModification
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    finddialog.cpp \
    opencvManager.cpp \
    opencvBase.cpp \
    opencvUtils.cpp \
    colorCriterion.cpp \
    extractParamManager.cpp \
    extractController.cpp \
    colorExtractService.cpp \
    colorExtractTolerance.cpp \
    domParser.cpp \
    propertyController.cpp

HEADERS  += mainwindow.h \
    finddialog.h \
    opencvManager.h \
    opencvBase.h \
    opencvUtils.h \
    colorCriterion.h \
    extractParamManager.h \
    extractController.h \
    colorExtractService.h \
    colorExtractTolerance.h \
    domParser.h \
    propertyController.h

FORMS    += mainwindow.ui

# OpenCV settings
# for Windows
win32:DEPENDPATH  += "C:\opencv\build\include"
win32:INCLUDEPATH += "C:\opencv\build\include"
win32:LIBS += -L"C:\opencv\build\x86\vc10\lib"
win32:LIBS += -lopencv_core241 -lopencv_highgui241 -lopencv_imgproc241

OTHER_FILES += \
    param.txt \
    ExtractParam.xml
