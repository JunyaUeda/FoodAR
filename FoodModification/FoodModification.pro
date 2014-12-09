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
    Param/colorCriterion.cpp \
    Param/colorExtractTolerance.cpp \
    View/calibrateDialog.cpp \
    Param/calibrateClickParam.cpp \
    app.cpp \
    Param/targetParam.cpp \
    Utils/opencvBase.cpp \
    Utils/opencvUtils.cpp \
    Controller/calibrationController.cpp \
    View/mainWindow.cpp \
    Controller/mainController.cpp \
    Service/textureService.cpp \
    Controller/textureController.cpp \
    Controller/convertController.cpp \
    View/colorDialog.cpp \
    Param/textureParam.cpp \
    Utils/xmlUtils.cpp \
    Param/illuminationParam.cpp \
    Controller/edgeController.cpp \
    Param/edgeParam.cpp \
    Controller/srcController.cpp \
    Param/cannyThreshold.cpp \
    Param/Features/feature.cpp \
    Param/References/reference.cpp \
    Controller/baseController.cpp \
    Controller/File/fileController.cpp \
    Controller/singleton.cpp \
    Model/features.cpp \
    Model/Param/color.cpp \
    Model/extractParam.cpp \
    Model/featureReference.cpp \
    Model/Param/channelThreshold.cpp \
    Model/Service/regionService.cpp \
    Model/SDK/opencv/opencvApi.cpp \
    Model/Param/channel.cpp \
    Model/Param/channelHistogram.cpp \
    Model/Param/matSet.cpp \
    Model/Param/colorThreshold.cpp \
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
    Model/Service/edgeService.cpp \
    Model/Service/contourService.cpp \
    Model/Executor/sourcer.cpp \
    Model/Manager/textureManager.cpp \
    Model/Executor/calibrator.cpp \
    Model/Executor/extractor.cpp \
    Model/Manager/cameraManager.cpp \
    Model/Manager/extractionManager.cpp \
    Model/Executor/outputer.cpp \
    Model/Manager/windowManager.cpp \
    Model/Param/Texture/movieTexture.cpp \
    Model/Param/Texture/stilltexture.cpp \
    Model/Param/Texture/texture.cpp \
    Model/Param/Texture/noTexture.cpp \
    Model/Param/window.cpp \
    Model/mainProcedure.cpp \
    Model/Executor/saver.cpp \
    Model/Manager/manager.cpp \
    Model/Param/xmlElement.cpp \
    Model/Manager/fileManager.cpp \
    Controller/fileController.cpp \
    Param/Features/features.cpp \
    Model/Util/qtUtil.cpp \
    Model/Param/edgeThreshold.cpp \
    Model/edgeFactory.cpp \
    Controller/extractionController.cpp \
    Model/channelViewer.cpp \
    Model/textureFactory.cpp \
    Model/Executor/converter.cpp \
    Controller/cameraController.cpp \
    Model/Service/histogramsService.cpp \
    Controller/windowController.cpp \
    Model/binarizationViewer.cpp

HEADERS  += \
    Param/colorCriterion.h \
    Param/colorExtractTolerance.h \
    View/calibrateDialog.h \
    Param/calibrateClickParam.h \
    app.h \
    Param/targetParam.h \
    Utils/opencvBase.h \
    Utils/opencvUtils.h \
    Controller/calibrationController.h \
    View/mainWindow.h \
    Controller/mainController.h \
    Service/textureService.h \
    Controller/textureController.h \
    Controller/convertController.h \
    View/colorDialog.h \
    Param/textureParam.h \
    Utils/xmlUtils.h \
    Param/illuminationParam.h \
    Controller/edgeController.h \
    Param/edgeParam.h \
    definition.h \
    Controller/srcController.h \
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
    Model/featureReference.h \
    Model/Param/channelThreshold.h \
    Model/Param/channelType.h \
    Model/Service/regionService.h \
    Model/SDK/opencv/opencvApi.h \
    Model/Param/colorSpaceType.h \
    Model/Param/channel.h \
    Model/Param/channelHistogram.h \
    Model/Param/matSet.h \
    Model/TypeDef.h \
    Model/Param/colorThreshold.h \
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
    Model/Service/edgeService.h \
    Model/Service/contourService.h \
    Model/Executor/sourcer.h \
    Model/Manager/textureManager.h \
    Model/Executor/calibrator.h \
    Model/Executor/extractor.h \
    Model/Manager/cameraManager.h \
    Model/Manager/extractionManager.h \
    Model/Executor/outputer.h \
    Model/Manager/windowManager.h \
    Model/Param/Texture/movieTexture.h \
    Model/Param/Texture/stillTexture.h \
    Model/Param/Texture/texture.h \
    Model/Param/Texture/noTexture.h \
    Model/Param/window.h \
    Model/mainProcedure.h \
    Model/Executor/saver.h \
    Model/Manager/manager.h \
    Model/Param/xmlElement.h \
    Model/Manager/fileManager.h \
    Controller/fileController.h \
    Param/Features/features.h \
    Model/Util/qtUtil.h \
    Model/Param/edgeThreshold.h \
    Model/edgeFactory.h \
    Controller/extractionController.h \
    Model/channelViewer.h \
    Model/textureFactory.h \
    Model/Executor/converter.h \
    Controller/cameraController.h \
    Model/Service/histogramService.h \
    Controller/windowController.h \
    Model/binarizationViewer.h

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
