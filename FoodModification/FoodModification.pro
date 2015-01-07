#-------------------------------------------------
#
# Project created by QtCreator 2014-07-23T22:04:07
#
#-------------------------------------------------

QT       += core gui
QT += xml
QT += opengl
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += MAC_CONFIG
MAC_CONFIG {
    QMAKE_CXXFLAGS = -std=c++11 -stdlib=libc++ -mmacosx-version-min=10.10
    QMAKE_LFLAGS = -std=c++11 -stdlib=libc++ -mmacosx-version-min=10.10
}

QMAKE_MACOSX_DEPLOYMENT_TARGET = 10.10
TARGET = FoodModification
TEMPLATE = app


SOURCES += main.cpp\
    View/calibrateDialog.cpp \
    app.cpp \
    Utils/opencvBase.cpp \
    Utils/opencvUtils.cpp \
    Controller/calibrationController.cpp \
    View/mainWindow.cpp \
    Controller/mainController.cpp \
    Controller/textureController.cpp \
    Controller/convertController.cpp \
    View/colorDialog.cpp \
    Utils/xmlUtils.cpp \
    Controller/edgeController.cpp \
    Controller/baseController.cpp \
    Controller/singleton.cpp \
    Model/features.cpp \
    Model/Param/color.cpp \
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
    Model/Manager/fileManager.cpp \
    Controller/fileController.cpp \
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
    Model/binarizationViewer.cpp \
    Model/cannyViewer.cpp \
    Model/Param/channelSet.cpp \
    Controller/Param/calibrateClickParam.cpp \
    Model/Extraction/State/contourState.cpp \
    Model/Extraction/State/contourExisted.cpp \
    Model/Extraction/State/contourNonExisted.cpp \
    Model/Manager/regionManager.cpp \
    Model/Manager/thresholdManager.cpp \
    Model/Extraction/State/ContourCount/contourCountState.cpp \
    Model/Extraction/State/ContourCount/oneContour.cpp \
    Model/Extraction/State/ContourCount/multiContour.cpp \
    Model/Manager/edgeManager.cpp \
    Model/Param/contours.cpp \
    Model/Util/cvUtil.cpp \
    Controller/bgr3dPlotController.cpp \
    View/bgr3dPlotDialog.cpp \
    View/bgr3dPlotViewer.cpp \
    Model/Param/bgrColor.cpp \
    Model/Manager/inputManager.cpp \
    View/histogram3dViewer.cpp \
    View/bgr3dPlotAreaWidget.cpp \
    View/histogram3dAreaWidget.cpp

HEADERS  += \
    View/calibrateDialog.h \
    app.h \
    Utils/opencvBase.h \
    Utils/opencvUtils.h \
    Controller/calibrationController.h \
    View/mainWindow.h \
    Controller/mainController.h \
    Controller/textureController.h \
    Controller/convertController.h \
    View/colorDialog.h \
    Utils/xmlUtils.h \
    Controller/edgeController.h \
    definition.h \
    Controller/baseController.h \
    Controller/singleton.h \
    Model/features.h \
    Model/Param/color.h \
    Model/Param/channel.h \
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
    Model/Manager/fileManager.h \
    Controller/fileController.h \
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
    Model/binarizationViewer.h \
    Model/cannyViewer.h \
    Model/Param/channelSet.h \
    Controller/Param/calibrateClickParam.h \
    Model/Extraction/State/contourState.h \
    Model/Extraction/State/contourExisted.h \
    Model/Extraction/State/contourNonExisted.h \
    Model/Manager/regionManager.h \
    Model/Manager/thresholdManager.h \
    Model/Extraction/State/ContourCount/contourCountState.h \
    Model/Extraction/State/ContourCount/oneContour.h \
    Model/Extraction/State/ContourCount/multiContour.h \
    Model/Manager/edgeManager.h \
    Model/Param/contours.h \
    Model/Util/cvUtil.h \
    Controller/bgr3dPlotController.h \
    View/bgr3dPlotDialog.h \
    View/bgr3dPlotViewer.h \
    Model/Param/bgrColor.h \
    Model/Manager/inputManager.h \
    View/histogram3dViewer.h \
    View/bgr3dPlotAreaWidget.h \
    View/histogram3dAreaWidget.h

FORMS    += \
    View/calibrateDialog.ui \
    View/mainWindow.ui \
    View/colorDialog.ui \
    View/bgr3dPlotDialog.ui

