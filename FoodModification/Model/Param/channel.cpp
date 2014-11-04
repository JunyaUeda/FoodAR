#include "channel.h"

Channel::Channel(){

}

Channel::Channel(int type) {
    _type = type;
}

Channel::Channel(int type, int value) {
    _type = type;
    _value = value;
}


int Channel::value() const {
    return _value;
}

void Channel::setValue(int value) {
    _value = value;
}

int Channel::type() const {
    return _type;
}

void Channel::setType(int type) {
    _type = type;
}
