#ifndef CANNYTHRESHOLD_H
#define CANNYTHRESHOLD_H

class CannyThreshold {

public:
	CannyThreshold();
	CannyThreshold(int value1, int value2);
	CannyThreshold(const CannyThreshold&);

	int value1() const;
	void setValue1(int value1);

	int value2() const;
	void setValue2(int value2);

private:
	int _value1 = 30;
	int _value2 = 60;

};

#endif // CANNYTHRESHOLD_H
