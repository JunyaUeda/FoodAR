#include "mainProcedure.h"

void MainProcedure::start() {
    _isProcessed = true;
    _sourcer.setUp();
    _saver.save();
    
    while (_isProcessed) {
        map<int, Mat> edges; QVector<Mat> edgeImgs; MatSet matSet;
        _sourcer.loadSrc(matSet);
		imshow(_windowManager.windowName(0), matSet.bgr());

        _extractor.extract(matSet);
  //       edgeController.calculateEdges(matSet.channelImgs(), edgeImgs);
  //       MatSet srcSet(srcBGRImg);
        // _extractor.extract(srcSet, edgeImgs);
        
        // vector<Rect> rects;
        // if(textureParam->isNoTexture()) {
        //     textureController.setROI(dstContours, rects);
        // } else {
        //     Mat textureImg = textureController.createTexture(dstContours, maskImg, rects, srcController.srcParam()->textureImg() );
        //     textureParam->setImg(textureImg);
        //     imshow("textureImg", textureImg);
        // }
        

        // dstBGRImg = srcBGRImg.clone();
        // convertController.convert(srcBGRImg,srcHSVImg, dstBGRImg, maskImg, rects, textureParam);
        // if(resizeFlag) {
        //     resize(dstBGRImg, dstBGRImg, dstSize, 0, 0, INTER_LINEAR);
        // }
        // imshow("dstImg",dstBGRImg);

        char ch = waitKey(33);
        if ( ch == 27 ) break;
    }
}

void MainProcedure::stop() {
    _isProcessed = false;
}

MainProcedure::MainProcedure() {
}

MainProcedure& MainProcedure::getInstance() {
    static MainProcedure instance;
    return instance;
}
