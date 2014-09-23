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
    extractParamManager.cpp \
    Param/colorCriterion.cpp \
    Param/colorExtractTolerance.cpp \
    View/calibrateDialog.cpp \
    Param/calibrateClickParam.cpp \
    app.cpp \
    Controller/extractController.cpp \
    Param/targetParam.cpp \
    Service/colorExtractService.cpp \
    Service/contourService.cpp \
    Service/edgeService.cpp \
    Utils/opencvBase.cpp \
    Utils/opencvUtils.cpp \
    Controller/calibrationController.cpp \
    Controller/propertyController.cpp \
    View/mainWindow.cpp \
    Controller/mainController.cpp \
    Service/textureService.cpp \
    Controller/textureController.cpp \
    Controller/convertController.cpp

HEADERS  += \
    extractParamManager.h \
    Param/colorCriterion.h \
    Param/colorExtractTolerance.h \
    View/calibrateDialog.h \
    Param/calibrateClickParam.h \
    app.h \
    Controller/extractController.h \
    Param/targetParam.h \
    Service/colorExtractService.h \
    Service/contourService.h \
    Service/edgeService.h \
    Utils/opencvBase.h \
    Utils/opencvUtils.h \
    Controller/calibrationController.h \
    Controller/propertyController.h \
    View/mainWindow.h \
    Controller/mainController.h \
    Service/textureService.h \
    Controller/textureController.h \
    Controller/convertController.h

FORMS    += \
    View/calibrateDialog.ui \
    View/mainWindow.ui

# OpenCV settings
# for Windows
win32:DEPENDPATH  += "C:\opencv248\build\include"
win32:INCLUDEPATH += "C:\opencv248\build\include"
win32:LIBS += -L"C:\opencv248\build\x86\vc12\lib"
#win32:LIBS += -lopencv_core248d -lopencv_highgui248d -lopencv_imgproc248d

OTHER_FILES += \
    ExtractParam.xml \
    Images/hamachi.jpg \
    Images/otoro.jpg \
    Images/sarmon.jpg \
    Images/toro.jpg