# OpenCV settings
# for Windows
win32:DEPENDPATH  += "C:\opencv248\build\include"
win32:INCLUDEPATH += "C:\opencv248\build\include"
win32:LIBS += -L"C:\opencv248\build\x86\vc12\lib"

# for Mac

unix {
INCLUDEPATH += /usr/local/include
DEPENDPATH += /usr/local/include
LIBS += -L/usr/local/lib \
-lopencv_highgui \
-lopencv_imgproc \
-lopencv_core \
-lopencv_calib3d \
-lopencv_objdetect \
-lopencv_features2d \
-lopencv_contrib \
-lopencv_flann \
-lopencv_gpu \
-lopencv_legacy \
-lopencv_ml \
-lopencv_video
}

OTHER_FILES += \
    ExtractParam.xml \
    Images/hamachi.jpg \
    Images/otoro.jpg \
    Images/sarmon.jpg \
    Images/toro.jpg


# --------------------------------------------------------------------------------------

# The remaining of this configuration tries to automatically detect the library paths.
# In your applications, you can probably simply use (see doc/compilation.html for details) :

#INCLUDEPATH *= C:/Users/debunne/Documents/libQGLViewer-2.6.0
#LIBS *= -LC:/Users/debunne/Documents/libQGLViewer-2.6.0/QGLViewer -lQGLViewer2

# Change these paths according to your configuration.

# --------------------------------------------------------------------------------------

