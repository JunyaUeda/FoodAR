#ifndef REFERENCECOLOR_H
#define REFERENCECOLOR_H

class ReferenceColor : public Feature {

/*property*/
private:
	int bgr[3];
    int hsv[3];
   	int ycrcb[3];

/*method*/
public:
    ReferenceColor();
};

#endif // REFERENCECOLOR_H
