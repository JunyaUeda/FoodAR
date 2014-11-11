#ifndef THRESHOLD_H
#define THRESHOLD_H

#include "./channelThreshold.h"
#include "../../Utils/xmlUtils.h"

class Threshold {

/*property*/
private:

/*method*/
public:
    Threshold();
    void loadThreshold(QDomElement element);

private:
	void loadAverage(QDomElement element);
};

#endif // THRESHOLD_H
