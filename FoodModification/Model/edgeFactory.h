#ifndef EDGEFACTORY_H
#define EDGEFACTORY_H

#include "./Param/edge.h"
#include "typeDef.h"
#include "./Param/edgeThreshold.h"
#include "./Param/channelSet.h"
#include "./Manager/edgeManager.h"

class EdgeFactory {

/*method*/
public:
    static EdgeFactory& getInstance();
    void createEdges(const MatSet& matSet, vector<Mat>& resultRawEdgeImgs);
    void createEdges(vector<Mat>& resultRawEdgeImgs, map<ChannelType, Mat>& channelMats);
    void createEdges(ChannelSet& channelSet, const Rect& roi);
    void updateEngagedChannels(vector<ChannelType> newList);
private:
    EdgeFactory();
    EdgeFactory(const EdgeFactory&);

    void revMergeEdges(vector<Mat>& channelEdgeImgs, const Rect& roi, Mat& dstEdgeImg) {

        if(!channelEdgeImgs.size()) {
            return;  
        }

        for(int y=roi.y; y<(roi.y+roi.height); y++) {
            for(int x=roi.x; x<(roi.x+roi.width); x++) {
                for(Mat mat : channelEdgeImgs) {
                    if(L(mat,x,y) == 255) {
                        L(dstEdgeImg, x, y) = 0;
                        break;
                    } 
                    L(dstEdgeImg, x, y) = 255;
                }
            }
        }
        erode(dstEdgeImg, dstEdgeImg, cv::Mat(), Point(-1,-1), 1);
    }

    void revMergeEdges(vector<Mat>& channelEdgeImgs, Rect& roi, vector<Mat*> edgeImgs) {

        if(!channelEdgeImgs.size()) {
            return;  
        }

        for(int y=roi.y; y<(roi.y+roi.height); y++) {
            for(int x=roi.x; x<(roi.x+roi.width); x++) {
                for(Mat mat : channelEdgeImgs) {
                    if(L(mat,x,y) == 255) {
                        L((*edgeImgs[0]), x, y) = 0;
                        L((*edgeImgs[1]), x, y) = 255;
                        break;
                    } 
                    L((*edgeImgs[0]), x, y) = 255;
                    L((*edgeImgs[1]), x, y) = 0;
                }
            }
        }
    }

    
/*property*/
private:
    vector<ChannelType> _engagedChannels;
    map<ChannelType, Mat> _channelMats;
    map<ChannelType, EdgeThreshold> _allEdgeThresholds;
    EdgeManager& _edgeManager = EdgeManager::getInstance();
    
};

#endif // EDGEFACTORY_H
