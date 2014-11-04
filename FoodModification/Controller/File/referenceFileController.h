#ifndef REFERENCEFILECONTROLLER_H
#define REFERENCEFILECONTROLLER_H

class ReferenceFileController : public FileController {
public:
	static ReferenceFileController& getInstance();
private:
};

#endif // REFERENCEFILECONTROLLER_H
