#ifndef MAINPROCEDURE_H
#define MAINPROCEDURE_H

#include "./Executor/saver.h"
#include "./Executor/sourcer.h"
#include "./Executor/extractor.h"
#include "./Executor/converter.h"
#include "./Executor/outputer.h"
#include "./Manager/windowManager.h"
#include "./Manager/cameraManager.h"
#include "./Manager/textureManager.h"


class MainProcedure {

/*method*/
public:
    static MainProcedure& getInstance();
    void start();
    void stop();
private:
    MainProcedure();
    MainProcedure(const MainProcedure&);

/*property*/
private:
    Sourcer& _sourcer             = Sourcer::getInstance();
    Extractor& _extractor         = Extractor::getInstance();
    Saver& _saver                 = Saver::getInstance();
    WindowManager& _windowManager = WindowManager::getInstance();
    TextureFactory& _textureFactory = TextureFactory::getInstance();
    TextureManager& _textureManager = TextureManager::getInstance();
    CameraManager& _cameraManager = CameraManager::getInstance();
    Converter& _converter         = Converter::getInstance();
    Outputer& _outputer           = Outputer::getInstance();
    bool _isProcessed = true;
    Region _extractedRegion;

};

#endif // MAINPROCEDURE_H