### Unix configuration ###
unix {
  CONFIG -= debug debug_and_release
  CONFIG *= release

  isEmpty( PREFIX ) {
	# Try same INCLUDE_DIR and LIB_DIR parameters than for the make install.
	PREFIX=/usr
  }

  # LIB_NAME
  LIB_NAME = libQGLViewer*.so*
  macx|darwin-g++ {
	LIB_NAME = libQGLViewer.$${QMAKE_EXTENSION_SHLIB}
  }
  hpux {
	LIB_NAME = libQGLViewer*.sl*
  }

  !isEmpty( QGLVIEWER_STATIC ) {
	LIB_NAME = libQGLViewer*.a
  }

  # LIB_DIR
  isEmpty( LIB_DIR ) {
	LIB_DIR = $${PREFIX}/lib
  }

  !exists( $${LIB_DIR}/$${LIB_NAME} ) {
	exists( ../../QGLViewer/$${LIB_NAME} ) {
	  #message( The library was found in ../../QGLViewer which will be set as the LIB_DIR )
	  LIB_DIR = ../../QGLViewer
	}
  }

  !exists( $${LIB_DIR}/$${LIB_NAME} ) {
	exists( ../../QGLViewer-build-desktop/$${LIB_NAME} ) {
	  #message( The library was found in ../../QGLViewer-build-desktop which will be set as the LIB_DIR )
	  LIB_DIR = ../../QGLViewer-build-desktop
	}
  }

  macx|darwin-g++ {
	!exists( $${LIB_DIR}/$${LIB_NAME} ) {
	  # DYLIB was not found, try to find Framework instead
	  LIB_NAME = QGLViewer.framework/QGLViewer
	  LIB_DIR = ~/Library/Frameworks
	  # qmake does not handle tilde
	  LIB_DIR = $$system(cd $${LIB_DIR};pwd)

	  !exists( $${LIB_DIR}/$${LIB_NAME} ) {
		exists( ../../QGLViewer/$${LIB_NAME} ) {
		  #message( The framework was found in ../../QGLViewer which will be set as the LIB_DIR )
		  LIB_DIR = ../../QGLViewer
		}
	  }

	  !exists( $${LIB_DIR}/$${LIB_NAME} ) {
		exists( ../../QGLViewer-build-desktop/$${LIB_NAME} ) {
		  #message( The framework was found in ../../QGLViewer-build-desktop which will be set as the LIB_DIR )
		  LIB_DIR = ../../QGLViewer-build-desktop
		}
	  }
	}
  }

  !exists( $${LIB_DIR}/$${LIB_NAME} ) {
	message( Unable to find $${LIB_NAME} in $${LIB_DIR}. Make sure you have built it. )
	message( If you have you should run qmake LIB_DIR=/path/to/QGLViewer/$${LIB_NAME} )
  }

  # The actual directory where the library/framework was found
  LIB_DIR_ABSOLUTE_PATH = $$system(cd $${LIB_DIR};pwd)

  # INCLUDE_DIR
  isEmpty( INCLUDE_DIR ) {
	INCLUDE_DIR = $${PREFIX}/include
  }

  macx|darwin-g++ {
	  !exists( $${INCLUDE_DIR}/QGLViewer/qglviewer.h ) {
		  INCLUDE_DIR=$${LIB_DIR}/QGLViewer.framework
		  exists( $${LIB_DIR}/QGLViewer.framework/Headers/QGLViewer/qglviewer.h ) {
			 INCLUDE_DIR = $${LIB_DIR}/QGLViewer.framework/Headers
		  }
	  }
  }

  !exists( $${INCLUDE_DIR}/QGLViewer/qglviewer.h ) {
	exists( ../../QGLViewer/qglviewer.h ) {
	  # message( libQGLViewer header files were not installed in standard $${INCLUDE_DIR} directory )
	  # message( Headers were found in ../.. which will be set as the INCLUDE_DIR )
	  INCLUDE_DIR = ../..
	}
  }

  !exists( $${INCLUDE_DIR}/QGLViewer/qglviewer.h ) {
	message( Unable to find QGLViewer/qglviewer.h in $${INCLUDE_DIR} )
	message( Use qmake INCLUDE_DIR=/path/to/QGLViewerDir )
  }


  macx|darwin-g++ {
	# On Mac, the lib path can be specified in the executable using install_name_tool
	contains( LIB_NAME, ".*QGLViewer.framework.*" ) {
	  # If framework was not found in a standard directory
	  !contains( LIB_DIR, ".*/Library/Frameworks/*$" ) {
		QMAKE_LFLAGS += -F$${LIB_DIR}
		!plugin:QMAKE_POST_LINK=install_name_tool -change QGLViewer.framework/Versions/2/QGLViewer $${LIB_DIR_ABSOLUTE_PATH}/QGLViewer.framework/Versions/2/QGLViewer $${TARGET}.app/Contents/MacOS/$${TARGET}
	  }
	  LIBS += -F$${LIB_DIR} -framework QGLViewer
	} else {
		!plugin:QMAKE_POST_LINK=install_name_tool -change libQGLViewer.2.dylib $${LIB_DIR_ABSOLUTE_PATH}/libQGLViewer.2.dylib $${TARGET}.app/Contents/MacOS/$${TARGET}
		LIBS *= -L$${LIB_DIR} -lQGLViewer
	}
  } else {
	isEmpty(QMAKE_LFLAGS_RPATH) {
	  !plugin:QMAKE_LFLAGS += -Wl,-rpath,$${LIB_DIR_ABSOLUTE_PATH}
	} else {
	  !plugin:QMAKE_RPATHDIR *= $${LIB_DIR_ABSOLUTE_PATH}
	}
	LIBS *= -L$${LIB_DIR} -lQGLViewer
  }

  # Paths were correctly detected
  INCLUDEPATH += $${INCLUDE_DIR}
  DEPENDPATH  += $${INCLUDE_DIR}

  !isEmpty( QGLVIEWER_STATIC ) {
	LIBS *= $${LIB_DIR}/$${LIB_NAME}
  }

  # Remove debugging options in release mode makes files much smaller
  release:QMAKE_CFLAGS_RELEASE -= -g
  release:QMAKE_CXXFLAGS_RELEASE -= -g

  # Intermediate files are created in an hidden folder
  MOC_DIR = .moc
  OBJECTS_DIR = .obj
}


