#include "Image.h"
#include <QString>
#include <QFile>
#include <QTextStream>
#include <QImage>

#ifndef OPERATIONS_H
#define OPERATIONS_H


class Operations {
public:
    static Image Load(QString imagePath, QString name);
    static Image Copy(Image img, QString name = "original");
};

#endif // OPERATIONS_H
