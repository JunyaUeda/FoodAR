#ifndef FEATURES_H
#define FEATURES_H

#include "./Param/Color.h"

using namespace std;

class Features {

/*property*/
private:
	Color _rgb;
	Color _hsv;
	Color _ycrcb;

/*method*/
public:
    Features();

};

#endif // FEATURES_H
