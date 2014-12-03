#ifndef QTUTIL_H
#define QTUTIL_H

#include <QString>

class QtUtil {

public:
	QtUtil();
    static QString toQString(int value) {
        return QString(QString::number(value));
    }
};

#endif // QTUTIL_H
