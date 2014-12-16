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
    ChannelSet channelSet(srcSet);
    
    //エッジ画像を取得する
    vector<Mat> rawEdges;
    _edgeFactory.createEdges(srcSet, rawEdges, channelSet);
  
    Mat dstEdgeImg(srcSet.size().height,srcSet.size().width, CV_8UC1, 255);
    revMergeEdges(rawEdges, _previousRegion.expectedRoi(), dstEdgeImg);
    

    Mat mat = Mat::zeros(srcSet.size(), CV_8UC1);

    if(_indexOfMaxArea >=0){
        _contourExisted.createMaskByColor(mat, channelSet);
        
    } else {
        _contourNonExisted.createMaskByColor(mat, channelSet);
    }
    
    dilate(mat, mat, cv::Mat(), Point(-1,-1), _extractionManager.dilateCount());
	erode(mat, mat, cv::Mat(), Point(-1,-1), _extractionManager.erodeCount());
   // imshow("colorExtract", mat);

    
    //最大面積
    vPs contours;
    findContours(mat, contours, CV_RETR_LIST, CV_CHAIN_APPROX_NONE);
    vector<int> indexiesOfTop3Area = calcIndexiesOfTop3Area(contours);
    // _indexOfMaxArea = calcIndexOfMaxArea(contours);
    _indexOfMaxArea = indexiesOfTop3Area[0];
    Mat mat2 = Mat::zeros(srcSet.size(), CV_8UC1);
   
    
    if(indexiesOfTop3Area[1] >= 0) {
        _multiContour.drawAndCalcRegion(mat2, indexiesOfTop3Area, contours);
        
    } else {
        _oneContour.drawAndCalcRegion(mat2, indexiesOfTop3Area, contours);
        
    }
    
    result = _regionManager.currentRegion();
        
}


void Extractor::extractCoffee(MatSet& srcSet, Region& result) {

     //いったん手続き型でアルゴリズムを作成する
    //TODO : メソッド分割すべし
    ChannelSet channelSet(srcSet);
    
    //エッジ画像を取得する
    vector<Mat> rawEdges;
    _edgeFactory.createEdges(srcSet, rawEdges, channelSet);
  
    Mat dstEdgeImg(srcSet.size().height,srcSet.size().width, CV_8UC1, 255);
    revMergeEdges(rawEdges, _previousRegion.expectedRoi(), dstEdgeImg);
    

    Mat mat = Mat::zeros(srcSet.size(), CV_8UC1);

    if(_indexOfMaxArea >=0){
        _contourExisted.createMaskByColor(mat, channelSet);
        
    } else {
        _contourNonExisted.createMaskByColor(mat, channelSet);
    }

    
    
    Mat dstEdgeImg2 = dstEdgeImg.clone();
    

    
    //最大面積
    vPs contours;
    findContours(mat, contours, CV_RETR_LIST, CV_CHAIN_APPROX_NONE);
    vector<int> indexiesOfTop3Area = calcIndexiesOfTop3Area(contours);
    // _indexOfMaxArea = calcIndexOfMaxArea(contours);
    _indexOfMaxArea = indexiesOfTop3Area[0];
    Mat mat2 = Mat::zeros(srcSet.size(), CV_8UC1);
   
    
    drawContours(mat2, contours, _indexOfMaxArea, Scalar(255, 255, 255), CV_FILLED, LINK_EIGHT);
        
    imshow("merge", mat2);

    
    //エッジ画像を取得する
    _edgeService.drawEdge(dstEdgeImg2, dstEdgeImg2, 255);
    // _edgeService.extractEdge(rawEdges, contours[_indexOfMaxArea], dstEdgeImg);
    imshow("edge", dstEdgeImg2);


    //残ったエッジ画像と色による抽出画像を合成する
    bitwise_or(mat2, dstEdgeImg2, dstEdgeImg2);

    vPs contours2;
    findContours(dstEdgeImg2, contours2, CV_RETR_LIST, CV_CHAIN_APPROX_NONE);
    _indexOfMaxArea = calcIndexOfMaxArea(contours2);
    //_indexOfMaxArea = indexiesOfTop3Area[0];
    Mat mat3 = Mat::zeros(srcSet.size(), CV_8UC1);
    drawContours(mat3, contours2, 0, Scalar(255, 255, 255), CV_FILLED, LINK_EIGHT);

    result.setMaskImg(mat3);
        if(_indexOfMaxArea>=0) {
            result.setContour(contours2[_indexOfMaxArea]);
            result.calcRotatedRect();
            result.calcRoi();
            result.calcExpectedRoiConsideringMove(_previousRegion);
        }
        
        _previousRegion = result;

    //     int minSize = 200;
    //     _contourService.fillContours(dstEdgeImg, minSize);
    

}


/**
* calibratorで呼び出される
*/
void Extractor::setPreviousRegion(Region& region) {

}

