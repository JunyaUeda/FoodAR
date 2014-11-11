#include "regionService.h"
#include <qDebug>
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

QVector<int> RegionService::calculateAverage(const MatSet* matSet, QList<Point> region) {
    QVector<int> averages(9,0);
   
    if(!region.size()) {
        qDebug() << "region.count()=0";
        return averages;
    }

    QVector<int> sumOfValue = countSum(matSet, region);

    for(int i=0; i<9; i++) {

      averages[i] = sumOfValue[i] / region.count();
    }

    return averages;
}

/**
* 指定領域の9チャンネルの平均値を返す
*
*/
QVector<int> RegionService::calculateAverage(Mat srcBGRImg, QList<Point> region) {
    MatSet matSet(srcBGRImg);
    return calculateAverage(&matSet, region);
}

/**
* BGR, HSV, YCrCbの9チャンネルの指定領域のピクセル値の合計を求める
*
*/
QVector<int> RegionService::countSum(Mat srcBGRImg, Mat refImg, Scalar refColor) {
	
    QList<Point> region = toPointList(refImg, refColor);
	  return countSum(srcBGRImg, region);
}

/**
* BGR, HSV, YCrCbの9チャンネルの指定領域のピクセル値の合計を求める
*
*/
QVector<int> RegionService::countSum(Mat srcBGRImg, QList<Point> region) {
    MatSet matSet(srcBGRImg);
    return countSum(&matSet, region);
}


QVector<int> RegionService::countSum(const MatSet* matSet, QList<Point> region) {
  
     QVector<int> sumOfValue(9,0);

    for(Point point : region) {

      sumOfValue[0] = sumOfValue[0] + B(matSet->bgr(), point.x, point.y);
      sumOfValue[1] = sumOfValue[1] + G(matSet->bgr(), point.x, point.y);
      sumOfValue[2] = sumOfValue[2] + R(matSet->bgr(), point.x, point.y);
      sumOfValue[3] = sumOfValue[3] + B(matSet->hsv(), point.x, point.y);
      sumOfValue[4] = sumOfValue[4] + G(matSet->hsv(), point.x, point.y);
      sumOfValue[5] = sumOfValue[5] + R(matSet->hsv(), point.x, point.y);
      sumOfValue[6] = sumOfValue[6] + B(matSet->ycrcb(), point.x, point.y);
      sumOfValue[7] = sumOfValue[7] + G(matSet->ycrcb(), point.x, point.y);
      sumOfValue[8] = sumOfValue[8] + R(matSet->ycrcb(), point.x, point.y);

    }

    return sumOfValue;
}


/**
* 指定領域の9チャンネルのToleranceを返す
*
*/
QVector<int> RegionService::calculateTolerance(Mat srcBGRImg, QList<Point> region) {
    QVector<int> tolerance(9,0);
    
    return tolerance;
}

/**
* 指定領域の9チャンネルのHistogramを作成して返す
*
*/
QVector<QVector<int> > RegionService::createHistogram(Mat srcBGRImg, QList<Point> region) {
  
    MatSet matSet(srcBGRImg);
    return createHistogram(&matSet, region);
}

QVector<QVector<int> > RegionService::createHistogram(const MatSet* matSet, QList<Point> region) {
  
  QVector<QVector<int> > histograms(9);

  for(int i=0; i<9; i++) {
    int BITE = 256;
    QVector<int> channelHistogram(matSet->bgr().elemSize1()*BITE, 0);
    histograms[i] = channelHistogram;
  }

    for(Point point : region) {
        histograms.value(0)[B(matSet->bgr(), point.x, point.y)]++;
        histograms.value(1)[G(matSet->bgr(), point.x, point.y)]++;
        histograms.value(2)[R(matSet->bgr(), point.x, point.y)]++;
        histograms.value(3)[B(matSet->hsv(), point.x, point.y)]++;
        histograms.value(4)[G(matSet->hsv(), point.x, point.y)]++;
        histograms.value(5)[R(matSet->hsv(), point.x, point.y)]++;
        histograms.value(6)[B(matSet->ycrcb(), point.x, point.y)]++;
        histograms.value(7)[G(matSet->ycrcb(), point.x, point.y)]++;
        histograms.value(8)[R(matSet->ycrcb(), point.x, point.y)]++;
    }
  

  return histograms;
}