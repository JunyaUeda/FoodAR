#pragma once
#include "bgr3dPlotController.h"

BGR3DPlotController::BGR3DPlotController()
{
}

BGR3DPlotController& BGR3DPlotController::getInstance() {
    static BGR3DPlotController instance;
    return instance;
}


