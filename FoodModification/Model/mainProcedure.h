#ifndef MAINPROCEDURE_H
#define MAINPROCEDURE_H

#include "./Executor/sourcer.h"
#include "./Executor/extractor.h"
#include "./Manager/windowManager.h"

class MainProcedure {

/*property*/
private:
    Sourcer& _sourcer             = Sourcer::getInstance();
    Extractor& _extractor         = Extractor::getInstance();
    WindowManager& _windowManager = WindowManager::getInstance();

/*method*/
public:
	static MainProcedure& getInstance();
    void start();
private:
    MainProcedure();
    MainProcedure(const MainProcedure&);

};

#endif // MAINPROCEDURE_H
