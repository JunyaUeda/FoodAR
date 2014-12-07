#include "textureFactory.h"

TextureFactory::TextureFactory() {

}

TextureFactory& TextureFactory::getInstance() {
    static TextureFactory instance;
    return instance;
}

void TextureFactory::create(const Region& region, Mat& aTexture) {
            
    if(region.contour().empty()) {
        qDebug() << "contours is empty in textureController";
        return;
    }

  
    resize(_src, _resizedSrc, region.rotatedRect().size, 0, 0, INTER_NEAREST);
    Point2f vertices[4];
    region.rotatedRect().points(vertices);
    
    // double scale = 1.0;
    // Mat affine_matrix = getRotationMatrix2D(region.rotatedRects()[i].center, region.rotatedRects()[i].angle, scale);
    // warpAffine(_src, aTexture, affine_matrix, aTexture.size() , INTER_LINEAR, BORDER_CONSTANT, Scalar::all(0) );
    
    if(region.rotatedRect().size.width > region.rotatedRect().size.height) {
        qDebug() << "012 width";
        qDebug() << "vertices[0]" << "x" << vertices[0].x << "    y" << vertices[0].y;
        qDebug() << "vertices[1]" << "x" << vertices[1].x << "    y" << vertices[1].y;
        qDebug() << "vertices[2]" << "x" << vertices[2].x << "    y" << vertices[2].y;
        Point2f src_pt[] = { Point2f(0, 0), Point2f(0, _resizedSrc.size().height), Point2f(_resizedSrc.size().width, _resizedSrc.size().height) };
        Point2f dst_pt[] = { vertices[0], vertices[1], vertices[2] };
        Mat affine_matrix = getAffineTransform(src_pt, dst_pt);
        warpAffine(_resizedSrc, aTexture, affine_matrix, aTexture.size() , INTER_LINEAR, BORDER_CONSTANT, Scalar::all(0) );
    } else {
        qDebug() << "301 height";
        qDebug() << "vertices[0]" << "x" << vertices[0].x << "    y" << vertices[0].y;
        qDebug() << "vertices[1]" << "x" << vertices[1].x << "    y" << vertices[1].y;
        qDebug() << "vertices[2]" << "x" << vertices[2].x << "    y" << vertices[2].y;
        Point2f src_pt[] = { Point2f(0, 0), Point2f(0, _resizedSrc.size().height), Point2f(_resizedSrc.size().width, _resizedSrc.size().height) };
        Point2f dst_pt[] = { vertices[1], vertices[2], vertices[3] };
        Mat affine_matrix = getAffineTransform(src_pt, dst_pt);
        warpAffine(_resizedSrc, aTexture, affine_matrix, aTexture.size() , INTER_LINEAR, BORDER_CONSTANT, Scalar::all(0) );
    }
    


    // circle(aTexture, region.rotatedRects()[i].center, 10, cv::Scalar(0,200,0), 8, 8);
    // rectangle(aTexture, rect.tl(), rect.br(), Scalar(255,0,255), 2);
    // for (int i = 0; i < 4; i++) line(aTexture, vertices[i], vertices[(i+1)%4], Scalar(0,255,0), 4, 8, 0);
        
}

void TextureFactory::updateSrc(Mat src) {
    _src = src;
}
