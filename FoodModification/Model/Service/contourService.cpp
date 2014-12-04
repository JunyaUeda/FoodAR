#include "contourService.h"

#define LINK_EIGHT 8
#define LINK_FOUR 4
#define LINK_CVAA CV_AA

ContourService::ContourService() {
}

// int ContourService::getMaxAreaContourIndex(vPs& contours) {
    
//     size_t max=0;
//     int indexForMaxArea=0;
//     for(int i=0; i<contours.size(); ++i) {
//         size_t count = contours[i].size();
//         if(count < 150 || count > 1000) continue;

//         if(count > max) {
//             indexForMaxArea = i;
//             max = count;
//         }
//     }

//     return indexForMaxArea;
// }

vPs ContourService::getTargetContours(Mat srcBinaryImg) {
    vPs contours;
    findContours(srcBinaryImg, contours, CV_RETR_LIST, CV_CHAIN_APPROX_NONE);
    return contours;
}

/**
*すべての輪郭を塗りつぶし、輪郭以外の部分を黒にする.
*@note 
*/
void ContourService::fillContours(Mat& filledImg, vPs& contours, int lineType, int minSize) {

    if(!contours.empty()) {
        return;
    }

    for(int i=0; i<contours.size(); ++i) {

        size_t count = contours[i].size();
        if(count < minSize) {
            drawContours(filledImg, contours, i, Scalar(0, 0, 0), CV_FILLED, lineType);
        } else {
            drawContours(filledImg, contours, i, Scalar(255, 255, 255), CV_FILLED, lineType);
        }
        
    }

}
void ContourService::fillContours(Mat& filledImg, int minSize) {
    vPs contours;
    Mat tmp = filledImg.clone();
    findContours(tmp, contours, CV_RETR_LIST, CV_CHAIN_APPROX_NONE);
    fillContours(filledImg, contours, LINK_EIGHT, minSize);
}

/**
*特定の輪郭を塗りつぶし、それ以外を黒にする.
*@note 
*/
void ContourService::fillSpecifiedContour(Mat filledImg, vPs& contours, int lineType, int minSize, int specifiedIndex) {

    if(!contours.empty()) {
        return;
    }

    for(int i=0; i<contours.size(); ++i) {

        size_t count = contours[i].size();
        if( i== specifiedIndex) {
            drawContours(filledImg, contours, i, Scalar(255, 255, 255), CV_FILLED, lineType);
        } else {
            drawContours(filledImg, contours, i, Scalar(0, 0, 0), CV_FILLED, lineType);
        }
        
    }

}

vPs ContourService::extractContoursWithPoints(Mat srcImg, vP& points, int minSize ) {

    vPs srcContours;
    findContours(srcImg, srcContours, CV_RETR_LIST, CV_CHAIN_APPROX_NONE);

    return extractContoursWithPoints(srcContours, points, minSize);

}

vPs ContourService::extractContoursWithPoints(vPs& srcContours, vP& points, int minSize ) {

    vPs dstContours;
    
    for(int i=0; i<srcContours.size(); ++i) {
        size_t count = srcContours[i].size();
        if(count < minSize) {
            continue;
        } else {
            for(int j=0; j<points.size(); j++) {
                if(pointPolygonTest(srcContours[i], points[j], false)) {
                    dstContours.push_back(srcContours[i]);
                   
                }
            }
            
        }
        
    }

    return dstContours;
}

void ContourService::contourAreasAndCenters(vPs& contours, vector<double>& areas, vP& mCenters) {

    if(contours.size() == areas.size() && contours.size() == mCenters.size()) {
        return;
    }

    //色による抽出領域の面積を求める
    for(int i=0; i<contours.size(); i++) {
        areas[i] = contourArea(contours[i]);
    }

    //色による抽出領域の重心を求める
    calcurateCenter(contours,mCenters);

}

void ContourService::calcurateCenter(vPs& contours, vP &mCenters) {

    if(contours.size() != mCenters.size()) {

    }

    vector<Moments> mu(contours.size());
    for(int i=0; i<contours.size(); i++) {
        mu[i] = moments(contours[i], false);
    }
    //std::vector<cv::Point> mCenters(contours2.size());
    for(int i=0; i<contours.size(); i++) {
        mCenters[i] = Point(mu[i].m10/mu[i].m00, mu[i].m01/mu[i].m00);
    }

}
