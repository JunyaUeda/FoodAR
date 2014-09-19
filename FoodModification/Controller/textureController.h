#ifndef TEXTURECONTROLLER_H
#define TEXTURECONTROLLER_H
#include "../Utils/opencvBase.h"

class TextureController {

public:

private:
	std::vector<std::vector<cv::Point>> contours;
	std::vector<cv::Size> rectSizes;
public:
    TextureController();
    cv::Mat createTexture(std::vector<std::vector<cv::Point>>& contours, cv::Mat maskImg);
};

#endif // TEXTURECONTROLLER_H
