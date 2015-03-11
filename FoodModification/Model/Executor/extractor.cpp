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
    // _edgeFactory.createEdges(channelSet, _regionManager.previousRegion().expectedRoi());
    _edgeFactory.createEdge(channelSet, _regionManager.previousRegion().expectedRoi());
    imshow("edge", _edgeManager.currentEdge().roiMergedMat());


    Mat mat = Mat::zeros(srcSet.size(), CV_8UC1);

    if(_regionManager.isPreviousRegionExisted()){
        _contourExisted.createMaskByColor(mat, channelSet);
    } else {
        _contourNonExisted.createMaskByColor(mat, channelSet);
    }
    
    dilate(mat, mat, cv::Mat(), Point(-1,-1), _extractionManager.dilateCount());
	//erode(mat, mat, cv::Mat(), Point(-1,-1), _extractionManager.erodeCount());
    imshow("ExtractByColor", mat);

    // add(mat, _edgeManager.currentEdge().roiMergedMat(), mat );
    // imshow("add", mat);
    // vPs contoursForAdd;
    // findContours(mat, contoursForAdd, CV_RETR_LIST, CV_CHAIN_APPROX_NONE);
    // for(int i=0; i<contoursForAdd.size(); i++) {
    //     drawContours(mat, contoursForAdd, i, Scalar(255, 255, 255), CV_FILLED, LINK_EIGHT);
    // }
    // erode(mat, mat, cv::Mat(), Point(-1,-1), _extractionManager.erodeCount());
    //dilate(mat, mat, cv::Mat(), Point(-1,-1), _extractionManager.dilateCount());
    
    imshow("draw", mat);
    Contours contours(mat);
    
  //   if(contours.hasMultiContour() ) {
		// _multiContour.drawAndCalcRegion(contours);
  //   } else {
		_oneContour.drawAndCalcRegion(contours);
    //}
    //_oneContour.drawAndCalcRegion(contours);
}
