#ifndef PIXEL_H
#define PIXEL_H

#include "Pixel.h"
#include <string>
using namespace std;



class Image: public Pixel {
  private:
    int width;
    int height;
    int bpp;
    Pixel** pixels;
    string name;
    public:
      Image() { width = 0; height = 0; bpp = 0;};
      ~Image() {};
      void Create(int width, int height, int bpp);
    friend class Operations;
    friend class Filters;
};

void Image::Create(int width, int height, int bpp) {
  this->width = width;
  this->height = height;
  this->bpp = bpp;
  this->pixels = new Pixel*[this->width];
  for(int i = 0; i < this->width; i++) {
    this->pixels[i] = new Pixel[this->height];
  }
}

#endif