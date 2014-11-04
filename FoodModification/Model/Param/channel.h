#ifndef CHANNEL_H
#define CHANNEL_H

class Channel {

/*property*/
private:
	int _value;
	int _type;

/*method*/
public:
	Channel();
    Channel(int type);
    Channel(int type, int value);
    /*getter setter*/
    int value() const;
    void setValue(int value);
    int type() const;
    void setType(int type);
};

#endif // CHANNEL_H
