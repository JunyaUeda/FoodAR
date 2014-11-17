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
    Model/extractParam.cpp \
    Model/xmlReader.cpp \
    Model/featureReference.cpp \
    Model/Param/threshold.cpp \
    Model/Param/channelThreshold.cpp \
    Model/calibrator.cpp \
    Model/Service/regionService.cpp \
    Model/SDK/opencv/opencvApi.cpp \
    Model/Param/channel.cpp \
    Model/Param/source.cpp \
    Model/Param/channelHistogram.cpp \
    Model/Param/matSet.cpp \
    Model/Param/colorThreshold.cpp \
    Model/extractor.cpp \
    Model/Param/region.cpp \
    Model/Param/edge.cpp \
    Model/Service/colorService.cpp \
    Model/Service/extractService.cpp \
    Model/Param/channelFunc/channelFunc.cpp \
    Model/Param/channelFunc/blueFunc.cpp \
    Model/Param/channelFunc/cbFunc.cpp \
    Model/Param/channelFunc/crFunc.cpp \
    Model/Param/channelFunc/greenFunc.cpp \
    Model/Param/channelFunc/hueFunc.cpp \
    Model/Param/channelFunc/redFunc.cpp \
    Model/Param/channelFunc/saturationFunc.cpp \
    Model/Param/channelFunc/valueFunc.cpp \
    Model/Param/channelFunc/yFunc.cpp \
    Model/Param/spaceFunc/colorSpaceFunc.cpp \
    Model/Param/spaceFunc/bgrFunc.cpp \
    Model/Param/spaceFunc/hsvFunc.cpp \
    Model/Param/spaceFunc/ycrcbFunc.cpp \
    Model/condition.cpp \
    Model/Service/edgeService.cpp

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
    Model/Param/channelType.h \
    Model/calibrator.h \
    Model/Service/regionService.h \
    Model/SDK/opencv/opencvApi.h \
    Model/Param/colorSpaceType.h \
    Model/Param/channel.h \
    Model/Param/source.h \
    Model/Param/channelHistogram.h \
    Model/Param/matSet.h \
    Model/TypeDef.h \
    Model/Param/colorThreshold.h \
    Model/extractor.h \
    Model/Param/region.h \
    Model/Param/edge.h \
    Model/Service/colorService.h \
    Model/Service/extractService.h \
    Model/Param/channelFunc/channelFunc.h \
    Model/Param/channelFunc/blueFunc.h \
    Model/Param/channelFunc/cbFunc.h \
    Model/Param/channelFunc/crFunc.h \
    Model/Param/channelFunc/greenFunc.h \
    Model/Param/channelFunc/hueFunc.h \
    Model/Param/channelFunc/redFunc.h \
    Model/Param/channelFunc/saturationFunc.h \
    Model/Param/channelFunc/valueFunc.h \
    Model/Param/channelFunc/yFunc.h \
    Model/Param/spaceFunc/colorSpaceFunc.h \
    Model/Param/spaceFunc/bgrFunc.h \
    Model/Param/spaceFunc/hsvFunc.h \
    Model/Param/spaceFunc/ycrcbFunc.h \
    Model/condition.h \
    Model/Param/channelFunc.h \
    Model/Service/edgeService.h

FORMS    += \
    View/calibrateDialog.ui \
    View/mainWindow.ui \
    View/colorDialog.ui

# OpenCV settings
# for Windows
win32:DEPENDPATH  += "C:\opencv248\build\include"
win32:INCLUDEPATH += "C:\opencv248\build\include"
win32:LIBS += -L"C:\opencv248\build\x86\vc12\lib"

# for Mac
INCLUDEPATH += /usr/local/include
DEPENDPATH += /usr/local/include
#LIBS += -L/usr/local/lib \
#    -lopencv_core \
#    -lopencv_imgproc \
#    -lopencv_highgui \
#    -lopencv_objdetect \
#    -lopencv_calib3d

OTHER_FILES += \
    ExtractParam.xml \
    Images/hamachi.jpg \
    Images/otoro.jpg \
    Images/sarmon.jpg \
    Images/toro.jpg
