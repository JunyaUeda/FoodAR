#ifndef OPENCVBASE_H
#define OPENCVBASE_H
#include "opencv2\opencv.hpp"

//#ifdef _DEBUG
//    //Debug mode
//    #pragma comment(lib,"C:\\opencv\\build\\x86\\vc10\\lib\\opencv_core241d.lib")
//    #pragma comment(lib,"C:\\opencv\\build\\x86\\vc10\\lib\\opencv_imgproc241d.lib")
//    #pragma comment(lib,"C:\\opencv\\build\\x86\\vc10\\lib\\opencv_highgui241d.lib")
//    #pragma comment(lib,"C:\\opencv\\build\\x86\\vc10\\lib\\opencv_objdetect241d.lib")
//    #pragma comment(lib,"C:\\opencv\\build\\x86\\vc10\\lib\\opencv_contrib241d.lib")
//    #pragma comment(lib,"C:\\opencv\\build\\x86\\vc10\\lib\\opencv_features2d241d.lib")
//    #pragma comment(lib,"C:\\opencv\\build\\x86\\vc10\\lib\\opencv_flann241d.lib")
//    #pragma comment(lib,"C:\\opencv\\build\\x86\\vc10\\lib\\opencv_gpu241d.lib")
//   // #pragma comment(lib,"C:\\opencv\\build\\x86\\vc10\\lib\\opencv_haartraining_engined.lib")
//    #pragma comment(lib,"C:\\opencv\\build\\x86\\vc10\\lib\\opencv_legacy241d.lib")
//    #pragma comment(lib,"C:\\opencv\\build\\x86\\vc10\\lib\\opencv_ts241d.lib")
//    #pragma comment(lib,"C:\\opencv\\build\\x86\\vc10\\lib\\opencv_video241d.lib")
//    #pragma comment(lib,"C:\\opencv\\build\\x86\\vc10\\lib\\opencv_nonfree241d.lib")

//#else
//    //Release mode
//    #pragma comment(lib,"C:\\opencv\\build\\x86\\vc10\\lib\\opencv_core241.lib")
//    #pragma comment(lib,"C:\\opencv\\build\\x86\\vc10\\lib\\opencv_imgproc241.lib")
//    #pragma comment(lib,"C:\\opencv\\build\\x86\\vc10\\lib\\opencv_highgui241.lib")
//    #pragma comment(lib,"C:\\opencv\\build\\x86\\vc10\\lib\\opencv_objdetect241.lib")
//    #pragma comment(lib,"C:\\opencv\\build\\x86\\vc10\\lib\\opencv_contrib241.lib")
//    #pragma comment(lib,"C:\\opencv\\build\\x86\\vc10\\lib\\opencv_features2d241.lib")
//    #pragma comment(lib,"C:\\opencv\\build\\x86\\vc10\\lib\\opencv_flann241.lib")
//    #pragma comment(lib,"C:\\opencv\\build\\x86\\vc10\\lib\\opencv_gpu241.lib")
//   // #pragma comment(lib,"C:\\opencv\\build\\x86\\vc10\\lib\\opencv_haartraining_engined.lib")
//    #pragma comment(lib,"C:\\opencv\\build\\x86\\vc10\\lib\\opencv_legacy241.lib")
//    #pragma comment(lib,"C:\\opencv\\build\\x86\\vc10\\lib\\opencv_ts241.lib")
//    #pragma comment(lib,"C:\\opencv\\build\\x86\\vc10\\lib\\opencv_video241.lib")
//    #pragma comment(lib,"C:\\opencv\\build\\x86\\vc10\\lib\\opencv_nonfree241.lib")
//#endif

#define B(IMG, X,Y) ((IMG).data[((IMG).step*(Y) + (IMG).channels()*(X)) + 0])
#define G(IMG, X,Y) ((IMG).data[((IMG).step*(Y) + (IMG).channels()*(X)) + 1])
#define R(IMG, X,Y) ((IMG).data[((IMG).step*(Y) + (IMG).channels()*(X)) + 2])
#define I(IMG, X,Y) ((IMG).data[((IMG).step*(Y) + (IMG).channels()*(X))])
class OpenCVBase
{
public:
    OpenCVBase();
};

#endif // OPENCVBASE_H
