#ifndef EXTRACTOR_H
#define EXTRACTOR_H

#include "./Param/matSet.h"

class Extractor {

/*property*/
private:

/*method*/
public:
	static Extractor& getInstance();
    void extract(MatSet* srcSet);

private:
    Extractor();
    Extractor(const Extractor&);

};

#endif // EXTRACTOR_H
