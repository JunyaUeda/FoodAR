#include "extractor.h"

#define LINK_EIGHT 8
#define LINK_FOUR 4
#define LINK_CVAA CV_AA

Extractor::Extractor() {

    _binarizationThreshold[0] = 50;  //Blue
    _binarizationThreshold[1] = 40;  //Green
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
    ChannelSet channelSet(srcSet);
    
    //エッジ画像を取得する
    vector<Mat> rawEdges;
    _edgeFactory.createEdges(srcSet, rawEdges, channelSet);
  
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
                // if(_featureReference.isWithinThreshold(srcSet, Point(x,y)) ) { 
                //         L(mat,x,y) = 255;     
                //     } 

                if(L(channelSet.crMat(),x,y) >= _binarizationThreshold[7] && L(channelSet.gMat(),x,y) <=_binarizationThreshold[1] && L(channelSet.rMat(),x,y) >=_binarizationThreshold[2]) {
    
                    L(mat,x,y) = 255;
                    
                } else if(L(channelSet.sMat(),x,y) >=_binarizationThreshold[4] && L(channelSet.crMat(),x,y) >= 154 && L(channelSet.gMat(),x,y) <= 40 && L(channelSet.bMat(),x,y) <= 41 ) {
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
                if(L(channelSet.crMat(),x,y) >= _binarizationThreshold[7] && L(channelSet.gMat(),x,y) <=_binarizationThreshold[1] && L(channelSet.rMat(),x,y) >=_binarizationThreshold[2]) {
    
                    L(mat,x,y) = 255;
                    
                } else if(L(channelSet.sMat(),x,y) >=_binarizationThreshold[4] && L(channelSet.crMat(),x,y) >= 154 && L(channelSet.gMat(),x,y) <= 40 && L(channelSet.bMat(),x,y) <= 41 ) {
                    L(mat,x,y) = 255;
                }
   
            }
        }

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
        Point2f vertices[4];
        _previousRegion.rotatedRect().points(vertices);
        vector<Point> allPoints = contours[indexiesOfTop3Area[0]];
        if(indexiesOfTop3Area[2] >= 0) {
            drawContours(mat2, contours, indexiesOfTop3Area[1], Scalar(255, 255, 255), CV_FILLED, LINK_EIGHT);
            drawContours(mat2, contours, indexiesOfTop3Area[2], Scalar(255, 255, 255), CV_FILLED, LINK_EIGHT);
            drawContours(mat2, contours, _indexOfMaxArea, Scalar(255, 255, 255), CV_FILLED, LINK_EIGHT);

            for(int i=1; i<3; i++) {
                for(Point point :contours[indexiesOfTop3Area[i]]) {
                    if(isInROI(point, vertices)) {
                        allPoints.push_back(point);
                    }
                    
                }
            }

        } else {
            drawContours(mat2, contours, indexiesOfTop3Area[1], Scalar(255, 255, 255), CV_FILLED, LINK_EIGHT);
            drawContours(mat2, contours, _indexOfMaxArea, Scalar(255, 255, 255), CV_FILLED, LINK_EIGHT);
           
            for(int i=1; i<2; i++) {
                for(Point point :contours[indexiesOfTop3Area[i]]) {
                    if(isInROI(point, vertices)) {
                        allPoints.push_back(point);
                    }
                }
            }
    
        }
    
        RotatedRect rect = minAreaRect(Mat(allPoints));
       
        result.setContour(contours[_indexOfMaxArea]);//TODO:本来は結合した輪郭を入れるか別にいれる必要がある
        result.setMaskImg(mat2);
        result.setRotatedRect(rect);
        result.calcRoiWithRotatedRect();
        result.calcExpectedRoiConsideringMoveWithRotatedRect(_previousRegion);

        _previousRegion = result;

       // imshow("merge", mat2);
    } else {

        drawContours(mat2, contours, _indexOfMaxArea, Scalar(255, 255, 255), CV_FILLED, LINK_EIGHT);
        result.setMaskImg(mat2);
        if(_indexOfMaxArea>=0) {
            result.setContour(contours[_indexOfMaxArea]);
            result.calcRotatedRect();
            result.calcRoi();
            result.calcExpectedRoiConsideringMove(_previousRegion);
        }
        
        _previousRegion = result;
      
       // imshow("merge", mat2);
    }
    
        
}


void Extractor::extractCoffee(MatSet& srcSet, Region& result) {


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
    Mat dstEdgeImg2 = dstEdgeImg.clone();
    //erode(dstEdgeImg, dstEdgeImg, cv::Mat(), Point(-1,-1), 2);
    //imshow("revEdge", dstEdgeImg);

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

                if(L(ycrcbChannels[1],x,y) <= _binarizationThreshold[7] && L(bgrChannels[1],x,y) <=_binarizationThreshold[1] && L(bgrChannels[2],x,y) <=_binarizationThreshold[2]
                    && L(ycrcbChannels[0],x,y) <= _binarizationThreshold[6
                        && L(hsvChannels[2],x,y) <=_binarizationThreshold[5]]) {
    
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
                

                if(L(ycrcbChannels[1],x,y) <= _binarizationThreshold[7] && L(bgrChannels[1],x,y) <=_binarizationThreshold[1] && L(bgrChannels[2],x,y) <=_binarizationThreshold[2]
                    && L(ycrcbChannels[0],x,y) <= _binarizationThreshold[6
                        && L(hsvChannels[2],x,y) <=_binarizationThreshold[5]]) {
    
                    L(mat,x,y) = 255;
                }  
            
            }
        }

    }
    
    dilate(mat, mat, cv::Mat(), Point(-1,-1), _extractionManager.dilateCount());
    //erode(mat, mat, cv::Mat(), Point(-1,-1), _extractionManager.erodeCount());
    imshow("colorExtract", mat);

    
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

