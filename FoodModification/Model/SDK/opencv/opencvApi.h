#ifndef OPENCVAPI_H
#define OPENCVAPI_H

#include "opencv2/opencv.hpp"

//#define CV_VER CVAUX_STR(CV_MAJOR_VERSION) CVAUX_STR(CV_MINOR_VERSION) CVAUX_STR(CV_SUBMINOR_VERSION)

//#ifdef _DEBUG
//#define CV_EXT "d.lib"
//#else
//#define CV_EXT ".lib"
//#endif

//#pragma comment(lib, "opencv_calib3d" CV_VER CV_EXT)
//#pragma comment(lib, "opencv_contrib" CV_VER CV_EXT)
//#pragma comment(lib, "opencv_core" CV_VER CV_EXT)
//#pragma comment(lib, "opencv_features2d" CV_VER CV_EXT)
//#pragma comment(lib, "opencv_flann" CV_VER CV_EXT)
//#pragma comment(lib, "opencv_gpu" CV_VER CV_EXT)
//#pragma comment(lib, "opencv_highgui" CV_VER CV_EXT)
//#pragma comment(lib, "opencv_imgproc" CV_VER CV_EXT)
//#pragma comment(lib, "opencv_legacy" CV_VER CV_EXT)
//#pragma comment(lib, "opencv_ml" CV_VER CV_EXT)
//#pragma comment(lib, "opencv_nonfree" CV_VER CV_EXT)
//#pragma comment(lib, "opencv_objdetect" CV_VER CV_EXT)
//#pragma comment(lib, "opencv_ocl" CV_VER CV_EXT)
//#pragma comment(lib, "opencv_photo" CV_VER CV_EXT)
//#pragma comment(lib, "opencv_stitching" CV_VER CV_EXT)
//#pragma comment(lib, "opencv_superres" CV_VER CV_EXT)
//#pragma comment(lib, "opencv_ts" CV_VER CV_EXT)
//#pragma comment(lib, "opencv_video" CV_VER CV_EXT)
//#pragma comment(lib, "opencv_videostab" CV_VER CV_EXT)

//#ifdef _DEBUG
//#pragma comment(lib, "opencv_calib3d.2.4.9.dylib")
//#pragma comment(lib, "opencv_contrib.2.4.9.dylib")
//#pragma comment(lib, "opencv_core.2.4.9.dylib")
//#pragma comment(lib, "opencv_features2d.2.4.9.dylib")
//#pragma comment(lib, "opencv_flann.2.4.9.dylib")
//#pragma comment(lib, "opencv_gpu.2.4.9.dylib")
//#pragma comment(lib, "opencv_highgui.2.4.9.dylib")
//#pragma comment(lib, "opencv_imgproc.2.4.9.dylib")
//#pragma comment(lib, "opencv_legacy.2.4.9.dylib")
//#pragma comment(lib, "opencv_ml.2.4.9.dylib")
//#pragma comment(lib, "opencv_nonfree.2.4.9.dylib")
//#pragma comment(lib, "opencv_objdetect.2.4.9.dylib")
//#pragma comment(lib, "opencv_ocl.2.4.9.dylib")
//#pragma comment(lib, "opencv_photo.2.4.9.dylib")
//#pragma comment(lib, "opencv_stitching.2.4.9.dylib")
//#pragma comment(lib, "opencv_superres.2.4.9.dylib")
//#pragma comment(lib, "opencv_ts.2.4.9.dylib")
//#pragma comment(lib, "opencv_video.2.4.9.dylib")
//#pragma comment(lib, "opencv_videostab.2.4.9.dylib")
//#else
//#define CV_EXT ".lib"
//#endif




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

class OpenCVAPI
{
public:
    OpenCVAPI();
};

#endif // OPENCVAPI_H
