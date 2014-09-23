#include "colorExtractService.h"

#include "../Utils/opencvUtils.h"
#include <math.h>
#include "../Param/colorCriterion.h"
#include "../Param/colorExtractTolerance.h"
#include "../extractParamManager.h"
//SIGN：DIFFの符号を表す 正1, 0, 負-1
#define SIGN_B(IMG,INDEX,X,Y) ((IMG).data[( (IMG).size[1]*(IMG).size[2]*(IMG).channels()*(INDEX) + (IMG).size[2]*(IMG).channels()*(Y) + (IMG).channels()*(X)) + 0])
#define DIFF_B(IMG,INDEX,X,Y) ((IMG).data[( (IMG).size[1]*(IMG).size[2]*(IMG).channels()*(INDEX) + (IMG).size[2]*(IMG).channels()*(Y) + (IMG).channels()*(X)) + 1])
#define SIGN_G(IMG,INDEX,X,Y) ((IMG).data[( (IMG).size[1]*(IMG).size[2]*(IMG).channels()*(INDEX) + (IMG).size[2]*(IMG).channels()*(Y) + (IMG).channels()*(X)) + 2])
#define DIFF_G(IMG,INDEX,X,Y) ((IMG).data[( (IMG).size[1]*(IMG).size[2]*(IMG).channels()*(INDEX) + (IMG).size[2]*(IMG).channels()*(Y) + (IMG).channels()*(X)) + 3])
#define SIGN_R(IMG,INDEX,X,Y) ((IMG).data[( (IMG).size[1]*(IMG).size[2]*(IMG).channels()*(INDEX) + (IMG).size[2]*(IMG).channels()*(Y) + (IMG).channels()*(X)) + 4])
#define DIFF_R(IMG,INDEX,X,Y) ((IMG).data[( (IMG).size[1]*(IMG).size[2]*(IMG).channels()*(INDEX) + (IMG).size[2]*(IMG).channels()*(Y) + (IMG).channels()*(X)) + 5])

ColorExtractService::ColorExtractService() {

}

void ColorExtractService::extractByBGR(Mat bgrImg, Mat dstImg, ExtractParamManager* extractParamManager) {

    Mat diffMap = getBGRDifferenceMap(bgrImg,extractParamManager->criterion);
    for(int y=0; y<bgrImg.rows; y++) {
        for(int x=0; x<bgrImg.cols; x++) {
            classifyByBGR(x,y,bgrImg,dstImg,extractParamManager,diffMap);
        }
    }

}

void ColorExtractService::extractByHSV(Mat srcImg, Mat dstImg, ExtractParamManager* extractParamManager) {

    for(int y=0; y<srcImg.rows; y++) {
        for(int x=0; x<srcImg.cols; x++) {

            int nearCriterionIndex = getHSVCriterionIndex(x, y, srcImg, extractParamManager);

            ColorCriterion* criterion = extractParamManager->criterion + nearCriterionIndex;
            ColorExtractTolerance* tolerance = extractParamManager->colorExtractTolerance + nearCriterionIndex;

            int diffHue = H(srcImg,x,y) - criterion->getHue();
            int diffSaturation = S(srcImg,x,y) - criterion->getSaturation();
            int diffValue = V(srcImg,x,y) - criterion->getValue();

            int factorH = 0; int factorS = 0; int factorV = 0;

            if(diffHue > 0) {
                factorH = tolerance->getHueHighTolerance() - abs(diffHue);
            } else {
                factorH = tolerance->getHueLowTolerance() - abs(diffHue);
            }

            if(diffSaturation > 0) {
                factorS = tolerance->getSaturationHighTolerance() - abs(diffSaturation);
            } else {
                factorS = tolerance->getSaturationLowTolerance() - abs(diffSaturation);
            }

            if(diffValue > 0) {
                factorV = tolerance->getValueHighTolerance() - abs(diffValue);
            } else {
                factorV = tolerance->getValueLowTolerance() - abs(diffValue);
            }

            /*ここの条件が色度値による抽出の精度に大きく影響するので、色々試して改善する必要がある*/
            if( factorH>-10 && factorS >-40 && factorV>-60) {//(factorH + factorS + factorV) >0
                L(dstImg,x,y) = 255;
            } else {
                L(dstImg,x,y) = 0;
            }     
    
        }   
   }

}

