#ifndef CHANNELTHRESHOLD_H
#define CHANNELTHRESHOLD_H

#include "./channelFunc/channelFunc.h"
#include "../../Utils/xmlUtils.h"
#include "./channelFunc/blueFunc.h"
#include "./channelFunc/greenFunc.h"
#include "./channelFunc/redFunc.h"
#include "./channelFunc/hueFunc.h"
#include "./channelFunc/saturationFunc.h"
#include "./channelFunc/valueFunc.h"
#include "./channelFunc/yFunc.h"
#include "./channelFunc/crFunc.h"
#include "./channelFunc/cbFunc.h"
#include "./matSet.h"

class ChannelThreshold {

/*method*/
public:
    ChannelThreshold(ChannelFunc* type);
    bool loadAverage(QDomElement element);
    void setThreshold(int average, int tolerance);
    static vector<ChannelThreshold> createAllChannelThreshold();

    bool isWithinThreshold(MatSet& matSet, Point& point) {
        int value = _channelFunc->value(matSet, point);
        if( (value <= _upper) && (value >= _under) ) {
            return true;
        }
        return false;
    }

    /**
    * ユーザーによるリアルタイムの閾値調整
    *　@param degree 0～100の整数
    *　0→variableTolerance=-tolerance
    * 50→variableTolerance=0;
    * 100→variableTolerance=2*tolerance;
    */
    void updateVariableTolerance(int degree);

    //getter setter
    ChannelFunc* channelFunc() const;
    int average() const;
    void setAverage(int average);
    int tolerance() const;
    void setTolerance(int tolerance);
    int upper() const;
    void setUpper(int upper);
    int under() const;
    void setUnder(int under);
    void displayThreshold();
    int degree() const {
        return _degree;
    }
private:
    ChannelThreshold();

/*property*/
private:
    ChannelFunc* _channelFunc;
	int _average;
	int _tolerance;//０以上
    int _degree = 50; // 閾値調整のView操作において扱う0～100の整数値
    int _variableTolerance = 0;//ユーザーによってコントロールできる。条件の強弱を変える
	int _upper;
	int _under;



};

#endif // CHANNELTHRESHOLD_H
