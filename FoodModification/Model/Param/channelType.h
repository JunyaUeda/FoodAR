#ifndef CHANNELTYPE_H
#define CHANNELTYPE_H

#include <QString>

class ChannelType {

/*property*/
public:
    static const ChannelType B;
    static const ChannelType G;
    static const ChannelType R;
    static const ChannelType H;
    static const ChannelType S;
    static const ChannelType V;
    static const ChannelType Y;
    static const ChannelType Cr;
    static const ChannelType Cb;

private:
    QString _name;

/*method*/
public:
	QString toString() const {
        return _name;
    }

private:
    // ChannelType() {
       
    // }
    ChannelType(QString name) {
        _name=name;
    }

};

#endif // CHANNELTYPE_H
