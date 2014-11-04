#-------------------------------------------------
#
# Project created by QtCreator 2014-07-23T22:04:07
#
#-------------------------------------------------

QT       += core gui
QT += xml
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

QMAKE_MACOSX_DEPLOYMENT_TARGET = 10.9
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
    Controller/convertController.cpp \
    Service/calibrationService.cpp \
    View/colorDialog.cpp \
    Param/textureParam.cpp \
    Utils/xmlUtils.cpp \
    Param/illuminationParam.cpp \
    Controller/edgeController.cpp \
    Param/edgeParam.cpp \
    Controller/srcController.cpp \
    Param/srcParam.cpp \
    Param/cannyThreshold.cpp \
    Param/Features/feature.cpp \
    Param/References/reference.cpp \
    Controller/baseController.cpp \
    Controller/File/fileController.cpp \
    Controller/singleton.cpp \
    Model/features.cpp \
    Model/Param/color.cpp \
    Model/Param/channel.cpp \
    Model/extractParam.cpp \
    Model/xmlReader.cpp \
    Model/featureReference.cpp \
    Model/Param/threshold.cpp \
    Model/Param/channelThreshold.cpp \
    Model/Param/channelType.cpp

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
    Controller/convertController.h \
    Service/calibrationService.h \
    View/colorDialog.h \
    Param/textureParam.h \
    Utils/xmlUtils.h \
    Param/illuminationParam.h \
    Controller/edgeController.h \
    Param/edgeParam.h \
    definition.h \
    Controller/srcController.h \
    Param/srcParam.h \
    Param/cannyThreshold.h \
    Param/Features/feature.h \
    Param/References/reference.h \
    Controller/baseController.h \
    Controller/File/fileController.h \
    Controller/singleton.h \
    Model/features.h \
    Model/Param/color.h \
    Model/Param/channel.h \
    Model/extractParam.h \
    Model/xmlReader.h \
    Model/featureReference.h \
    Model/Param/threshold.h \
    Model/Param/channelThreshold.h \
    Model/Param/channelType.h

FORMS    += \
    View/calibrateDialog.ui \
    View/mainWindow.ui \
    View/colorDialog.ui

# OpenCV settings
# for Windows
#win32:DEPENDPATH  += "C:\opencv248\build\include"
#win32:INCLUDEPATH += "C:\opencv248\build\include"
#win32:LIBS += -L"C:\opencv248\build\x86\vc12\lib"
# for Mac
INCLUDEPATH += /usr/local/include
DEPENDPATH += /usr/local/include
LIBS += -L/usr/local/lib \
    -lopencv_core \
    -lopencv_imgproc \
    -lopencv_highgui \
    -lopencv_objdetect \
    -lopencv_calib3d

OTHER_FILES += \
    ExtractParam.xml \
    Images/hamachi.jpg \
    Images/otoro.jpg \
    Images/sarmon.jpg \
    Images/toro.jpg
