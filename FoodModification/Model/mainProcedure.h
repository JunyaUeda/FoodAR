#ifndef MAINPROCEDURE_H
#define MAINPROCEDURE_H

#include "./Executor/saver.h"
#include "./Executor/sourcer.h"
#include "./Executor/extractor.h"
#include "./Manager/windowManager.h"

class MainProcedure {

/*method*/
public:
    static MainProcedure& getInstance();
    void start();
private:
    MainProcedure();
    MainProcedure(const MainProcedure&);

/*property*/
private:
    Sourcer& _sourcer             = Sourcer::getInstance();
    Extractor& _extractor         = Extractor::getInstance();
    Saver& _saver                 = Saver::getInstance();
    WindowManager& _windowManager = WindowManager::getInstance();

};

#endif // MAINPROCEDURE_H
