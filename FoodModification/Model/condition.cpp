#include "condition.h"

Condition::Condition() {
	_usedChannelList.push_back(new HueFunc());
	_usedChannelList.push_back(new SaturationFunc());
	_usedChannelList.push_back(new ValueFunc());
}

Condition& Condition::getInstance() {
    static Condition instance;
    return instance;
}
