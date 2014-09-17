#include "extractController.h"
#include "../Utils/opencvUtils.h"

#define LINK_EIGHT 8
#define LINK_FOUR 4
#define LINK_CVAA CV_AA

ExtractController::ExtractController(ExtractParamManager *extractParamManager) {

    this->extractParamManager = extractParamManager;

}

void ExtractController::extract(cv::Mat srcBGRImg, cv::Mat srcHSVImg, cv::Mat srcYCrCbImg, cv::Mat srcGrayImg,
	cv::Mat dstImg, cv::Mat* BGREdges) {

    this->extractByColor(srcBGRImg, srcHSVImg, dstImg);
    cv::imshow("extractByColor",dstImg);

    cv::Point ANCHOR = cv::Point(-1,-1);//構造要素内のアンカー位置。デフォルト値の(-1,-1)はアンカーが構造要素の中心にあることを意味する
    int ITERATIONS = 1;
    //cv::erode(dstImg, dstImg, cv::Mat(), ANCHOR, ITERATIONS);
    //cv::imshow("after erode",dstImg);
    cv::dilate(dstImg, dstImg, cv::Mat(), ANCHOR, ITERATIONS);//element = cv::Mat()の場合　3×3の矩形構造要素が使われる
    cv::imshow("after dilate",dstImg);

    std::vector<std::vector<cv::Point>> contours;
    cv::cvtColor(dstImg, dstImg, CV_BGR2GRAY);
    cv::findContours(dstImg, contours, CV_RETR_LIST, CV_CHAIN_APPROX_NONE);
    int lineType = LINK_EIGHT;
    size_t max=0;
    
    for(int i=0; i<contours.size(); ++i) {
        size_t count = contours[i].size();
        if(count < 200) {
            //continue;
            cv::drawContours(dstImg, contours, i, cv::Scalar(0, 0, 0), CV_FILLED, lineType);
        } else {
            cv::drawContours(dstImg, contours, i, cv::Scalar(255, 255, 255), CV_FILLED, lineType);
        }
        
    }
    cv::imshow("after drawContours",dstImg);

    std::vector< std::vector<cv::Point> > contours2;
    cv::findContours(dstImg, contours2, CV_RETR_LIST, CV_CHAIN_APPROX_NONE);
    //qDebug() << "contours2" << contours2.size();
    std::vector<double> areas(contours2.size());
    for(int i=0; i<contours2.size(); i++) {
        areas[i] = cv::contourArea(contours2[i]);
    }

    
    std::vector<cv::Moments> mu(contours2.size());
    for(int i=0; i<contours2.size(); i++) {
        mu[i] = cv::moments(contours2[i], false);
    }

    std::vector<cv::Point> mCenters(contours2.size());
    for(int i=0; i<contours2.size(); i++) {
        mCenters[i] = cv::Point(mu[i].m10/mu[i].m00, mu[i].m01/mu[i].m00);
    }

    //qDebug() << "center.x =" << mCenters[0].x;

    cv::Mat dstEdgeImg;
    dstEdgeImg.create(srcBGRImg.size(), CV_8UC1);
    this->edgeService->extractEdge(BGREdges,dstEdgeImg);
    cv::Mat dstEdgeImg2;
    dstEdgeImg2= cv::Mat::zeros(dstEdgeImg.size(), dstEdgeImg.type());

    std::vector<cv::Rect> rects(contours2.size());
    for(int i=0; i<contours2.size(); i++) {
        rects[i] = cv::boundingRect(contours2[i]);

        cv::Rect cannyRect = cv::Rect(rects[i].x-rects[i].width*0.2, rects[i].y-rects[i].height*0.2, rects[i].width*1.2, rects[i].height*1.2);
        int w = srcBGRImg.size().width;
        int h = srcBGRImg.size().height;
        int y_min_canny=0, y_max_canny=h, x_min_canny=0, x_max_canny=w;
        if(cannyRect.x <0) x_min_canny=0;
        else x_min_canny = cannyRect.x;
        if( (cannyRect.x+cannyRect.width) >w) x_max_canny = w;
        else x_max_canny = cannyRect.x+cannyRect.width;
                    
        if(cannyRect.y<0) y_min_canny=0;
        else y_min_canny = cannyRect.y;
        if( (cannyRect.y+cannyRect.height) >h) y_max_canny = h;
        else y_max_canny = cannyRect.y+cannyRect.height;

        for(int y=y_min_canny; y<y_max_canny; y++){     
            for(int x=x_min_canny; x<x_max_canny; x++){ 
                if(L(dstEdgeImg,x,y) == 255) {
                    L(dstEdgeImg2,x,y) = 255;
                }
            }
        }
        cv::drawContours(dstEdgeImg2, contours2, i, cv::Scalar(255, 255, 255), CV_FILLED, lineType);
    }
    cv::imshow("dstEdgeImg2",dstEdgeImg2);
    

    


    std::vector< std::vector<cv::Point> > contours3;
    //手を近づけるとruntimeエラーになる
    cv::findContours(dstEdgeImg, contours3,CV_RETR_LIST, CV_CHAIN_APPROX_NONE);

    // std::vector<std::vector<cv::Point> > contours4;
    // for(int i=0; i<contours3.size(); ++i) {
    //     size_t count = contours3[i].size();
    //     if(count < 400) {
    //         //continue;
    //     } else {
    //         for(int j=0; j<contours2.size(); j++) {
    //             if(cv::pointPolygonTest(contours3[i],mCenters[j], false)) {
    //                 contours4.push_back(contours3[i]);
    //                 // if(areas[j] < cv::contourArea(contours3[i])) {
    //                 //     contours4.push_back(contours3[i]);
    //                 // }
    //             }
    //         }
            
    //     }
        
    // }

    // qDebug() << "contours4" << contours4.size();
    cv::Mat dstEdgeColorImg;
    dstEdgeColorImg = cv::Mat::zeros(dstImg.size(), dstImg.type());
    // if(contours4.size() > 0) {
    //     for(int i=0; i<contours4.size(); i++) {
    //         size_t count = contours4[i].size();
    //         cv::drawContours(dstEdgeColorImg, contours4, i, cv::Scalar(255, 255, 255), CV_FILLED, lineType);        
    //     } 
    // } 

    // if(contours3.size() > 0) {
    //     for(int i=0; i<contours3.size(); i++) {
    //         size_t count = contours3[i].size();
    //         cv::drawContours(dstEdgeColorImg, contours3, i, cv::Scalar(255, 255, 255), CV_FILLED, lineType);        
    //     } 
    // }

    for(int i=0; i<contours2.size(); i++) {
        mCenters[i] = cv::Point(mu[i].m10/mu[i].m00, mu[i].m01/mu[i].m00);
        cv::circle(dstEdgeColorImg, mCenters[i], 20, cv::Scalar(255,255,255), 5, lineType, 0);
    }
    
    cv::imshow("dstEdgeColorImg", dstEdgeColorImg);

	// std::vector<std::vector<cv::Point>> contours = contourService->getTargetContours(srcGrayImg);
	// if(contours.size() >0 ) {
	// 	qDebug() << "contours != null" << contours.size();
	// 	//targetParam->setContours(&contours);
	// }
    
 //    cv::Scalar color;
 //    color = cv::Scalar(255, 255, 255);
 //    int lineType = LINK_EIGHT;
 //    int indexOfMaxAreaContour = contourService->getMaxAreaContourIndex(contours);
 //    //cv::drawContours(dstImg, contours, indexOfMaxAreaContour, color, CV_FILLED, lineType);
 //    //int indexOfMaxAreaContour = contourService->getMaxAreaContourIndex(targetParam->getContours());
 //    //cv::drawContours(dstImg, targetParam->getContours(), indexOfMaxAreaContour, color, CV_FILLED, lineType);

 //   // std::vector<std::vector<cv::Point>> contours = targetParam->getContours();
 //    cv::Rect cannyRect = cv::boundingRect(contours[indexOfMaxAreaContour]);
 //    cannyRect = cv::Rect(cannyRect.x-cannyRect.width*0.2, cannyRect.y-cannyRect.height*0.2, cannyRect.width*1.2, cannyRect.height*1.2);
 //    int w = srcBGRImg.size().width;
 //    int h = srcBGRImg.size().height;
 //    int y_min_canny=0, y_max_canny=h, x_min_canny=0, x_max_canny=w;
	// if(cannyRect.x <0) x_min_canny=0;
	// else x_min_canny = cannyRect.x;
	// if( (cannyRect.x+cannyRect.width) >w) x_max_canny = w;
	// else x_max_canny = cannyRect.x+cannyRect.width;
				
	// if(cannyRect.y<0) y_min_canny=0;
	// else y_min_canny = cannyRect.y;
	// if( (cannyRect.y+cannyRect.height) >h) y_max_canny = h;
	// else y_max_canny = cannyRect.y+cannyRect.height;

 //    // cv::imshow("blue", BGRChannels[0]);
 //    // cv::imshow("green", BGRChannels[1]);
 //    // cv::imshow("red", BGRChannels[2]);
 //    // for(int i=0; i<40; i++) {
 //    //     qDebug() << BGREdges[0].at<unsigned char>(i, i)+BGREdges[1].at<unsigned char>(i, i)+BGREdges[2].at<unsigned char>(i, i);
 //    // }
 //    // cv::Mat single;
 //    // single = cv::Mat::zeros(srcBGRImg.size(), CV_8UC1);
 //    // for(int y=0; y<single.rows; y++) {
 //    // 	for(int x=0; x<single.cols; x++) {
 //    // 			VALUE(single, x,y) = VALUE(BGREdges[0], x,y);
 //    // 	}
 //    // }
 //    // cv::imshow("single",single);

 //    cv::Mat total;
 //    //total.create(srcBGRImg.size(), CV_8UC1);
 //    total = cv::Mat::zeros(srcBGRImg.size(), CV_8UC1);

 //    for(int y=y_min_canny; y<y_max_canny; y++){		
	// 	for(int x=x_min_canny; x<x_max_canny; x++){	
	// 		int sum = VALUE(BGREdges[0], x,y) + VALUE(BGREdges[1], x,y) + VALUE(BGREdges[2], x,y);
 //     		if(sum > 250) {
 //    			VALUE(total, x,y) = 255;
 //     		}
	// 	}
	// }
 //    // for(int y=0; y<total.rows; y++) {
 //    // 	for(int x=0; x<total.cols; x++) {
 //    // 		int sum = VALUE(BGREdges[0], x,y) + VALUE(BGREdges[1], x,y) + VALUE(BGREdges[2], x,y);
 //    // 		if(sum > 250) {
 //    // 			VALUE(total, x,y) = 255;
 //    // 		}
 //    // 	}
 //    // }
 //    cv::imshow("total",total);
 //    std::vector<std::vector<cv::Point>> contours2 = contourService->getTargetContours(total);
 //    //cv::findContours(total, contours2, CV_RETR_LIST, CV_CHAIN_APPROX_NONE);
 //    int indexOfMaxAreaContour2 = contourService->getMaxAreaContourIndex(contours2);
 //    cv::drawContours(dstImg, contours2, indexOfMaxAreaContour2, color, CV_FILLED, lineType);
 //    cv::imshow("dstImg",dstImg);

}

void ExtractController::extractByColor(cv::Mat srcBGRImg, cv::Mat srcHSVImg, cv::Mat dstImg) {

    //this->extractService->extract(srcBGRImg, srcHSVImg, srcYCrCbImg, extractParamManager);
    int extractColorSpace = extractParamManager->getExtractColorSpace();

    if(extractColorSpace == 0) {
        this->extractService->extractByBGR(srcBGRImg, dstImg, extractParamManager);
    } else if(extractColorSpace == 1) {
        this->extractService->extractByHSV(srcHSVImg, dstImg, extractParamManager);
    }
    
}

void ExtractController::extractByContour(cv::Mat srcGrayImg, cv::Mat dstImg) {

}
