#ifndef EDGE_H
#define EDGE_H

#include "../TypeDef.h"
#include "../SDK/opencv/opencvApi.h"

class Edge {

/*method*/
public:
    Edge();
    Edge(const Mat &mat);
    Mat mat() const;
    void setMat(const Mat &mat);;
    vPs contours() const;
    void setContours(const vPs &contours);

/*property*/
private:
	Mat _mat;
	vPs _contours;

};

#endif // EDGE_H
