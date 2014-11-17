#include "channelFunc.h"

ChannelFunc::ChannelFunc() {

}

int ChannelFunc::value(MatSet* matSet, int x, int y) {
	return B(matSet->bgr(), x, y);
}
  	

int ChannelFunc::value(MatSet* matSet, Point point) {
	 return value(matSet, point.x, point.y);
}