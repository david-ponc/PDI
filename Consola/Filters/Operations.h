#ifndef IMAGE_H
#define IMAGE_H

#include <stdio.h>
#include <fstream>
#include <string>
#include <math.h>
#include "Image.h"
using namespace std;

class Operations{
  public:
    static void Print(Image img);
    static Image Load(string name);
    static Image Copy(Image img);
    static void Save(Image img, string name, string comment);
};

void Operations::Print(Image img) {

  for (int x = 0; x < img.width; x++) {
    for (int y = 0; y < img.height; y++) {
        cout << img.pixels[x][y].R << " " 
             << img.pixels[x][y].G << " " 
             << img.pixels[x][y].B << " ";
    }
    cout << endl;
  }

}

Image Operations::Load(string name) {
  if(name.find(".ppm")) {
    ifstream file(name);
    string data;
    Image img;

    string header;
    getline(file, header);

    string comment;
    getline(file, comment);

    getline(file, data, ' ');
    img.width = atoi(data.c_str());

    getline(file, data);
    img.height = atoi(data.c_str());

    getline(file, data);
    img.bpp = atoi(data.c_str());

    img.Create(img.width, img.height, img.bpp);

    for (int x = 0; x < img.width; x++) {
      for (int y = 0; y < img.height; y++) {
        getline(file, data);
        img.pixels[x][y].R = atoi(data.c_str());
        getline(file, data);
        img.pixels[x][y].G = atoi(data.c_str());
        getline(file, data);
        img.pixels[x][y].B = atoi(data.c_str());
      }
    }
    return img;
  }else {
    cout << "Ingrese la extension correta (ppm)" << endl;
    Image error;
    return error;
  }
}

Image Operations::Copy(Image img) {
  Image copy = img;
  return copy;
}

void Operations::Save(Image img, string name, string comment) {
  if(name.find(".ppm") == false) {
    name = name + ".ppm";
  }
  ofstream file(name);
  file << "P3" << endl;
  file << "#"+comment << endl;
  file << img.width << " " << img.height << endl;
  file << img.bpp << endl;

  for (int x = 0; x < img.width; x++) {
    for (int y = 0; y < img.height; y++) {
      file << img.pixels[x][y].R << endl;
      file << img.pixels[x][y].G << endl;
      file << img.pixels[x][y].B << endl;
    }
  }
}

#endif