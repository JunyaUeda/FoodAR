#ifndef COLOR_H
#define COLOR_H

class Color {

/*property*/
private:
	int value0;
	int value1;
	int value2;

/*method*/
public:
    Color();
    int getValue0() const;
    void setValue0(int value);
    int getValue1() const;
    void setValue1(int value);
    int getValue2() const;
    void setValue2(int value);
};

#endif // COLOR_H