int ColorExtractService::getHSVCriterionIndex(int x, int y, Mat srcImg, ExtractParamManager* extractParamManager) {

    int difference_V0 = V(srcImg,x,y) - (extractParamManager->criterion+0)->getValue();
    int difference_V1 = V(srcImg,x,y) - (extractParamManager->criterion+1)->getValue();

    if( ( abs(difference_V0) - abs(difference_V1) ) >= 0) {
        return 1; 
    } else {
        return 0;
    }

}

void ColorExtractService::classifyByHSV(int x, int y, Mat srcImg, Mat dstImg, ExtractParamManager* extractParamManager, Mat diffMap) {

    int indexOfCriterion = getIndexOfNearCriterionByValue(x,y,diffMap);
    //int indexOfCriterion = 0;
    ColorExtractTolerance* tolerance = extractParamManager->colorExtractTolerance + indexOfCriterion;

    int diffB = DIFF_B(diffMap,indexOfCriterion,x,y);
    int diffG = DIFF_G(diffMap,indexOfCriterion,x,y);
    int diffR = DIFF_R(diffMap,indexOfCriterion,x,y);

    int toleranceB, toleranceG, toleranceR;

    if(SIGN_B(diffMap,indexOfCriterion,x,y)) {
        toleranceB = tolerance->getHueHighTolerance();
    } else {
        toleranceB = tolerance->getHueLowTolerance();
    }

    if(SIGN_G(diffMap,indexOfCriterion,x,y)) {
        toleranceG = tolerance->getSaturationHighTolerance();
    } else {
        toleranceG = tolerance->getSaturationLowTolerance();
    }

    if(SIGN_R(diffMap,indexOfCriterion,x,y)) {
        toleranceR = tolerance->getValueHighTolerance();
    } else {
        toleranceR = tolerance->getValueLowTolerance();
    }

    int factorB = toleranceB - diffB;
    int factorG = toleranceG - diffG;
    int factorR = toleranceR - diffR;

    if(factorB>0 && factorG>0 && factorR>0) {
        OpenCVUtils::setPixelValue(dstImg,x,y,255);
    } else {
        OpenCVUtils::setPixelValue(dstImg,x,y,0);
    }

}

void ColorExtractService::classifyByBGR(int x, int y, Mat bgrImg, Mat dstImg, ExtractParamManager* extractParamManager, Mat diffMap) {

    int indexOfCriterion = getIndexOfNearCriterion(x,y,diffMap);
    ColorExtractTolerance* tolerance = extractParamManager->colorExtractTolerance + indexOfCriterion;

    int diffB = DIFF_B(diffMap,indexOfCriterion,x,y);
    int diffG = DIFF_G(diffMap,indexOfCriterion,x,y);
    int diffR = DIFF_R(diffMap,indexOfCriterion,x,y);

    int toleranceB, toleranceG, toleranceR;

    if(SIGN_B(diffMap,indexOfCriterion,x,y)) {
        toleranceB = tolerance->getBlueHighTolerance();
    } else {
        toleranceB = tolerance->getBlueLowTolerance();
    }

    if(SIGN_G(diffMap,indexOfCriterion,x,y)) {
        toleranceG = tolerance->getGreenHighTolerance();
    } else {
        toleranceG = tolerance->getGreenLowTolerance();
    }

    if(SIGN_R(diffMap,indexOfCriterion,x,y)) {
        toleranceR = tolerance->getRedHighTolerance();
    } else {
        toleranceR = tolerance->getRedLowTolerance();
    }

    int factorB = toleranceB - diffB;
    int factorG = toleranceG - diffG;
    int factorR = toleranceR - diffR;

    if(factorB>0 && factorG>-10 && factorR>-30) {
        OpenCVUtils::setPixelValue(dstImg,x,y,255);
    } else {
        OpenCVUtils::setPixelValue(dstImg,x,y,0);
    }

}

