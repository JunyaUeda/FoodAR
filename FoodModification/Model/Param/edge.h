#ifndef EDGE_H
#define EDGE_H

#include "../TypeDef.h"

class Edge {

/*property*/
private:
	Mat _edgeImg;
	vPs _contours;
/*method*/
public:
    Edge();
    Mat edgeImg() const;
    void setEdgeImg(const Mat &edgeImg);
    vPs contours() const;
    void setContours(const vPs &contours);
};

#endif // EDGE_H
