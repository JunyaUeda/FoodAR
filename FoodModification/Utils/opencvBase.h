#ifndef OPENCVBASE_H
#define OPENCVBASE_H
#include "opencv2/opencv.hpp"

#define CV_VER CVAUX_STR(CV_MAJOR_VERSION) CVAUX_STR(CV_MINOR_VERSION) CVAUX_STR(CV_SUBMINOR_VERSION)

#ifdef _DEBUG
#define CV_EXT "d.lib"
#else
#define CV_EXT ".lib"
#endif

#pragma comment(lib, "opencv_calib3d" CV_VER CV_EXT)
#pragma comment(lib, "opencv_contrib" CV_VER CV_EXT)
#pragma comment(lib, "opencv_core" CV_VER CV_EXT)
#pragma comment(lib, "opencv_features2d" CV_VER CV_EXT)
#pragma comment(lib, "opencv_flann" CV_VER CV_EXT)
#pragma comment(lib, "opencv_gpu" CV_VER CV_EXT)
#pragma comment(lib, "opencv_highgui" CV_VER CV_EXT)
#pragma comment(lib, "opencv_imgproc" CV_VER CV_EXT)
#pragma comment(lib, "opencv_legacy" CV_VER CV_EXT)
#pragma comment(lib, "opencv_ml" CV_VER CV_EXT)
#pragma comment(lib, "opencv_nonfree" CV_VER CV_EXT)
#pragma comment(lib, "opencv_objdetect" CV_VER CV_EXT)
#pragma comment(lib, "opencv_ocl" CV_VER CV_EXT)
#pragma comment(lib, "opencv_photo" CV_VER CV_EXT)
#pragma comment(lib, "opencv_stitching" CV_VER CV_EXT)
#pragma comment(lib, "opencv_superres" CV_VER CV_EXT)
#pragma comment(lib, "opencv_ts" CV_VER CV_EXT)
#pragma comment(lib, "opencv_video" CV_VER CV_EXT)
#pragma comment(lib, "opencv_videostab" CV_VER CV_EXT)


#define B(IMG, X,Y) ((IMG).data[((IMG).step*(Y) + (IMG).channels()*(X)) + 0])
#define G(IMG, X,Y) ((IMG).data[((IMG).step*(Y) + (IMG).channels()*(X)) + 1])
#define R(IMG, X,Y) ((IMG).data[((IMG).step*(Y) + (IMG).channels()*(X)) + 2])
#define I(IMG, X,Y) ((IMG).data[((IMG).step*(Y) + (IMG).channels()*(X)) + 3])

#define H(IMG, X,Y) ((IMG).data[((IMG).step*(Y) + (IMG).channels()*(X)) + 0])
#define S(IMG, X,Y) ((IMG).data[((IMG).step*(Y) + (IMG).channels()*(X)) + 1])
#define V(IMG, X,Y) ((IMG).data[((IMG).step*(Y) + (IMG).channels()*(X)) + 2])

#define L(IMG, X,Y) ((IMG).data[(IMG).step*(Y) + (X)])

#define BLUE(IMG,Y) ((IMG).data[(IMG).step*(Y) + (IMG).channels() + 0])
#define GREEN(IMG,Y) ((IMG).data[(IMG).step*(Y) + (IMG).channels() + 1])
#define RED(IMG,Y) ((IMG).data[(IMG).step*(Y) + (IMG).channels() + 2])
#define X(IMG,Y) ((IMG).data[(IMG).step*(Y) + (IMG).channels() + 3])
#define Y(IMG,Y) ((IMG).data[(IMG).step*(Y) + (IMG).channels() + 4])

using namespace cv;
using namespace std;

class OpenCVBase {
	
public:
    OpenCVBase();
};

#endif // OPENCVBASE_H
