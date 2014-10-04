#ifndef EDGEPARAM_H
#define EDGEPARAM_H

class EdgeParam {
public:
    EdgeParam();

	int cannyThreshold_1() const;
	void setCannyThreshold_1(int cannyThreshold_1);

	int cannyThreshold_2() const;
	void setCannyThreshold_2(int cannyThreshold_2);

private:
	int _cannyThreshold_1 = 30;
	int _cannyThreshold_2 = 60;
};

#endif // EDGEPARAM_H
