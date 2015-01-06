#include "window.h"

Window::Window(QString name, Size size) {
    _name = name.toLocal8Bit().data();
    _size = size;
    create();
}

void Window::create() {
    namedWindow(_name, CV_WINDOW_NORMAL);
    resizeWindow(_name, _size.width, _size.height);
}
void Window::show(Mat img) {
    imshow(_name, img);
}

Size Window::size() const {
    return _size;
}

void Window::reSize(const Size& size) {
    _size = size;
}

std::string Window::name() const {
    return _name;
}
    
void Window::changeName(const QString& name) {
    destroyWindow(_name);
    _name = name.toLocal8Bit().data();
    create();
}

void onMouse(int event, int x, int y, int flags, void* param) {
 
	Mat* img = (Mat*) param;
    switch(event) {
        case cv::EVENT_LBUTTONDOWN:
			qDebug() << " Ch0 =" << B((*img), x,y);
			qDebug() << " Ch1 =" << G((*img), x,y);
			qDebug() << " Ch2 =" << R((*img), x,y);
        break;
        case cv::EVENT_RBUTTONDOWN:
        
        break;
    }

}

void Window::setMouseFunction(Mat img) {
	setMouseCallback(_name, onMouse, &img);
}
