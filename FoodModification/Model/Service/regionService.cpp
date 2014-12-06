#include "regionService.h"
#include <qDebug>
RegionService::RegionService() {
}

/**
* 画像から指定した色のピクセル座標をListに格納して返す
* @param refImg ユーザーがマウスで指定した領域に色が塗られた画像
* @param refColor 指定した色
*/
QLPs RegionService::toPointList(Mat refImg, QVS refColor) {
    QLPs regions;
    for(Scalar color : refColor) {
        regions.push_back(toPointList(refImg, color));
    }
    return regions;
}

QLP RegionService::toPointList(Mat refImg, Scalar refColor) {
    QLP region;
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
* 指定領域のmaskImgを返す
* NOTE:初回の処理ループのときに使うextractorのpreviousRegionの初期化にしよう
*/
void RegionService::acquireMaskImg(const Mat refImg, QVS refColor, Mat& result) {
    for(Scalar color : refColor) {
        for(int y=0; y<refImg.rows; y++) {
            for(int x=0; x<refImg.cols; x++) {
                Scalar hereColor(B(refImg,x,y), G(refImg,x,y), R(refImg,x,y));
                if(hereColor == color) {
                    L(result,x,y) = 255;
                }
            }
        }
    }
}

/**
* 指定領域の9チャンネルの平均値を返す
*
*/

QVis RegionService::calcAverages(const MatSet& matSet, QLPs regions) {
    QVis averages;
    for(QLP region : regions) {
        averages.push_back(calcAverage(matSet, region));
    }
    return averages;
}

QVi RegionService::calcAverage(Mat srcBGRImg, QLP region) {
    MatSet matSet(srcBGRImg);
	return calcAverage(matSet, region);
}

QVi RegionService::calcAverage(const MatSet& matSet, QLP region) {
    QVi averages(9,0);
   
    if(!region.size()) {
        qDebug() << "region.count()=0";
        return averages;
    }

    QVi sumOfValue = countSum(matSet, region);

    for(int i=0; i<9; i++) {
        averages[i] = sumOfValue[i] / region.count();
    }

    return averages;
}

/**
* BGR, HSV, YCrCbの9チャンネルの指定領域のピクセル値の合計を求める
*
*/
QVi RegionService::countSum(Mat srcBGRImg, Mat refImg, Scalar refColor) {
	
    QLP region = toPointList(refImg, refColor);
	  return countSum(srcBGRImg, region);
}

QVi RegionService::countSum(Mat srcBGRImg, QLP region) {
    MatSet matSet(srcBGRImg);
	return countSum(matSet, region);
}


QVi RegionService::countSum(const MatSet& matSet, QLP region) {
  
     QVi sumOfValue(9,0);

    for(Point point : region) {

      sumOfValue[0] = sumOfValue[0] + B(matSet.bgr(), point.x, point.y);
      sumOfValue[1] = sumOfValue[1] + G(matSet.bgr(), point.x, point.y);
      sumOfValue[2] = sumOfValue[2] + R(matSet.bgr(), point.x, point.y);
      sumOfValue[3] = sumOfValue[3] + B(matSet.hsv(), point.x, point.y);
      sumOfValue[4] = sumOfValue[4] + G(matSet.hsv(), point.x, point.y);
      sumOfValue[5] = sumOfValue[5] + R(matSet.hsv(), point.x, point.y);
      sumOfValue[6] = sumOfValue[6] + B(matSet.ycrcb(), point.x, point.y);
      sumOfValue[7] = sumOfValue[7] + G(matSet.ycrcb(), point.x, point.y);
      sumOfValue[8] = sumOfValue[8] + R(matSet.ycrcb(), point.x, point.y);

    }

    return sumOfValue;
}


/**
* 指定領域の9チャンネルのToleranceを返す
*
*/

QVis RegionService::calcTolerances(const MatSet& matSet, QLPs regions, QVis averages) {
    QVis tolerances;
    for(int i=0; i<regions.size(); i++) {
        tolerances.push_back(calcTolerance(matSet, regions[i], averages[i]));
    }
    return tolerances;
}

QVi RegionService::calcTolerance(const MatSet& matSet, QLP region, QVi averages) {

    QVis histograms = createHistogram(matSet, region);
    QVi tolerance(9,0);
    for(int i=0; i<9; i++) {
      tolerance[i] = findTolerance(averages[i], histograms[i], region.size());
    }
    
    return tolerance;
}

int RegionService::findTolerance(int average, QVi histogram, int pixcelNum) {
    int sum =0;
    bool maxFlag = false;
    bool minFlag = false;
    int result =0;
    for(result=0; sum < pixcelNum*0.8; result++) {
        if((average+result) > 255) {
            return 255 - average;
        } else if((average-result) < 0) {
            return average;
        } else {
            sum = sum + histogram[average+result] + histogram[average-result];
        }
        
    }
    return result;
}

/**
* 指定領域の9チャンネルのHistogramを作成して返す
*
*/
QVis RegionService::createHistogram(Mat srcBGRImg, QLP region) {
  
    MatSet matSet(srcBGRImg);
    return createHistogram(matSet, region);
}

QVis RegionService::createHistogram(const MatSet& matSet, QLP region) {
  
  QVis histograms(9);

  for(int i=0; i<9; i++) {
    int BITE = 256;
	QVi channelHistogram(matSet.bgr().elemSize1()*BITE, 0);
    histograms[i] = channelHistogram;
  }

    for(Point point : region) {
        histograms.value(0)[B(matSet.bgr(), point.x, point.y)]++;
        histograms.value(1)[G(matSet.bgr(), point.x, point.y)]++;
        histograms.value(2)[R(matSet.bgr(), point.x, point.y)]++;
        histograms.value(3)[B(matSet.hsv(), point.x, point.y)]++;
        histograms.value(4)[G(matSet.hsv(), point.x, point.y)]++;
        histograms.value(5)[R(matSet.hsv(), point.x, point.y)]++;
        histograms.value(6)[B(matSet.ycrcb(), point.x, point.y)]++;
        histograms.value(7)[G(matSet.ycrcb(), point.x, point.y)]++;
        histograms.value(8)[R(matSet.ycrcb(), point.x, point.y)]++;
    }
  

  return histograms;
}
