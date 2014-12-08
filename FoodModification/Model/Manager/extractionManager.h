#ifndef EXTRACTIONMANAGER_H
#define EXTRACTIONMANAGER_H

#include <vector>
#include "manager.h"
#include "../TypeDef.h"
#include "../Param/edgeThreshold.h"
#include "../Executor/converter.h"

class ExtractionManager : public Manager {

/*method*/
public:
    static ExtractionManager& getInstance();
    void save(QXmlStreamWriter& writer);
    void setDilateCount(int count) {
        _dilateCount = count;
    }
    int dilateCount() {
        return _dilateCount;
    }
    void setErodeCount(int count) {
        _erodeCount = count;
    }
    int erodeCount() {
        return _erodeCount;
    }
    void updateRatioOfPixelNum(double upperRatio, double underRatio) {
        _converter.updateRatioPixelNum(upperRatio, underRatio);
    }
private:
    ExtractionManager();
    ExtractionManager(const ExtractionManager&);

/*property*/
private:
    int _dilateCount = 2;
    int _erodeCount = 0;
    Converter& _converter = Converter::getInstance();
};

#endif // EXTRACTIONMANAGER_H
