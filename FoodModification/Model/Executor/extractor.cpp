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

    Region region(srcSet.size() );

    //コピーの速度をきにしないなら右のほうが読みやすい
    //_extractService.extractRegionByColor(srcSet, region);//色情報だけではなくなる可能性が高いのでいったんコメントアウト
    //いったん手続き型でアルゴリズムを作成する
    //TODO : メソッド分割すべし
    for(int y=0; y<srcSet.height(); y++) {
        for(int x=0; x<srcSet.width(); x++) {

            //全ピクセルに対する操作
            if(_featureReference.isWithinThreshold(srcSet, Point(x,y)) ){ 
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
                L(region.maskImg(),x,y) = 255;     
            }
            
        }
    }
    region.calcContours();
    

    dilate(region.maskImg(), region.maskImg(), cv::Mat(), Point(-1,-1), _extractionManager.dilateCount());
	erode(region.maskImg(), region.maskImg(), cv::Mat(), Point(-1,-1), _extractionManager.erodeCount());
    imshow("new extract", region.maskImg());

    
    //最大面積の領域を取得する
    Region areamaxRegion(region.size() );
     _extractService.acquireMaxAreaRegion(region, areamaxRegion);

     Mat dstEdgeImg = Mat::zeros(region.size(), CV_8UC1);
    if(areamaxRegion.rois().size()) {
        //エッジ画像を取得する
        vector<Mat> rawEdges;
        _edgeFactory.createEdges(srcSet, rawEdges);
        

        //エッジ画像を取得する
        _edgeService.extractEdge(rawEdges, areamaxRegion.rois()[0], dstEdgeImg);
        imshow("edge", dstEdgeImg);


        //残ったエッジ画像と色による抽出画像を合成する
        bitwise_or(areamaxRegion.maskImg(), dstEdgeImg, dstEdgeImg);
        drawContours(dstEdgeImg, areamaxRegion.contours(), 0, Scalar(255, 255, 255), CV_FILLED, LINK_EIGHT);

        int minSize = 200;
        _contourService.fillContours(dstEdgeImg, minSize);
        
    }
    imshow("merge", dstEdgeImg);

    result.setMaskImg(dstEdgeImg);
    result.calcContours();
    result.calcRois();
    result.calcRotatedRects();

    _previousRegion = result;
}

/**
* calibratorで呼び出される
*/
void Extractor::setPreviousRegion(Region& region) {
    _previousRegion = region;
}