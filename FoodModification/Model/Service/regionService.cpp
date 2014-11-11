#include "regionService.h"

RegionService::RegionService() {
}

/**
* 画像から指定した色のピクセル座標をListに格納して返す
* @param refImg ユーザーがマウスで指定した領域に色が塗られた画像
* @param refColor 指定した色
*/
QList<Point> RegionService::toPointList(Mat refImg, Scalar refColor) {
	QList<Point> region;
	for(int y=0; y<refImg.rows; y++) {
		for(int x=0; x<refImg.cols; x++) {
			Scalar hereColor(B(refImg,x,y), G(refImg,x,y), R(refImg,x,y));
			if(hereColor == refColor) {
                region.push_back(Point(x,y));
            }
		}
	}
	return region;
}

/**
* 指定領域の9チャンネルの平均値を返す
*
*/
QVector<int>* RegionService::calculateAverage(Mat srcBGRImg, QList<Point>& region) {
	QVector<int> averages(9);
   	QVector<int>::iterator it;
   	for(it = averages.begin(); it != averages.end(); ++it) {
   		(*it) = 0;
   	}

   	QVector<int>* sumOfValue = countSum(srcBGRImg, region);

   	if(region.count() > 0) {
   		return &averages;
   	}

   	for(int i=0; i<9; i++) {

   		averages[i] = (*sumOfValue)[i] / region.count();
   	}

   return &averages;
}

/**
* BGR, HSV, YCrCbの9チャンネルの指定領域のピクセル値の合計を求める
*
*/
QVector<int>* RegionService::countSum(Mat srcBGRImg, Mat refImg, Scalar refColor) {
	
    QVector<int> sumOfValue(9);
    QVector<int>::iterator it;
    for(it = sumOfValue.begin(); it != sumOfValue.end(); ++it) {
    	(*it) = 0;
    }

    Mat srcHSVImg, srcYCrCbImg;
    cvtColor(srcBGRImg, srcHSVImg, CV_BGR2HSV);
    cvtColor(srcBGRImg, srcYCrCbImg,CV_BGR2YCrCb);

	for(int y=0; y<refImg.rows; y++) {
		for(int x=0; x<refImg.cols; x++) {
			Scalar hereColor(B(refImg,x,y), G(refImg,x,y), R(refImg,x,y));
			if(hereColor == refColor) {
                sumOfValue[0] = sumOfValue[0] + B(srcBGRImg,x,y);
                sumOfValue[1] = sumOfValue[1] + G(srcBGRImg,x,y);
                sumOfValue[2] = sumOfValue[2] + R(srcBGRImg,x,y);
				sumOfValue[3] = sumOfValue[3] + B(srcHSVImg,x,y);
				sumOfValue[4] = sumOfValue[4] + G(srcHSVImg,x,y);
				sumOfValue[5] = sumOfValue[5] + R(srcHSVImg,x,y);
				sumOfValue[6] = sumOfValue[6] + B(srcYCrCbImg,x,y);
				sumOfValue[7] = sumOfValue[7] + G(srcYCrCbImg,x,y);
				sumOfValue[8] = sumOfValue[8] + R(srcYCrCbImg,x,y);
			}
		}
	}
	return &sumOfValue;
}

/**
* BGR, HSV, YCrCbの9チャンネルの指定領域のピクセル値の合計を求める
*
*/
QVector<int>* RegionService::countSum(Mat srcBGRImg, QList<Point>& region) {
	
   QVector<int> sumOfValue(9);
    QVector<int>::iterator it;
    for(it = sumOfValue.begin(); it != sumOfValue.end(); ++it) {
    	(*it) = 0;
    }

    Mat srcHSVImg, srcYCrCbImg;
    cvtColor(srcBGRImg, srcHSVImg, CV_BGR2HSV);
    cvtColor(srcBGRImg, srcYCrCbImg,CV_BGR2YCrCb);

    QList<Point>::iterator point;
    for(point = region.begin(); point != region.end(); ++point) {

        sumOfValue[0] = sumOfValue[0] + B(srcBGRImg, (*point).x, (*point).y);
        sumOfValue[1] = sumOfValue[1] + G(srcBGRImg, (*point).x, (*point).y);
        sumOfValue[2] = sumOfValue[2] + R(srcBGRImg, (*point).x, (*point).y);
		sumOfValue[3] = sumOfValue[3] + B(srcHSVImg, (*point).x, (*point).y);
		sumOfValue[4] = sumOfValue[4] + G(srcHSVImg, (*point).x, (*point).y);
		sumOfValue[5] = sumOfValue[5] + R(srcHSVImg, (*point).x, (*point).y);
		sumOfValue[6] = sumOfValue[6] + B(srcYCrCbImg, (*point).x, (*point).y);
		sumOfValue[7] = sumOfValue[7] + G(srcYCrCbImg, (*point).x, (*point).y);
		sumOfValue[8] = sumOfValue[8] + R(srcYCrCbImg, (*point).x, (*point).y);

	}
	return &sumOfValue;
}

/**
* BGR, HSV, YCrCbの9チャンネルの指定領域のピクセル値の合計を求める
*
*/
QVector<int>* RegionService::countSum(Source imgs, QList<Point>& region) {
	
    QVector<int> sumOfValue(9);
    QVector<int>::iterator it;
    for(it = sumOfValue.begin(); it != sumOfValue.end(); ++it) {
    	(*it) = 0;
    }

    QList<Point>::iterator ite;
    for(ite = region.begin(); ite != region.end(); ++ite) {
    	for(it = sumOfValue.begin(); it != sumOfValue.end(); ++it) {
    		//(*it) = (*it);
    	}
    }

	return &sumOfValue;
}
