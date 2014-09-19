#include "textureController.h"
#include <QDebug>

TextureController::TextureController()
{
}

cv::Mat TextureController::createTexture(std::vector<std::vector<cv::Point>>& contours, cv::Mat maskImg) {
	
	cv::Mat textureImg = cv::Mat::zeros(maskImg.size(), CV_8UC3);

	if(contours.size() > 0) {
		for(int i=0; i<contours.size(); i++) {

			cv::RotatedRect rotatedRect = cv::minAreaRect(contours[i]);
			
			if(ratatedRect.size.width < rotatedRect.size.height) {
				rectSizes.push_back(cv::Size(rotatedRect.size.height, ratatedRect.size.width) );
			} else {
				rectSizes.push_back(cv::Size(rotatedRect.size.width, ratatedRect.size.height) );
			}
		}
	} else {
		qDebug() << "contours < = 0";
	}

	

	return textureImg;

}