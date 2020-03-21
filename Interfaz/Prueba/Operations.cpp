#include "Operations.h"
#include <QDebug>

Image Operations::Load(QString imagePath, QString name) {
    QString data;
    Image img;
    QFile imageFile(imagePath);
    imageFile.open(QIODevice::ReadOnly | QIODevice::Text);
    QTextStream file(&imageFile);

    file.readLine(); // P3
    file.readLine(); // Comment

    QStringList size = file.readLine().split(" ");
    int width = size.at(0).toInt();
    int height = size.at(1).toInt();

    int bpp = file.readLine().toInt();

    img.Create(width, height, bpp, imagePath, name);

    for(int i = 0; i < img.height; i++) {
        for(int j = 0; j < img.width; j++) {
            img.pixels[i][j].R = file.readLine().toInt();
            img.pixels[i][j].G = file.readLine().toInt();
            img.pixels[i][j].B = file.readLine().toInt();
        }
    }

    return img;
}

Image Operations::Copy(Image img, QString name) {
    Image copy;
    copy.name = name;
    copy.path = img.path;
    copy.width = img.width;
    copy.height = img.height;
    copy.bpp = img.bpp;

    copy.Create(img.width, img.height, img.bpp, copy.path, copy.name);

    for(int i = 0; i < copy.height; i++) {
        for(int j = 0; j < copy.width; j++) {
            copy.pixels[i][j].R = img.pixels[i][j].R;
            copy.pixels[i][j].G = img.pixels[i][j].G;
            copy.pixels[i][j].B = img.pixels[i][j].B;
        }
    }
    return copy;
}
