#include "edgeService.h"

EdgeService::EdgeService() {

}

void EdgeService::aqcuireEdgeImgs() {

}

Mat EdgeService::extractEdge(vector<Mat>& channelEdgeImgs, Rect& roi) {

    if(!channelEdgeImgs.size()) {
        Mat mat;
        return  mat;  
    }

     Mat resultImg = Mat::zeros(channelEdgeImgs[0].size(), CV_8UC1);

    for(int y=roi.y; y<(roi.y+roi.height); y++) {
        for(int x=roi.x; x<(roi.x+roi.width); x++) {
            int score = 0;
            for(Mat mat : channelEdgeImgs) {
                if(L(mat,x,y) == 255) score++;
            }
            
            if(score >= 2) {
                L(resultImg, x,y) = 255;
            }
        }
    }
     return resultImg;
}

/**
*@param cv::Mat
*@note エッジ画像の拡張処理を３チャンネル分行う
*/
void EdgeService::dillateEdge(cv::Mat *channelEdgeImgs) {

    cv::imshow("before edge", channelEdgeImgs[0]);
    cv::Point ANCHOR = cv::Point(-1,-1);//構造要素内のアンカー位置。デフォルト値の(-1,-1)はアンカーが構造要素の中心にあることを意味する
    int ITERATIONS = 1;
    for(int channel=0; channel<3; channel++) {
        cv::dilate(channelEdgeImgs[channel], channelEdgeImgs[channel], cv::Mat(), ANCHOR, ITERATIONS);//element = cv::Mat()の場合　3×3の矩形構造要素が使われる
    }//element = cv::Mat()の場合　3×3の矩形構造要素が使われる
    cv::imshow("after edge", channelEdgeImgs[0]);

}


/**
*エッジ画像を参照しエッジの線を出力画像に描画する.
*@param cv::Mat
*@param luminance:描画するエッジ線の明度
*@note 
*/
void EdgeService::drawEdge(Mat srcEdgeImg, Mat dstDrawnImg, int luminace) {

    for(int y=0; y<srcEdgeImg.rows; y++){
        for(int x=0; x<srcEdgeImg.cols; x++) {
            if(L(srcEdgeImg,x,y) == 255) {
                L(dstDrawnImg,x,y) = luminace;
            }
        }
    }

}
