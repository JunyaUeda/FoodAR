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

void Extractor::extract(MatSet& srcSet) {
    //_featureReference.displayThreshold();
    Region region(srcSet.size() );
    //コピーの速度をきにしないなら右のほうが読みやすい
    _extractService.extractRegionByColor(srcSet, region);// Region region = _extractService.extractRegionByColor(srcSet);
    imshow("new extract", region.maskImg());

    Region areamaxRegion = _extractService.acquireMaxAreaRegion(region);

    //エッジ画像を取得する
    vector<Mat> rawEdges;
    _edgeFactory.createEdges(srcSet, rawEdges);
    

    // //エッジ画像を取得する
    Mat dstEdgeImg = _edgeService.extractEdge(rawEdges, areamaxRegion.rois()[0]);
    imshow("edge", dstEdgeImg);


    //残ったエッジ画像と色による抽出画像を合成する
    bitwise_or(areamaxRegion.maskImg(), dstEdgeImg, dstEdgeImg);
    drawContours(dstEdgeImg, areamaxRegion.contours(), 0, Scalar(255, 255, 255), CV_FILLED, LINK_EIGHT);

    int minSize = 200;
	_contourService.fillContours(dstEdgeImg, minSize);
    imshow("merge", dstEdgeImg);

    Region result(dstEdgeImg);
    result.calcContours();
}
