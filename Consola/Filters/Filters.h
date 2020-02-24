#include <stdio.h>
#include <fstream>
#include <string>
#define _USE_MATH_DEFINES
#include <math.h>
#include "Image.h"
using namespace std;

class Filters {
  public:
    static Image Negative(Image img);
    static Image Grayscale(Image img);
    static Image Power(Image, double alpha);
    static Image LogarithmicRinse(Image img, double alpha);
    static Image Sine(Image img);
    static Image Exponential(Image img, double alpha);
    static Image Cosenoidal(Image img);
    static Image ExponentialDarkening(Image img, double alpha);
    static Image Binarize(Image img, int threshold);
    static Image BinarizeByChannel(Image img, int threshold);
};

Image Filters::Negative(Image img) {
  for (int y = 0; y < img.height; y++) {
    for (int x = 0; x < img.width; x++) {
      img.pixels[x][y].R = img.bpp - img.pixels[x][y].R;
      img.pixels[x][y].G = img.bpp - img.pixels[x][y].G;
      img.pixels[x][y].B = img.bpp - img.pixels[x][y].B;
    }
  }
  return img;
}

Image Filters::Grayscale(Image img) {
  int gray;
  for (int y = 0; y < img.height; y++) {
    for (int x = 0; x < img.width; x++) {
      gray = (img.pixels[x][y].R + img.pixels[x][y].G + img.pixels[x][y].B) / 3;
      img.pixels[x][y].R = gray;
      img.pixels[x][y].G = gray;
      img.pixels[x][y].B = gray;
    }
  }
  return img;
}

//  0 <= alpha <= 10
Image Filters::Power(Image img, double alpha) {
  for (int y = 0; y < img.height; y++) {
    for (int x = 0; x < img.width; x++) {
      img.pixels[x][y].R = img.bpp * (pow(((double)img.pixels[x][y].R/img.bpp ), alpha));
      img.pixels[x][y].G = img.bpp * (pow(((double)img.pixels[x][y].G/img.bpp ), alpha));
      img.pixels[x][y].B = img.bpp * (pow(((double)img.pixels[x][y].B/img.bpp ), alpha));
    }
  }
  return img;
}

// lampda / log(Alfa*Lampda + 1) * log(alfa*z+1) alpha > 0
Image Filters::LogarithmicRinse(Image img, double alpha) {
  for (int y = 0; y < img.height; y++) {
    for (int x = 0; x < img.width; x++) {
      img.pixels[x][y].R = log(alpha * (img.pixels[x][y].R + 1)) * (img.bpp / log(alpha*(img.bpp + 1)));
      img.pixels[x][y].G = log(alpha * (img.pixels[x][y].G + 1)) * (img.bpp / log(alpha*(img.bpp + 1)));
      img.pixels[x][y].B = log(alpha * (img.pixels[x][y].B + 1)) * (img.bpp / log(alpha*(img.bpp + 1)));
    }
  }
  return img;
}

// lampda * sin((pi*x)/(2*lampda))
Image Filters::Sine(Image img) {
  for (int y = 0; y < img.height; y++) {
    for (int x = 0; x < img.width; x++) {
      img.pixels[x][y].R = img.bpp*sin((M_PI*img.pixels[x][y].R)/(2*img.bpp));
      img.pixels[x][y].G = img.bpp*sin((M_PI*img.pixels[x][y].G)/(2*img.bpp));
      img.pixels[x][y].B = img.bpp*sin((M_PI*img.pixels[x][y].B)/(2*img.bpp));
    }
  }
  return img;
}

Image Filters::Exponential(Image img, double alpha) {
  for (int y = 0; y < img.height; y++) {
    for (int x = 0; x < img.width; x++) {
      img.pixels[x][y].R = ((img.bpp)/(1 - exp(-1 * alpha))) * (1 - exp((-1 * alpha * img.pixels[x][y].R)/img.bpp));
      img.pixels[x][y].G = ((img.bpp)/(1 - exp(-1 * alpha))) * (1 - exp((-1 * alpha * img.pixels[x][y].G)/img.bpp));
      img.pixels[x][y].B = ((img.bpp)/(1 - exp(-1 * alpha))) * (1 - exp((-1 * alpha * img.pixels[x][y].B)/img.bpp));
    }
  }
  return img;
}

Image Filters::Cosenoidal(Image img) {
  for (int y = 0; y < img.height; y++) {
    for (int x = 0; x < img.width; x++) {
      img.pixels[x][y].R = img.bpp*(1-cos((M_PI*img.pixels[x][y].R)/(2*img.bpp)));
      img.pixels[x][y].G = img.bpp*(1-cos((M_PI*img.pixels[x][y].G)/(2*img.bpp)));
      img.pixels[x][y].B = img.bpp*(1-cos((M_PI*img.pixels[x][y].B)/(2*img.bpp)));
    }
  }
  return img;
}

Image Filters::ExponentialDarkening(Image img, double alpha) {
  for (int y = 0; y < img.height; y++) {
    for (int x = 0; x < img.width; x++) {
      img.pixels[x][y].R = (img.bpp/(exp(alpha)-1))*(exp((alpha*img.pixels[x][y].R)/img.bpp)-1);
      img.pixels[x][y].G = (img.bpp/(exp(alpha)-1))*(exp((alpha*img.pixels[x][y].G)/img.bpp)-1);
      img.pixels[x][y].B = (img.bpp/(exp(alpha)-1))*(exp((alpha*img.pixels[x][y].B)/img.bpp)-1);
    }
  }
  return img;
}

Image Filters::Binarize(Image img, int threshold) {
  for (int y = 0; y < img.height; y++) {
    for (int x = 0; x < img.width; x++) {
      if(img.pixels[x][y].R > threshold) {
        img.pixels[x][y].R = 255;
        img.pixels[x][y].G = 255;
        img.pixels[x][y].B = 255;
      }else {
        img.pixels[x][y].R = 0;
        img.pixels[x][y].G = 0;
        img.pixels[x][y].B = 0;
      }
    }
  }
  return img;
}

Image Filters::BinarizeByChannel(Image img, int threshold) {
  for (int y = 0; y < img.height; y++) {
    for (int x = 0; x < img.width; x++) {
      img.pixels[x][y].R = 0;
      img.pixels[x][y].G = 0;
      img.pixels[x][y].B = 0;
    }
  }
  return img;
}
