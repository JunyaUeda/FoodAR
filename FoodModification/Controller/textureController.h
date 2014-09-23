#ifndef TEXTURECONTROLLER_H
#define TEXTURECONTROLLER_H
#include "../Utils/opencvBase.h"

class TextureController {

public:

private:
	vector<vector<Point>> contours;
	vector<Size> rectSizes;
	
public:
    TextureController();
    Mat createTexture(vector<vector<Point>>& contours, Mat maskImg, vector<Rect>& rects);
};

#endif // TEXTURECONTROLLER_H
