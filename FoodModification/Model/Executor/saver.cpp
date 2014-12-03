#include "saver.h"

#define FILE_PATH "../samplee.xml"

Saver::Saver() {
}

Saver& Saver::getInstance() {
    static Saver instance;
    return instance;
}

void Saver::save() {
    QFile file(FILE_PATH);
    if(!file.open(QIODevice::WriteOnly | QIODevice::Truncate)) {
        qDebug() << "file is not opend.";
    }

    QXmlStreamWriter writer(&file);
    writer.setAutoFormatting(true);
    writer.writeStartDocument();
    writer.writeStartElement("root");
    
    _windowManager.save(writer);
    _cameraManager.save(writer);


    writer.writeEndElement();
    writer.writeEndDocument();
    file.close();   

}