int ColorExtractService::getIndexOfNearCriterion(int x, int y, Mat diffMap) {

    int sum0 = DIFF_R(diffMap,0,x,y) + DIFF_G(diffMap,0,x,y) + DIFF_B(diffMap,0,x,y);
    int sum1 = DIFF_R(diffMap,1,x,y) + DIFF_G(diffMap,1,x,y) + DIFF_B(diffMap,1,x,y);
    if(sum0 < sum1) {
        return 0;
    } else {
        return 1;
    }

}

int ColorExtractService::getIndexOfNearCriterionByValue(int x, int y, Mat diffMap) {

    if(DIFF_R(diffMap,0,x,y) < DIFF_R(diffMap,1,x,y)) {
        return 0;
    } else {
        return 1;
    }

}

Mat ColorExtractService::getBGRDifferenceMap(Mat srcImg, ColorCriterion* criterion) {

    const int sizes[] = {2, srcImg.size().width, srcImg.size().height};
    Mat diffMap(3, sizes, CV_8UC(6));
    int HIGH = 1;
    int LOW = 0;
    for(int criterionIndex=0; criterionIndex<2; criterionIndex++) {
       for(int y=0; y<srcImg.rows; y++) {
            for(int x=0; x<srcImg.cols; x++) {
                for(int colorIndex=0; colorIndex<3; colorIndex++) {
                    int difference = 0;
                    switch(colorIndex) {
                        case 0:
                            difference = B(srcImg,x,y) - (criterion+criterionIndex)->getBlue();
                            if(difference >= 0) {
                                SIGN_B(diffMap,criterionIndex,x,y) = 1;
                                DIFF_B(diffMap,criterionIndex,x,y) = difference;
                            } else {
                                SIGN_B(diffMap,criterionIndex,x,y) = 0;
                                DIFF_B(diffMap,criterionIndex,x,y) = abs(difference);
                            }
                            break;
                        case 1:
                            difference = G(srcImg,x,y) - (criterion+criterionIndex)->getGreen();
                            if(difference >= 0) {
                                SIGN_G(diffMap,criterionIndex,x,y) = 1;
                                DIFF_G(diffMap,criterionIndex,x,y) = difference;
                            } else {
                                SIGN_G(diffMap,criterionIndex,x,y) = 0;
                                DIFF_G(diffMap,criterionIndex,x,y) = abs(difference);
                            }
                            break;
                        case 2:
                            difference = R(srcImg,x,y) - (criterion+criterionIndex)->getRed();
                            if(difference >= 0) {
                                SIGN_R(diffMap,criterionIndex,x,y) = 1;
                                DIFF_R(diffMap,criterionIndex,x,y) = difference;
                            } else {
                                SIGN_R(diffMap,criterionIndex,x,y) = 0;
                                DIFF_R(diffMap,criterionIndex,x,y) = abs(difference);
                            }
                            break;
                    } 
                }
            } 
        }
    }

    return diffMap;

 }

