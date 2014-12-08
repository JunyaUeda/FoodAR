#ifndef HISTOGRAMSERVICE_H
#define HISTOGRAMSERVICE_H

#include "../featureReference.h"

class HistogramService {

/*method*/
public:
	static HistogramService& getInstance();

    void updateMedianAndTolerance(int gFrequency[], int yFrequency[], int crFrequency[], int cbFrequency[], int pixelSum) {

        _harfPixelNum = (int)((double)pixelSum/2.0);
        _underPixelNum = (int)((double)pixelSum*0.05);
        _upperPixelNum = (int)((double)pixelSum*0.95);

        
        int greenMedian = 0;
        int greenUpperTolerance = 0;
        int greenUnderTolerance = 0;
        calcMedianAndTolerance(greenMedian, greenUnderTolerance, greenUpperTolerance, gFrequency);
               
        int yMedian = 0;
        int yUpperTolerance = 0;
        int yUnderTolerance = 0;
        calcMedianAndTolerance(yMedian, yUnderTolerance, yUpperTolerance, yFrequency);
        
        int crMedian = 0;
        int crUpperTolerance = 0;
        int crUnderTolerance = 0;
        calcMedianAndTolerance(crMedian, crUnderTolerance, crUpperTolerance, crFrequency);
        
        int cbMedian = 0;
        int cbUpperTolerance = 0;
        int cbUnderTolerance = 0;
        calcMedianAndTolerance(cbMedian, cbUnderTolerance, cbUpperTolerance, cbFrequency);

        vint averages(9,0);
        vint medians(9,0);
        vint upperTolerances(9,0);
        vint underTolerances(9,0);

        medians[1] = greenMedian;
        medians[6] = yMedian;
        medians[7] = crMedian;
        medians[8] = cbMedian;
        upperTolerances[1] = greenUpperTolerance;
        upperTolerances[6] = yUpperTolerance;
        upperTolerances[7] = crUpperTolerance;
        upperTolerances[8] = cbUpperTolerance;
        underTolerances[1] = greenUnderTolerance;
        underTolerances[6] = yUnderTolerance;
        underTolerances[7] = crUnderTolerance;
        underTolerances[8] = cbUnderTolerance;

        _featureReference.updateMedianAndTolerance(medians, upperTolerances, underTolerances);
    }

private:
    HistogramService();
    HistogramService(const HistogramService&);
    void calcMedianAndTolerance(int& median, int& under, int& upper, int frequency[]) {
        int pixelCount;
        for(int bin =0; bin<256; bin++ ) {
            pixelCount = pixelCount + frequency[bin];
            if(pixelCount <= _underPixelNum) {
                under = bin;
                continue;
            }
            if(pixelCount <= _harfPixelNum) {
                median = bin;
                continue;
            }
            if(pixelCount >= _upperPixelNum) {
                upper = bin;
                break;
            }

        }
    }
/*property*/
private:
    int _harfPixelNum;
    int _underPixelNum;
    int _upperPixelNum;

    FeatureReference& _featureReference = FeatureReference::getInstance();
};

#endif // HISTOGRAMSERVICE_H
