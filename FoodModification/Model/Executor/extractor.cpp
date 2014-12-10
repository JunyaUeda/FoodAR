#include "extractor.h"

#define LINK_EIGHT 8
#define LINK_FOUR 4
#define LINK_CVAA CV_AA

Extractor::Extractor() {

    _binarizationThreshold[0] = 50;  //Blue
    _binarizationThreshold[1] = 75;  //Green
    _binarizationThreshold[2] = 180;  //Red
    _binarizationThreshold[3] = 45;  //Hue
    _binarizationThreshold[4] = 140; //Saturation
    _binarizationThreshold[5] = 173; //Value
    _binarizationThreshold[6] = 125;  //Y
    _binarizationThreshold[7] = 155; //Cr
    _binarizationThreshold[8] = 30;  //Cb


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

    map<ChannelType, Mat> channelMats;

    Mat bgrChannels[3];
    split(srcSet.blur(), bgrChannels);
    channelMats.insert( map<ChannelType,Mat>::value_type(ChannelType::blue, bgrChannels[0]) );
    channelMats.insert( map<ChannelType,Mat>::value_type(ChannelType::green, bgrChannels[1]) );
    channelMats.insert( map<ChannelType,Mat>::value_type(ChannelType::red, bgrChannels[2]) );
    Mat hsvChannels[3];
	split(srcSet.hsv(), hsvChannels);
    channelMats.insert( map<ChannelType,Mat>::value_type(ChannelType::hue, hsvChannels[0]) );
    channelMats.insert( map<ChannelType,Mat>::value_type(ChannelType::saturation, hsvChannels[1]) );
    channelMats.insert( map<ChannelType,Mat>::value_type(ChannelType::value, hsvChannels[2]) );  
    Mat ycrcbChannels[3];
    split(srcSet.ycrcb(), ycrcbChannels);
    channelMats.insert( map<ChannelType,Mat>::value_type(ChannelType::y, ycrcbChannels[0]) );
    channelMats.insert( map<ChannelType,Mat>::value_type(ChannelType::cr, ycrcbChannels[1]) );
    channelMats.insert( map<ChannelType,Mat>::value_type(ChannelType::cb, ycrcbChannels[2]) );

    
    //エッジ画像を取得する
    vector<Mat> rawEdges;
    //_edgeFactory.createEdges(srcSet, rawEdges);
	_edgeFactory.createEdges(srcSet, rawEdges, channelMats);
  
    Mat dstEdgeImg(srcSet.size().height,srcSet.size().width, CV_8UC1, 255);
    revMergeEdges(rawEdges, _previousRegion.expectedRoi(), dstEdgeImg);
    erode(dstEdgeImg, dstEdgeImg, cv::Mat(), Point(-1,-1), 1);
    imshow("revEdge", dstEdgeImg);

    // threshold(ycrcbChannels[1], ycrcbChannels[1], 174, 255, CV_THRESH_BINARY);
    // threshold(hsvChannels[2], hsvChannels[2], 170, 255, CV_THRESH_BINARY);
    // threshold(bgrChannels[2], bgrChannels[2], 170, 255, CV_THRESH_BINARY);
    // imshow("cr",ycrcbChannels[1] );
    // imshow("v", hsvChannels[2]);
    // imshow("r", bgrChannels[2]);

    Mat mat = Mat::zeros(srcSet.size(), CV_8UC1);
    if(_indexOfMaxArea >=0){

        int yBegin = _previousRegion.expectedRoi().y;
        int yEnd = _previousRegion.expectedRoi().y+_previousRegion.expectedRoi().height;
        int xBegin = _previousRegion.expectedRoi().x;
        int xEnd = _previousRegion.expectedRoi().x+_previousRegion.expectedRoi().width;
    
        for(int y=yBegin; y<yEnd; y++) {
            for(int x=xBegin; x<xEnd; x++) {
                // if(_featureReference.isWithinThreshold(srcSet, Point(x,y)) ) { 
                //         L(mat,x,y) = 255;     
                //     } 

                if(L(ycrcbChannels[1],x,y) >= _binarizationThreshold[7] && L(bgrChannels[1],x,y) <=_binarizationThreshold[1] && L(bgrChannels[2],x,y) >=_binarizationThreshold[2]) {
    
                    L(mat,x,y) = 255;
                    
                } else if(L(hsvChannels[1],x,y) >=_binarizationThreshold[4] && L(ycrcbChannels[1],x,y) >= 154 && L(bgrChannels[1],x,y) <= 40 && L(bgrChannels[0],x,y) <= 41 ) {
                    L(mat,x,y) = 255;
                }

                
            }
        }
    
    } else {
        for(int y=0; y<srcSet.size().height; y++) {
            for(int x=0; x<srcSet.size().width; x++) {
                // if(_featureReference.isWithinThreshold(srcSet, Point(x,y)) ) { 
                //         L(mat,x,y) = 255;     
                //     } 
                if(L(ycrcbChannels[1],x,y) >= _binarizationThreshold[7] && L(bgrChannels[1],x,y) <=_binarizationThreshold[1] && L(bgrChannels[2],x,y) >=_binarizationThreshold[2]) {
    
                    L(mat,x,y) = 255;
                    
                } else if(L(hsvChannels[1],x,y) >=_binarizationThreshold[4] && L(ycrcbChannels[1],x,y) >= 154 && L(bgrChannels[1],x,y) <= 40 && L(bgrChannels[0],x,y) <= 41 ) {
                    L(mat,x,y) = 255;
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


void Extractor::extractCoffee(MatSet& srcSet, Region& result) {

    //いったん手続き型でアルゴリズムを作成する
    //TODO : メソッド分割すべし

    map<ChannelType, Mat> channelMats;

    Mat bgrChannels[3];
    split(srcSet.blur(), bgrChannels);
    channelMats.insert( map<ChannelType,Mat>::value_type(ChannelType::blue, bgrChannels[0]) );
    channelMats.insert( map<ChannelType,Mat>::value_type(ChannelType::green, bgrChannels[1]) );
    channelMats.insert( map<ChannelType,Mat>::value_type(ChannelType::red, bgrChannels[2]) );
    Mat ycrcbChannels[3];
    split(srcSet.ycrcb(), ycrcbChannels);
    channelMats.insert( map<ChannelType,Mat>::value_type(ChannelType::y, ycrcbChannels[0]) );
    channelMats.insert( map<ChannelType,Mat>::value_type(ChannelType::cr, ycrcbChannels[1]) );
    channelMats.insert( map<ChannelType,Mat>::value_type(ChannelType::cb, ycrcbChannels[2]) );
        
    threshold(bgrChannels[0], bgrChannels[0], 11, 255, CV_THRESH_BINARY_INV);
    threshold(bgrChannels[1], bgrChannels[1], 10, 255, CV_THRESH_BINARY_INV);
    threshold(bgrChannels[2], bgrChannels[2], 39, 255, CV_THRESH_BINARY_INV);
    threshold(ycrcbChannels[0], ycrcbChannels[0], 5, 255, CV_THRESH_BINARY_INV);
    threshold(ycrcbChannels[1], ycrcbChannels[1], 131, 255, CV_THRESH_BINARY_INV);
    threshold(ycrcbChannels[2], ycrcbChannels[2], 125, 255, CV_THRESH_BINARY);


    //エッジ画像を取得する
    vector<Mat> rawEdges;
    //_edgeFactory.createEdges(srcSet, rawEdges);
    _edgeFactory.createEdges(srcSet, rawEdges, channelMats);
    Mat dstEdgeImg(srcSet.size().height,srcSet.size().width, CV_8UC1, 255);
    Mat dstWhiteEdgeImg(srcSet.size().height,srcSet.size().width, CV_8UC1, Scalar::all(0));
    vector<Mat*> edgeImgs = {&dstEdgeImg, &dstWhiteEdgeImg};
    revMergeEdges(rawEdges, _previousRegion.expectedRoi(), edgeImgs);
    erode(dstEdgeImg, dstEdgeImg, cv::Mat(), Point(-1,-1), 1);
    dilate(dstWhiteEdgeImg, dstWhiteEdgeImg, cv::Mat(), Point(-1,-1),1);
    imshow("revEdge", dstEdgeImg);

     Mat mat = Mat::zeros(srcSet.size(), CV_8UC1);
    if(_indexOfMaxArea >=0){

        int yBegin = _previousRegion.expectedRoi().y;
        int yEnd = _previousRegion.expectedRoi().y+_previousRegion.expectedRoi().height;
        int xBegin = _previousRegion.expectedRoi().x;
        int xEnd = _previousRegion.expectedRoi().x+_previousRegion.expectedRoi().width;
    
        for(int y=yBegin; y<yEnd; y++) {
            for(int x=xBegin; x<xEnd; x++) {
                if(L(bgrChannels[0],x,y) == 255
                    && L(bgrChannels[1],x,y) == 255
                    && L(bgrChannels[2],x,y) == 255 
                    && L(ycrcbChannels[0],x,y) == 255
                    && L(ycrcbChannels[1],x,y) == 255
                    && L(ycrcbChannels[2],x,y) == 255) {
                   
                    if(_featureReference.isWithinThreshold(srcSet, Point(x,y)) ){ 
                            L(mat,x,y) = 255;
                    }
                    L(mat,x,y) =255; 
                }
                
            }
        }
    
    } else {
        for(int y=0; y<srcSet.size().height; y++) {
            for(int x=0; x<srcSet.size().width; x++) {

                if(L(bgrChannels[0],x,y) == 255
                    && L(bgrChannels[1],x,y) == 255
                    && L(bgrChannels[2],x,y) == 255 
                    && L(ycrcbChannels[0],x,y) == 255
                    && L(ycrcbChannels[1],x,y) == 255
                    && L(ycrcbChannels[2],x,y) == 255) {
                  
                    if(_featureReference.isWithinThreshold(srcSet, Point(x,y)) ){ 
                            L(mat,x,y) = 255;
                    }
                    L(mat,x,y) =255; 
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


    //残ったエッジ画像と色による抽出画像を合成する
    bitwise_or(mat2, dstWhiteEdgeImg, dstWhiteEdgeImg);
    vPs contours2;
    findContours(dstWhiteEdgeImg, contours2, CV_RETR_LIST, CV_CHAIN_APPROX_NONE);
    _indexOfMaxArea = calcIndexOfMaxArea(contours2);
    Mat mat3 = Mat::zeros(srcSet.size(), CV_8UC1);
   
    drawContours(mat3, contours2, _indexOfMaxArea, Scalar(255, 255, 255), CV_FILLED, LINK_EIGHT);

    //     drawContours(dstEdgeImg, areamaxRegion.contours(), 0, Scalar(255, 255, 255), CV_FILLED, LINK_EIGHT);

    //     int minSize = 200;
    //     _contourService.fillContours(dstEdgeImg, minSize);
        

    imshow("merge", mat3);

    result.setMaskImg(mat3);
    if(_indexOfMaxArea>=0) {
        result.setContour(contours2[_indexOfMaxArea]);
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

