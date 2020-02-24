#include <stdio.h>
#include <fstream>
#include <string>
#include <math.h>
#include "Image.h"
using namespace std;

// #ifndef IMAGE_H
// #define IMAGE_H

class Functions {
  public:
    // Operations
    void Print(Image img);
    Image Load(string name);
    Image Copy(Image img);
    void Save(Image img, string name, string comment);

    // Helpers
    Image Apply(Image img, int (*filter)());

    // Filters
    Image GradientLeft(Image img);
    float Negative(Image img);

};

// #endif