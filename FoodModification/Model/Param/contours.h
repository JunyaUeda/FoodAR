#ifndef CONTOURS_H
#define CONTOURS_H

#include "../TypeDef.h"

class Contours {

/*method*/
public:
	Contours();
    Contours(Mat& mat) {
        _mat = mat;
        findContours(_mat, _contours, CV_RETR_LIST, CV_CHAIN_APPROX_NONE);
        _indexSortedByArea = calcIndexiesOfTop3Area(_contours);
    }

    vPs& all() {
        return _contours;
    }

    bool hasContour() {
        if(_indexSortedByArea[0] >= 0) {
            return true;
        }
        return false;
    }

    bool hasMultiContour() {
        if(_indexSortedByArea[1] >= 0) {
            return true;
        }
        return false;
    }

    vector<int>& indexSortedByArea() {
        return _indexSortedByArea;
    }

    vector<Point>& getLargestContour() {
        return _contours[_indexSortedByArea[0]];
    }

    Size matSize() {
        return _mat.size();
    }

    int numOfContour() {
        return _numOfContour;
    }

private:
    int calcIndexOfMaxArea(vPs& contours) {
        if(!contours.size()) {
            return -1;
        }
        size_t max=0;
        int indexForMaxArea=-1;
        for(int i=0; i<static_cast<int>(contours.size()); ++i) {
            size_t count = contours[i].size();
            //if(count < 300 || count > 1000) continue;

            if(count > max) {
                indexForMaxArea = i;
                max = count;
            }
        }

        return indexForMaxArea;
    }

    vector<int> calcIndexiesOfTop3Area(vPs& contours) {
       
        size_t max=0;
        size_t second =0;
        size_t third = 0;
        vector<int> indexForTop3(3, -1);
        
        const int FIRST = 0;
        const int SECOND = 1;
        const int THIRD = 2;

        if(contours.size() > 0) {
            for(int i=0; i<static_cast<int>(contours.size()); ++i) {
                size_t count = contours[i].size();
                //if(count < 300 || count > 1000) continue;

                if(count > max) {
                    indexForTop3[THIRD] = indexForTop3[SECOND];
                    indexForTop3[SECOND] = indexForTop3[FIRST];
                    indexForTop3[FIRST] = i;
                    third = second;
                    second = max;
                    max = count;
                } else if(count > second) {
                    indexForTop3[THIRD] = indexForTop3[SECOND];
                    indexForTop3[SECOND] = i;
                    third = second;
                    second = count;
                } else if( count > third) {
                    indexForTop3[THIRD] = i;
                    third = count;
                }
            }
        }
        
        if(indexForTop3[THIRD] >= 0) {
            _numOfContour = 3;
        } else if (indexForTop3[SECOND] >= 0) {
            _numOfContour = 2;
        } else if (indexForTop3[FIRST] >= 0) {
            _numOfContour = 1;
        } else {
            _numOfContour = 0;
        }
        return indexForTop3;
    }


/*property*/
private:
    Mat _mat;
    vPs _contours;
    vector<int> _indexSortedByArea;
    int _numOfContour;


};

#endif // CONTOURS_H
