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
    Model/extractParam.cpp \
    Model/xmlReader.cpp \
    Model/featureReference.cpp \
    Model/Param/threshold.cpp \
    Model/Param/channelThreshold.cpp \
    Model/calibrator.cpp \
    Model/Service/regionService.cpp \
    Model/SDK/opencv/opencvApi.cpp \
    Model/Param/channelType/channelType.cpp \
    Model/Param/channelType/blueType.cpp \
    Model/Param/channelType/greenType.cpp \
    Model/Param/channelType/hueType.cpp \
    Model/Param/channelType/saturationType.cpp \
    Model/Param/channelType/valueType.cpp \
    Model/Param/channelType/yType.cpp \
    Model/Param/channelType/crType.cpp \
    Model/Param/channelType/cbType.cpp \
    Model/Param/spaceType/colorSpaceType.cpp \
    Model/Param/spaceType/bgrType.cpp \
    Model/Param/spaceType/hsvType.cpp \
    Model/Param/spaceType/ycrcbType.cpp \
    Model/Param/channel.cpp \
    Model/Param/channelType/redType.cpp \
    Model/Param/source.cpp \
    Model/Param/channelHistogram.cpp \
    Model/Param/matSet.cpp \
    Model/Param/colorThreshold.cpp \
    Model/extractor.cpp \
    Model/Param/region.cpp \
    Model/Param/edge.cpp \
    Model/Service/colorService.cpp \
    Model/Service/extractService.cpp

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
    Model/Param/channelType.h \
    Model/calibrator.h \
    Model/Service/regionService.h \
    Model/SDK/opencv/opencvApi.h \
    Model/Param/colorSpaceType.h \
    Model/Param/channelType/channelType.h \
    Model/Param/channelType/blueType.h \
    Model/Param/channelType/greenType.h \
    Model/Param/channelType/hueType.h \
    Model/Param/channelType/saturationType.h \
    Model/Param/channelType/valueType.h \
    Model/Param/channelType/yType.h \
    Model/Param/channelType/crType.h \
    Model/Param/channelType/cbType.h \
    Model/Param/spaceType/colorSpaceType.h \
    Model/Param/spaceType/bgrType.h \
    Model/Param/spaceType/hsvType.h \
    Model/Param/spaceType/ycrcbType.h \
    Model/Param/channel.h \
    Model/Param/channelType/redType.h \
    Model/Param/source.h \
    Model/Param/channelHistogram.h \
    Model/Param/matSet.h \
    Model/TypeDef.h \
    Model/Param/colorThreshold.h \
    Model/extractor.h \
    Model/Param/region.h \
    Model/Param/edge.h \
    Model/Service/colorService.h \
    Model/Service/extractService.h

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
