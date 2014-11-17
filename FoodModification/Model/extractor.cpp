#include "extractor.h"

Extractor::Extractor() {
}

Extractor& Extractor::getInstance() {
    static Extractor instance;
    return instance;
}

void Extractor::extract(MatSet* srcSet, QVector<Mat> edges) {
    Region region(Size(srcSet->width(), srcSet->height()) );
    //コピーの速度をきにしないなら上のほうが読みやすい
	// Region region = _extractService.extractRegionByColor(srcSet);
    _extractService.extractRegionByColor(srcSet, &region);
    imshow("new extract", region.maskImg());

    Region areamaxRegion = _extractService.acquireMaxAreaRegion(&region);

    // //エッジ画像を取得する
    Mat dstEdgeImg;
    _edgeService.extractEdge(edges, dstEdgeImg);

    // int lineType = LINK_EIGHT;

    // vector<Rect> rois(contours.size());
    // for(int i=0; i<contours.size(); i++) {

    //     Rect rect = boundingRect(contours[i]);
    //     double SCALE_RATIO = 1.0;
    //     rois[i] = OpenCVUtils::calculateROI(dstImg.size(), rect, SCALE_RATIO);
        
    //     //色による抽出領域の近辺だけエッジを残す
    //     for(int y=rois[i].y; y<rois[i].y+rois[i].height; y++){     
    //         for(int x=rois[i].x; x<rois[i].x+rois[i].width; x++){ 
    //             if(L(dstEdgeImg,x,y) == 255) {
    //                 L(dstImg,x,y) = 255;
    //             }
    //         }
    //     }

    //     //残ったエッジ画像と色による抽出画像を合成する
    //     drawContours(dstImg, contours, i, Scalar(255, 255, 255), CV_FILLED, lineType);
    // }

}
