#ifndef EDGE_H
#define EDGE_H

#include "../TypeDef.h"
#include "../SDK/opencv/opencvApi.h"

class Edge {

/*method*/
public:
    Edge();
    void setRawMats(vector<Mat>& mats) {
        _rawMats = mats;
    }
    Mat& roiMergedMat() {
        return _roiMergedMat;
    }
    void setRoiMergedMat(Mat& mat) {
        _roiMergedMat = mat;
    }
/*property*/
private:
    vector<Mat>  _rawMats;
	Mat _roiMergedMat;
    Mat _revRoiMergedMat;
	vPs _contours;

};

#endif // EDGE_H
