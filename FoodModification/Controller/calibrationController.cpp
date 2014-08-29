#include "calibrationController.h"
#include <stdio.h>
#define RATIO_OF_REGION 0.95

#define DIFF(IMG,INDEX,X,Y) ((IMG).data[( (IMG).size[1]*(IMG).size[2]*(IMG).channels()*(INDEX) + (IMG).size[2]*(IMG).channels()*(Y) + (IMG).channels()*(X)) + 0])
#define HIGH_OR_LOW(IMG,INDEX,X,Y) ((IMG).data[( (IMG).size[1]*(IMG).size[2]*(IMG).channels()*(INDEX) + (IMG).size[2]*(IMG).channels()*(Y) + (IMG).channels()*(X)) + 1])

CalibrationController::CalibrationController(ExtractParamManager* extractParamManager)
{
	this->clickParam = new CalibrateClickParam;
	this->extractParamManager = extractParamManager;
}


void mouseCallback(int event, int x, int y, int flags, void* param) {
	CalibrateClickParam *clickParam = static_cast<CalibrateClickParam*>(param);

    switch(event) {
    case cv::EVENT_LBUTTONDOWN:
        clickParam->leftClickedCounts++;
        clickParam->clickedPoints[0][clickParam->leftClickedCounts-1] = cv::Point(x,y);
        cv::fillConvexPoly(clickParam->img, clickParam->clickedPoints[0], clickParam->leftClickedCounts, cv::Scalar(0,0,255));
    	break;
    case cv::EVENT_RBUTTONDOWN:
    	clickParam->rightClickedCounts++;
        clickParam->clickedPoints[1][clickParam->rightClickedCounts-1] = cv::Point(x,y);
        cv::fillConvexPoly(clickParam->img, clickParam->clickedPoints[1], clickParam->rightClickedCounts, cv::Scalar(0,255,0));
    break;
    }
}

void CalibrationController::calibrate() {

	cv::VideoCapture videoCapture = cv::VideoCapture(0);
    cv::Mat srcImg;
    std::string windowName = "calibration";

    while(inputFlag) {
        videoCapture >> srcImg;
        cv::imshow(windowName, srcImg);
        char ch = cv::waitKey(33);
        if ( ch == 27 ) break;
    }

    this->clickParam->img = srcImg.clone();
    cv::setMouseCallback(windowName, mouseCallback, (void*)this->clickParam);
    while(drawingFlag) {
    	cv::imshow(windowName, this->clickParam->img);
    	char ch = cv::waitKey(33);
        if ( ch == 27 ) break;
    }
    cv::destroyWindow(windowName);

    setExtractBGRParam(srcImg, this->clickParam->img, cv::Scalar(0,0,255), 0);
    setExtractBGRParam(srcImg, this->clickParam->img, cv::Scalar(0,255,0), 1);

    qDebug() << "average =" << this->extractParamManager->criterion->getBlue();
    qDebug() << "average =" << this->extractParamManager->criterion->getGreen();
    qDebug() << "average =" << this->extractParamManager->criterion->getRed();
    qDebug() << "setHueTolerance" << this->extractParamManager->colorExtractTolerance->getBlueHighTolerance();
    qDebug() << "setHueTolerance" << this->extractParamManager->colorExtractTolerance->getGreenLowTolerance();
    qDebug() << "setHueTolerance" << this->extractParamManager->colorExtractTolerance->getRedLowTolerance();

    const int sizes[] = {3, srcImg.size().width, srcImg.size().height};
    cv::Mat m1(3, sizes, CV_8UC(2));

    DIFF(m1,0,5,5) = 123;
    HIGH_OR_LOW(m1,0,5,5)=1;
    qDebug() <<  "dims:" << m1.dims;
    qDebug() << DIFF(m1,0,5,5);
    qDebug() << HIGH_OR_LOW(m1,0,5,5);
    
}

void CalibrationController::videoInput() {
	this->calibrate();
}

void CalibrationController::capture() {
	this->inputFlag = false;
}

void CalibrationController::stopDrawing() {
	this->drawingFlag = false;
}

int CalibrationController::calculateAverages(cv::Mat srcImg, cv::Mat refImg, int* result, cv::Scalar color) {
	int samplingPixcelNum = 0;
    int *sumOfValue = new int[srcImg.channels()];
    for(int i=0; i<srcImg.channels(); i++) {
    	sumOfValue[i] = 0;
    }
	for(int y=0; y<refImg.rows; y++ ) {
		for(int x=0; x<refImg.cols; x++) {
			cv::Scalar refImgColor(B(refImg,x,y),G(refImg,x,y),R(refImg,x,y));
			if(refImgColor == color) {
                samplingPixcelNum++;
				sumOfValue[0] = sumOfValue[0] + B(srcImg,x,y);
				sumOfValue[1] = sumOfValue[1] + G(srcImg,x,y);
				sumOfValue[2] = sumOfValue[2] + R(srcImg,x,y);
			} 
		}
	}

	for(int i=0; i<srcImg.channels(); i++) {
		result[i] = (int) sumOfValue[i]/samplingPixcelNum;
	}
	
	delete[] sumOfValue;

	return samplingPixcelNum;
}