win32 {
  CONFIG += debug_and_release

  # Seems to be needed for Visual Studio with Intel compiler
  DEFINES += WIN32

  !isEmpty( QGLVIEWER_STATIC ) {
	DEFINES *= QGLVIEWER_STATIC
  }

  # INCLUDE_DIR
  !exists( $${INCLUDE_DIR}/QGLViewer/qglviewer.h ) {
	exists( ../QGLViewer/qglviewer.h ) {
	  # message( libQGLViewer header files were not installed in standard $${INCLUDE_DIR} directory )
	  # message( Headers were found in ../.. which will be set as the INCLUDE_DIR )
	  INCLUDE_DIR = ..
	}
  }

  !exists( $${INCLUDE_DIR}/QGLViewer/qglviewer.h ) {
	message( Unable to find QGLViewer/qglviewer.h in $${INCLUDE_DIR} )
	error( Use qmake INCLUDE_DIR=/path/to/QGLViewerDir )
  }

  # Paths were correctly detected
  INCLUDEPATH += $${INCLUDE_DIR}
  DEPENDPATH  += $${INCLUDE_DIR}

  # LIB_NAME
  LIB_NAME = QGLViewer
  build_pass:CONFIG(debug, debug|release) {
	LIB_NAME = $$join(LIB_NAME,,,d)
  }
  LIB_NAME = $$join(LIB_NAME,,,2) #TODO 2

  win32-g++: LIB_FILE_NAME = lib$${LIB_NAME}.a
  !win32-g++: LIB_FILE_NAME = $${LIB_NAME}.lib

  isEmpty( LIB_DIR ) {
	LIB_DIR = C:\\Windows\\System32
  }

  !exists( $${LIB_DIR}/$${LIB_FILE_NAME} ) {
	exists( ../QGLViewer/$${LIB_FILE_NAME} ) {
	  LIB_DIR = ../QGLViewer
	}
  }

  !exists( $${LIB_DIR}/$${LIB_FILE_NAME} ) {
	 exists( ../QGLViewer/Release/$${LIB_FILE_NAME} ) {
	   LIB_DIR = ../QGLViewer/Release
	 }
  }

  !exists( $${LIB_DIR}/$${LIB_FILE_NAME} ) {
	 exists( ../QGLViewer/release/$${LIB_FILE_NAME} ) {
	   LIB_DIR = ../QGLViewer/release
	 }
  }

  !exists( $${LIB_DIR}/$${LIB_FILE_NAME} ) {
	exists( ../QGLViewer/Debug/$${LIB_FILE_NAME} ) {
	  LIB_DIR = ../QGLViewer/Debug
	}
  }

  !exists( $${LIB_DIR}/$${LIB_FILE_NAME} ) {
	exists( ../QGLViewer/debug/$${LIB_FILE_NAME} ) {
	  LIB_DIR = ../QGLViewer/debug
	}
  }

  !exists( $${LIB_DIR}/$${LIB_FILE_NAME} ) {
	exists( ../QGLViewer-build-desktop/$${LIB_FILE_NAME} ) {
	  LIB_DIR = ../QGLViewer-build-desktop
	}
  }

  !exists( $${LIB_DIR}/$${LIB_FILE_NAME} ) {
	 exists( ../QGLViewer-build-desktop/Release/$${LIB_FILE_NAME} ) {
	   LIB_DIR = ../QGLViewer-build-desktop/Release
	 }
  }

  !exists( $${LIB_DIR}/$${LIB_FILE_NAME} ) {
	 exists( ../QGLViewer-build-desktop/release/$${LIB_FILE_NAME} ) {
	   LIB_DIR = ../QGLViewer-build-desktop/release
	 }
  }

  !exists( $${LIB_DIR}/$${LIB_FILE_NAME} ) {
	exists( ../QGLViewer-build-desktop/Debug/$${LIB_FILE_NAME} ) {
	  LIB_DIR = ../QGLViewer-build-desktop/Debug
	}
  }

  !exists( $${LIB_DIR}/$${LIB_FILE_NAME} ) {
	exists( ../QGLViewer-build-desktop/debug/$${LIB_FILE_NAME} ) {
	  LIB_DIR = ../QGLViewer-build-desktop/debug
	}
  }

  !exists( $${LIB_DIR}/$${LIB_FILE_NAME} ) {
	message( Unable to find $${LIB_FILE_NAME} in $${LIB_DIR} )
	error( Use qmake LIB_DIR=/path/to/QGLViewer/$${LIB_FILE_NAME} )
  }

  win32-g++ {
	# The actual directory where the library/framework was found
	# LIB_DIR_ABSOLUTE_PATH = $$system(cd $${LIB_DIR} && cd)

	isEmpty( QGLVIEWER_STATIC ) {
	  LIBS *= -L$${LIB_DIR} -l$${LIB_NAME}
	} else {
	  LIBS *= $${LIB_DIR}/$${LIB_FILE_NAME}
	}
  }

  !win32-g++ {
	# Use the Qt DLL version. Only needed with Qt3

	LIBS *= -L$${LIB_DIR} -l$${LIB_NAME}
  }
}


macx|darwin-g++ {
  ICON = $${INCLUDEPATH}/QGLViewer/qglviewer.icns
}

win32 {
   !designer {
      exists( ../qglviewer.rc ) {
	     RC_FILE = ../qglviewer.rc
	  }
      exists( ../examples/qglviewer.rc ) {
	     RC_FILE = ../examples/qglviewer.rc
	  }
   }
}