Mat ColorExtractService::getHSVDifferenceMap(Mat srcImg, ColorCriterion* criterion) {

    const int sizes[] = {2, srcImg.size().width, srcImg.size().height};
    Mat diffMap(3, sizes, CV_8UC(6));
    int HIGH = 1;
    int LOW = 0;
    for(int criterionIndex=0; criterionIndex<2; criterionIndex++) {
       for(int y=0; y<srcImg.rows; y++) {
            for(int x=0; x<srcImg.cols; x++) {
                for(int colorIndex=0; colorIndex<3; colorIndex++) {
                    int difference = 0;
                    switch(colorIndex) {
                        case 0:
                            difference = B(srcImg,x,y) - (criterion+criterionIndex)->getHue();
                            if(difference >= 0) {
                                SIGN_B(diffMap,criterionIndex,x,y) = 1;
                                DIFF_B(diffMap,criterionIndex,x,y) = difference;
                            } else {
                                SIGN_B(diffMap,criterionIndex,x,y) = 0;
                                DIFF_B(diffMap,criterionIndex,x,y) = abs(difference);
                            }
                            break;
                        case 1:
                            difference = G(srcImg,x,y) - (criterion+criterionIndex)->getSaturation();
                            if(difference >= 0) {
                                SIGN_G(diffMap,criterionIndex,x,y) = 1;
                                DIFF_G(diffMap,criterionIndex,x,y) = difference;
                            } else {
                                SIGN_G(diffMap,criterionIndex,x,y) = 0;
                                DIFF_G(diffMap,criterionIndex,x,y) = abs(difference);
                            }
                            break;
                        case 2:
                            difference = R(srcImg,x,y) - (criterion+criterionIndex)->getValue();
                            if(difference >= 0) {
                                SIGN_R(diffMap,criterionIndex,x,y) = 1;
                                DIFF_R(diffMap,criterionIndex,x,y) = difference;
                            } else {
                                SIGN_R(diffMap,criterionIndex,x,y) = 0;
                                DIFF_R(diffMap,criterionIndex,x,y) = abs(difference);
                            }
                            break;
                    } 
                }
            } 
        }
    }

    return diffMap;

 }

void ColorExtractService::extract(Mat bgrImg, Mat hsvImg,Mat yCrCbImg, ExtractParamManager* extractParamManager) {

    for(int y=0; y<hsvImg.rows; y++) {
        for(int x=0; x<hsvImg.cols; x++) {
                if(isNearNormalPointA(x, y, hsvImg, extractParamManager->criterion)) {
                    discriminate(x, y, bgrImg, hsvImg, yCrCbImg, extractParamManager->criterion, extractParamManager->colorExtractTolerance);
                } else {
                    discriminate(x, y, bgrImg, hsvImg, yCrCbImg, extractParamManager->criterion+1, extractParamManager->colorExtractTolerance+1);
                }
        }
    }

}

void ColorExtractService::discriminate(int x, int y, cv::Mat bgrImg, cv::Mat hsvImg, cv::Mat yCrCbImg, ColorCriterion* colorCriterion, ColorExtractTolerance* extractTolerance) {

    int hueDifference = abs(B(hsvImg,x,y) - colorCriterion->getHue());
    int saturationDifference = abs(G(hsvImg,x,y) - colorCriterion->getSaturation());
    int valueDifference = abs(R(hsvImg,x,y) - colorCriterion->getValue());
   // int crDifference = abs(G(yCrCbImg,x,y) - colorCriterion->getCr());

    int tmpA = extractTolerance->getHueHighTolerance() - hueDifference;
    int tmpB = extractTolerance->getSaturationHighTolerance() - saturationDifference;
    int tmpC = extractTolerance->getValueHighTolerance() - valueDifference;
    //int tmpD = extractTolerance->getCrTolerance() - crDifference;

    if(tmpA>0 && tmpB>0 && tmpC>0 ) {
        OpenCVUtils::setPixelValue(bgrImg, x, y, 255);
    } else {
        OpenCVUtils::setPixelValue(bgrImg, x, y, 0);
    }

}

bool ColorExtractService::isNearNormalPointA(int x, int y, cv::Mat hsvImg, ColorCriterion* colorCriterion) {

    int absoluteValueDifferenceA = abs(R(hsvImg,x,y) - colorCriterion->getValue());
    int absoluteValueDifferenceB = abs(R(hsvImg,x,y) - (colorCriterion+1)->getValue());

    if (absoluteValueDifferenceA <= absoluteValueDifferenceB) {
        return true;
    }

    return false;

}


