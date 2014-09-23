#include "textureController.h"
#include <QDebug>
#define IMG_SRC "../FoodModification/Images/toro.jpg"

TextureController::TextureController() {

}

Mat TextureController::createTexture(vector<vector<Point>>& contours, Mat maskImg, vector<Rect>& rects) {
	
	Mat allTextureImg = Mat::zeros(maskImg.size(), CV_8UC3);
	Mat srcImg = imread(IMG_SRC, 1);
	if(srcImg.empty()) {
		qDebug() << "srcImg is empty";
		return allTextureImg;
	}
	if(contours.empty()) {
		qDebug() << "contours is empty in textureController";
		return allTextureImg;
	}
	
	for(int i=0; i<contours.size(); i++) {

		size_t count = contours[i].size();
        if(count < 300) {
            continue;
        }
        Mat textureImg = Mat::zeros(maskImg.size(), CV_8UC3);
		RotatedRect rotatedRect = minAreaRect(contours[i]);
		
		Rect rect = rotatedRect.boundingRect();
		rects.push_back(rect);
		resize(srcImg, srcImg, rotatedRect.size, 0, 0, INTER_NEAREST);
		Point2f vertices[4];
		rotatedRect.points(vertices);
		
		// double scale = 1.0;
		// Mat affine_matrix = getRotationMatrix2D(rotatedRect.center, rotatedRect.angle, scale);
		// warpAffine(srcImg, textureImg, affine_matrix, textureImg.size() , INTER_LINEAR, BORDER_CONSTANT, Scalar::all(0) );

		Point2f src_pt[] = { Point2f(0, 0), Point2f(0, srcImg.size().height), Point2f(srcImg.size().width, srcImg.size().height) };
  		Point2f dst_pt[] = { vertices[0], vertices[1], vertices[2] };
  		Mat affine_matrix = getAffineTransform(src_pt, dst_pt);
		warpAffine(srcImg, textureImg, affine_matrix, textureImg.size() , INTER_LINEAR, BORDER_CONSTANT, Scalar::all(0) );

		circle(textureImg, rotatedRect.center, 10, cv::Scalar(0,200,0), 8, 8);
		rectangle(textureImg, rect.tl(), rect.br(), Scalar(255,0,255), 2);
		for (int i = 0; i < 4; i++) line(textureImg, vertices[i], vertices[(i+1)%4], Scalar(0,255,0), 4, 8, 0);
 		
 		add(allTextureImg, textureImg, allTextureImg);
	}
	
	
	return allTextureImg;

}

