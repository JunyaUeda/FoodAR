#include "extractor.h"

#define LINK_EIGHT 8
#define LINK_FOUR 4
#define LINK_CVAA CV_AA

Extractor::Extractor() {
    
}

Extractor& Extractor::getInstance() {
    static Extractor instance;
    return instance;
}
void Extractor::setScoreMatZeroAndSize(Size size) {
    _scoreMat = Mat(size.width, size.height, CV_8UC1, 2);
}

void Extractor::extract(MatSet& srcSet, Region& result) {

    //いったん手続き型でアルゴリズムを作成する
    //TODO : メソッド分割すべし

    //エッジ画像を取得する
    vector<Mat> rawEdges;
    _edgeFactory.createEdges(srcSet, rawEdges);
    Mat dstEdgeImg(srcSet.size().height,srcSet.size().width, CV_8UC1, 255);
    revMergeEdges(rawEdges, _previousRegion.expectedRoi(), dstEdgeImg);
    erode(dstEdgeImg, dstEdgeImg, cv::Mat(), Point(-1,-1), 1);
    imshow("revEdge", dstEdgeImg);

     Mat mat = Mat::zeros(srcSet.size(), CV_8UC1);
    if(_indexOfMaxArea >=0){

        int yBegin = _previousRegion.expectedRoi().y;
        int yEnd = _previousRegion.expectedRoi().y+_previousRegion.expectedRoi().height;
        int xBegin = _previousRegion.expectedRoi().x;
        int xEnd = _previousRegion.expectedRoi().x+_previousRegion.expectedRoi().width;
    
        for(int y=yBegin; y<yEnd; y++) {
            for(int x=xBegin; x<xEnd; x++) {

                //全ピクセルに対する操作
                if(_featureReference.isWithinThreshold(srcSet, Point(x,y)) ){ 
                    ////score使う方法
                    // switch(L(_scoreMat,x,y)) {
                    //     case 0:
                    //         L(_scoreMat,x,y) = 1;
                    //         break;
                    //     case 1:
                    //         L(region.maskImg(),x,y) = 255;
                    //         L(_scoreMat,x,y) = 2;
                    //         break;
                    //     case 2:
                    //         L(region.maskImg(),x,y) = 255;
                    //         break;
                    // }
                    //if(L(dstEdgeImg,x,y)==255) {
                        L(mat,x,y) = 255; 
                    //}   
                        
                }
                
            }
        }
    
    } else {
        for(int y=0; y<srcSet.size().height; y++) {
            for(int x=0; x<srcSet.size().width; x++) {

                //全ピクセルに対する操作
                if(_featureReference.isWithinThreshold(srcSet, Point(x,y)) ){ 
                    ////score使う方法
                    // switch(L(_scoreMat,x,y)) {
                    //     case 0:
                    //         L(_scoreMat,x,y) = 1;
                    //         break;
                    //     case 1:
                    //         L(region.maskImg(),x,y) = 255;
                    //         L(_scoreMat,x,y) = 2;
                    //         break;
                    //     case 2:
                    //         L(region.maskImg(),x,y) = 255;
                    //         break;
                    // }   
                  // if(L(dstEdgeImg,x,y)==255) {
                        L(mat,x,y) = 255; 
                    //}      
                }
                
            }
        }
    }
    
    dilate(mat, mat, cv::Mat(), Point(-1,-1), _extractionManager.dilateCount());
	erode(mat, mat, cv::Mat(), Point(-1,-1), _extractionManager.erodeCount());
    imshow("colorExtract", mat);

    
    //最大面積
    vPs contours;
    findContours(mat, contours, CV_RETR_LIST, CV_CHAIN_APPROX_NONE);
    _indexOfMaxArea = calcIndexOfMaxArea(contours);
    Mat mat2 = Mat::zeros(srcSet.size(), CV_8UC1);
   
    drawContours(mat2, contours, _indexOfMaxArea, Scalar(255, 255, 255), CV_FILLED, LINK_EIGHT);
    
    
    //エッジ画像を取得する
    //     // _edgeService.extractEdge(rawEdges, areamaxRegion.rois()[0], dstEdgeImg);
    //     // imshow("edge", dstEdgeImg);


    //     //残ったエッジ画像と色による抽出画像を合成する
    //     bitwise_or(areamaxRegion.maskImg(), dstEdgeImg, dstEdgeImg);


    //     drawContours(dstEdgeImg, areamaxRegion.contours(), 0, Scalar(255, 255, 255), CV_FILLED, LINK_EIGHT);

    //     int minSize = 200;
    //     _contourService.fillContours(dstEdgeImg, minSize);
        

    imshow("merge", mat2);

    result.setMaskImg(mat2);
    if(_indexOfMaxArea>=0) {
        result.setContour(contours[_indexOfMaxArea]);
        result.calcRotatedRect();
        result.calcRoi();
        result.calcExpectedRoiConsideringMove(_previousRegion);
    }
    
    _previousRegion = result;

}

/**
* calibratorで呼び出される
*/
void Extractor::setPreviousRegion(Region& region) {

}