void CalibrationController::setHistogramArray(cv::Mat srcImg, cv::Mat refImg, int colorIndex, int* histogram, int histogramSize, cv::Scalar color) {
	int BITE = 256;
	if(histogramSize != srcImg.elemSize1()*BITE) {
		qWarning() << "histogramSize is inappropriate.";
	}
	for(int y=0; y<srcImg.rows; y++) {
		for(int x=0; x<srcImg.cols; x++) {
			cv::Scalar refImgColor(B(refImg,x,y),G(refImg,x,y),R(refImg,x,y));
			if(refImgColor == color) {
				switch(colorIndex) {
					case 0:
						histogram[B(srcImg,x,y)]++;
						break;
					case 1:
						histogram[G(srcImg,x,y)]++;
						break;
					case 2:
						histogram[R(srcImg,x,y)]++;
						break;
					case 3:
						histogram[I(srcImg,x,y)]++;
						break;
					default:
						break;
				}					
			}
		}
	}
}

void CalibrationController::calculateTolerance(int* tolerance, int average, int pixcelNum, int* histogram) { 
	int sum =0;
	bool maxFlag = false;
	bool minFlag = false;
    int result =0;
	for(result=0; sum < pixcelNum*RATIO_OF_REGION; result++) {
        if((average+result) <= 255 && (average+result) >=0 ) {
			sum = sum + histogram[average+result];
		} else {
			maxFlag = true;
		}

        if((average-result) <=255 &&(average-result) >= 0) {
			sum = sum + histogram[average-result];
		} else {
			minFlag = true;
		}
	}

	if(maxFlag) {
		tolerance[0] = 255-average;
	} else {
		tolerance[0] = result-1;
	}

	if(minFlag) {
		tolerance[1] = average;
	} else {
		tolerance[1] = result-1;
	}
}

int CalibrationController::setTolerance(cv::Mat srcImg, cv::Mat refImg,int* average,int pixcelNum,int colorIndex, int* tolerance, cv::Scalar color) {
	if(colorIndex<0 || colorIndex >2) {
        qWarning() << "ColorIndex is not inappropriate.";
		return -1;
	}

	int BITE = 256;
    int BINS = srcImg.elemSize1()*BITE;
    int* histogram = new int[BINS];
    for(int i=0; i<BINS; i++) {
        histogram[i] = 0;
    }
	setHistogramArray(srcImg, refImg, colorIndex, histogram, BINS, color);
    calculateTolerance(tolerance, average[colorIndex], pixcelNum, histogram);

	delete[] histogram;

	return 0;
}

cv::Mat CalibrationController::getDistribution(cv::Mat srcImg, cv::Mat refImg, int pixcelNum, cv::Scalar color){
	cv::Mat m1(pixcelNum,1, CV_64FC(5));
	int rows=0;
	for(int y=0; y<srcImg.rows; y++) {
		for(int x=0; x<srcImg.cols; x++) {
			cv::Scalar refImgColor(B(refImg,x,y),G(refImg,x,y),R(refImg,x,y));
            if(refImgColor == color) {
				BLUE(m1,rows)=B(srcImg,x,y);
				GREEN(m1,rows)=G(srcImg,x,y);
				RED(m1,rows)=R(srcImg,x,y);
				X(m1,rows)=x;
				Y(m1,rows)=y;
				rows++;
			}
		}
	}

	return m1;
}

void CalibrationController::setExtractBGRParam(cv::Mat srcImg, cv::Mat refImg, cv::Scalar color, int paramIndex) {

	int average[3] = {0};
    int blueTolerance[2] = {0}, greenTolerance[2] = {0}, redTolerance[2] = {0};
    int BLUE = 0, GREEN = 1, RED = 2;

	int pixcelNum = calculateAverages(srcImg, refImg, average, color);
    setTolerance(srcImg, refImg, average, pixcelNum, BLUE, blueTolerance, color);
    setTolerance(srcImg, refImg, average, pixcelNum, GREEN, greenTolerance, color);
    setTolerance(srcImg, refImg, average, pixcelNum, RED, redTolerance, color);

    ColorCriterion* criterion = this->extractParamManager->criterion+paramIndex;
    ColorExtractTolerance* tolerace = this->extractParamManager->colorExtractTolerance+paramIndex;

    criterion->setBlue(average[0]);
    criterion->setGreen(average[1]);
    criterion->setRed(average[2]);
    this->extractParamManager->referenceMat = getDistribution(srcImg, refImg, pixcelNum,color);
    tolerace->setBlueHighTolerance(blueTolerance[0]);
    tolerace->setBlueLowTolerance(blueTolerance[1]);
    tolerace->setGreenHighTolerance(greenTolerance[0]);
    tolerace->setGreenLowTolerance(greenTolerance[1]);
    tolerace->setRedHighTolerance(redTolerance[0]);
    tolerace->setRedLowTolerance(redTolerance[1]);

    qDebug() << "pixcelNum =" << pixcelNum;
}
