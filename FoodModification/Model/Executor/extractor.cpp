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


void Extractor::extract(const MatSet& srcSet) {

    ChannelSet channelSet(srcSet);
    
    //エッジ画像を作成する
   // _edgeFactory.createEdges(srcSet, channelSet);
  
    // Mat dstEdgeImg(srcSet.size().height,srcSet.size().width, CV_8UC1, 255);
    // revMergeEdges(rawEdges, _regionManager.previousRegion().expectedRoi(), dstEdgeImg);
    
    _edgeFactory.createEdges(channelSet, _regionManager.previousRegion().expectedRoi());
    imshow("edge", _edgeManager.currentEdge().roiMergedMat());


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
    
    // //エッジ画像を取得する
    // _edgeService.drawEdge(dstEdgeImg2, dstEdgeImg2, 255);
    // // _edgeService.extractEdge(rawEdges, contours[_indexOfMaxArea], dstEdgeImg);
    // imshow("edge", dstEdgeImg2);


    // //残ったエッジ画像と色による抽出画像を合成する
    // bitwise_or(mat2, dstEdgeImg2, dstEdgeImg2);

    // vPs contours2;
    // findContours(dstEdgeImg2, contours2, CV_RETR_LIST, CV_CHAIN_APPROX_NONE);
    // _indexOfMaxArea = calcIndexOfMaxArea(contours2);
    // //_indexOfMaxArea = indexiesOfTop3Area[0];
    // Mat mat3 = Mat::zeros(srcSet.size(), CV_8UC1);
    // drawContours(mat3, contours2, 0, Scalar(255, 255, 255), CV_FILLED, LINK_EIGHT);

    //     int minSize = 200;
    //     _contourService.fillContours(dstEdgeImg, minSize);
}


