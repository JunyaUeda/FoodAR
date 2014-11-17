#ifndef CONDITION_H
#define CONDITION_H

#include "./Param/channelFunc/channelFunc.h"
#include "./Param/channelFunc/hueFunc.h"
#include "./Param/channelFunc/saturationFunc.h"
#include "./Param/channelFunc/valueFunc.h"
#include <QList>

class Condition {

/*property*/
private:
    QList<ChannelFunc*> _usedChannelList;

/*method*/
public:
	static Condition& getInstance();

private:
    Condition();
    Condition(const Condition&);
    
};

#endif // CONDITION_H
