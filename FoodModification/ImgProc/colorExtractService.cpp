#include "colorExtractService.h"

#include "opencvUtils.h"
#include <math.h>
#include "..\\Param\\colorCriterion.h"
#include "..\\Param\\colorExtractTolerance.h"
#include "..\\extractParamManager.h"

ColorExtractService::ColorExtractService()
{
}

void ColorExtractService::extract(cv::Mat bgrImg, cv::Mat hsvImg,cv::Mat yCrCbImg, ExtractParamManager* extractParamManager) {
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
    int crDifference = abs(G(yCrCbImg,x,y) - colorCriterion->getCr());

    int tmpA = extractTolerance->getHueTolerance() - hueDifference;
    int tmpB = extractTolerance->getSaturationTolerance() - saturationDifference;
    int tmpC = extractTolerance->getValueTolerance() - valueDifference;
    int tmpD = extractTolerance->getCrTolerance() - crDifference;

    if(tmpA>0 && tmpB>0 && tmpC>0 && tmpD>0) {
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
