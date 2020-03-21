#include "Pixel.h"
#include <QString>

#ifndef IMAGE_H
#define IMAGE_H


class Image: public Pixel {
    private:
    public:
        QString name;
        QString path;
        QString type;
        int width;
        int height;
        int bpp;
        Pixel** pixels;
        Image();
        void Create(int width, int height, int bpp, QString path, QString name, QString type = "P3");
        friend class Operations;
        friend class Filters;
};

#endif // IMAGE_H
