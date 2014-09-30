#ifndef TEXTURECONTROLLER_H
#define TEXTURECONTROLLER_H
#include "../Utils/opencvBase.h"

class TextureController {

public:
	static TextureController& getInstance();
    Mat createTexture(vector<vector<Point>>& contours, Mat maskImg, vector<Rect>& rects, String picturePath);
    void setROI(vector<vector<Point>>& contours, vector<Rect>& rects);
private:
	TextureController();
	TextureController(const TextureController&);
	vector<vector<Point>> contours;
	vector<Size> rectSizes;
	

};

#endif // TEXTURECONTROLLER_H
