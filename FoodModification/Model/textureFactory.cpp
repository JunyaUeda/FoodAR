#include "textureFactory.h"

TextureFactory::TextureFactory() {

}

TextureFactory& TextureFactory::getInstance() {
    static TextureFactory instance;
    return instance;
}

void TextureFactory::create(Mat& aTexture) {
    Region region = _regionManager.currentRegion();
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
    
    // if(region.rotatedRect().size.width > region.rotatedRect().size.height) {
    //     Point2f src_pt[] = { Point2f(0, 0), Point2f(0, _resizedSrc.size().height), Point2f(_resizedSrc.size().width, _resizedSrc.size().height) };
    //     Point2f dst_pt[] = { Point2f(vertices[0].x, vertices[0].y+3), Point2f(vertices[1].x, vertices[1].y), Point2f(vertices[2].x+10, vertices[2].y-3) };
    //     Mat affine_matrix = getAffineTransform(src_pt, dst_pt);
    //     warpAffine(_resizedSrc, aTexture, affine_matrix, aTexture.size() , INTER_LINEAR, BORDER_CONSTANT, Scalar::all(0) );
    // } else {
    //     Point2f src_pt[] = { Point2f(0, 0), Point2f(0, _resizedSrc.size().height), Point2f(_resizedSrc.size().width, _resizedSrc.size().height) };
    //     Point2f dst_pt[] = { Point2f(vertices[1].x, vertices[1].y+3), Point2f(vertices[2].x, vertices[2].y), Point2f(vertices[3].x+10, vertices[3].y-3) };
    //     Mat affine_matrix = getAffineTransform(src_pt, dst_pt);
    //     warpAffine(_resizedSrc, aTexture, affine_matrix, aTexture.size() , INTER_LINEAR, BORDER_CONSTANT, Scalar::all(0) );
    // }

    if(region.rotatedRect().size.width > region.rotatedRect().size.height) {
        Point2f src_pt[] = { Point2f(0, 0), Point2f(0, _resizedSrc.size().height), Point2f(_resizedSrc.size().width, _resizedSrc.size().height) };
        Point2f dst_pt[] = { vertices[0], vertices[1], vertices[2] };
        Mat affine_matrix = getAffineTransform(src_pt, dst_pt);
        warpAffine(_resizedSrc, aTexture, affine_matrix, aTexture.size() , INTER_LINEAR, BORDER_CONSTANT, Scalar::all(0) );
    } else {
        Point2f src_pt[] = { Point2f(0, 0), Point2f(0, _resizedSrc.size().height), Point2f(_resizedSrc.size().width, _resizedSrc.size().height) };
        Point2f dst_pt[] = { vertices[1], vertices[2], vertices[3] };
        Mat affine_matrix = getAffineTransform(src_pt, dst_pt);
        warpAffine(_resizedSrc, aTexture, affine_matrix, aTexture.size() , INTER_LINEAR, BORDER_CONSTANT, Scalar::all(0) );
    }
    


    // circle(aTexture, region.rotatedRects()[i].center, 10, cv::Scalar(0,200,0), 8, 8);
    // rectangle(aTexture, rect.tl(), rect.br(), Scalar(255,0,255), 2);
    //for (int i = 0; i < 4; i++) line(aTexture, vertices[i], vertices[(i+1)%4], Scalar(0,255,0), 4, 8, 0);
    imshow("texture", aTexture);
        
}

void TextureFactory::updateSrc(Mat src) {
    _src = src;
}
