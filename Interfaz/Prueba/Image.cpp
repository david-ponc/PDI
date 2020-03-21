#include "Image.h"

Image::Image() {
    name = "";
    path = "";
    width = 0;
    height = 0;
    bpp = 0;
}

void Image::Create(int width, int height, int bpp, QString path, QString name, QString type) {
    this->name = name;
    this->path = path;
    this->width = width;
    this->height = height;
    this->bpp = bpp;
    this->pixels = new Pixel*[this->height];

    for(int i = 0; i < this->height; i++) {
        this->pixels[i] = new Pixel[this->width];
    }
}
