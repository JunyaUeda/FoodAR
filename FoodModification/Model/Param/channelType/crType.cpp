#include "crType.h"

CrType::CrType() {
}

int CrType::value(Mat img, int x, int y) {
	return G(img, x, y);
}

int CrType::value(MatSet* matSet, int x, int y) {
	return value(matSet->ycrcb(),x,y);
}