#include "mainProcedure.h"

void MainProcedure::start() {
    _isProcessed = true;
    _sourcer.setUp();
    _saver.save();
    
    while (_isProcessed) {

        MatSet matSet;
        _sourcer.loadSrc(matSet);
		imshow(_windowManager.windowName(0), matSet.bgr());

        Region extractedRegion;
        _extractor.extract(matSet,extractedRegion);
        
        Mat resultTexture = Mat::zeros(matSet.size(), CV_8UC3);
        
        if(_textureManager.currentMediaType() != MediaType::no) {
            _textureFactory.create(extractedRegion, resultTexture);
            imshow("textureImg", resultTexture);
        }
         
        Mat dstBGRImg = matSet.bgr().clone();
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
