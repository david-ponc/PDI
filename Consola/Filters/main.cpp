#include <tuple>
#include <fstream>
#include <iostream>
#include <string>
#include "Operations.h"
#include "Filters.h"

using namespace std;

Image NewOrLoad();
int ShowMenu();
void SaveImage(Image img);
tuple<Image, Image> BuildResource();

int main() {
  cout << "******** Editor de imagenes ********" << endl;
  do {
    switch (ShowMenu()) {
      case 0: {
        cout << "Programa finalizado :P";
        return 0;
      } break;
      case 1: {
        Image original, copy;
        tie(original, copy) = BuildResource();
        Filters::Negative(copy);
        SaveImage(copy);
      } break;
      case 2: {
        Image original, copy;
        tie(original, copy) = BuildResource();
        Filters::Grayscale(copy);
        SaveImage(copy);
      } break;
      case 3: {
        Image original, copy; double alpha;
        tie(original, copy) = BuildResource();
        cout << "Alfa: ";cin >> alpha;
        Filters::Power(copy, alpha);
        SaveImage(copy);
      } break;
      case 4: {
        Image original, copy; double alpha;
        tie(original, copy) = BuildResource();
        cout << "Alfa: ";cin >> alpha;
        Filters::LogarithmicRinse(copy, alpha);
        SaveImage(copy);
      } break;
      case 5: {
        Image original, copy;
        tie(original, copy) = BuildResource();
        Filters::Sine(copy);
        SaveImage(copy);
      } break;
      case 6: {
        Image original, copy; double alpha;
        tie(original, copy) = BuildResource();
        cout << "Alfa: ";cin >> alpha;
        Filters::Exponential(copy, alpha);
        SaveImage(copy);
      } break;
      case 7: {
        Image original, copy;
        tie(original, copy) = BuildResource();
        Filters::Cosenoidal(copy);
        SaveImage(copy);
      } break;
      case 8: {
        Image original, copy; double alpha;
        tie(original, copy) = BuildResource();
        cout << "Alfa: ";cin >> alpha;
        Filters::ExponentialDarkening(copy, alpha);
        SaveImage(copy);
      } break;
      case 9: {
        Image original, copy; int treshold;
        tie(original, copy) = BuildResource();
        cout << "Umbral: ";cin >> treshold;
        Filters::Binarize(copy, treshold);
        SaveImage(copy);
      } break;
      case 10: {
        Image original, copy; int treshold;
        tie(original, copy) = BuildResource();
        cout << "Umbral: ";cin >> treshold;
        Filters::BinarizeByChannel(copy, treshold);
        SaveImage(copy);
      } break;
      case 11: {
        Image original, copy;
        tie(original, copy) = BuildResource();
        Image histo = Filters::Histogram(copy);
        SaveImage(histo);
      } break;
    }
  }while(true);
}

int ShowMenu() {
  int reply = -1;
  cout << "Filtros" << endl;
  cout << "(1) Negativo" << endl;
  cout << "(2) Escala de grises" << endl;
  cout << "(3) Potencia" << endl;
  cout << "(4) Aclarado logaritmico" << endl;
  cout << "(5) Seno" << endl;
  cout << "(6) Exponencial" << endl;
  cout << "(7) Cosenoidal" << endl;
  cout << "(8) Oscurecimiento exponencial" << endl;
  cout << "(9) Binarizar" << endl;
  cout << "(10) Binarizar por canal" << endl;
  cout << "(11) Histograma Gris" << endl;
  cout << "(0) Salir del programa" << endl;
  cout << "Accion: "; cin >> reply;
  return reply;
}

tuple<Image, Image> BuildResource() {
  string filename = "";
  Image img = NewOrLoad();
  Image copy = Operations::Copy(img);
  return make_tuple(img, copy);
}

void SaveImage(Image img) {
  try {
    string name;
    cout << "Nombre del nuevo archivo: "; cin >> name;
    Operations::Save(img, name, "Imagen creada por David Ponce");
    cout << "Imagen " + name + "creada exitosamente" << endl << endl;
  }catch(exception& e) {
    cerr << "Error al guardar imagen ... :(" << e.what() << endl;
  }
}

Image NewOrLoad() {
  int r = -1; Image img;
  cout << "(1) Abrir imagen" << endl;
  cout << "(2) Nueva imagen" << endl;
  cout << "Accion: "; cin >> r;
  cout << "--------------------" << endl;
  if(r == 1) {
    string name;
    cout << "Nombre: "; cin >> name;
    try {
      img = Operations::Load(name);
      cout << endl << "Imagen creada ... :D" << endl;
    }catch(exception& e) {
      cerr << "Error al cargar imagen ... :(" << e.what() << endl;
    }
    return img;
  }
  else if(r == 2) {
    int width, height, bpp;
    cout << "Ancho: "; cin >> width;
    cout << "Alto: "; cin >> height;
    cout << "Profundidad de bits: "; cin >> bpp;
    try {
      img.Create(width, height, bpp);
      cout << endl << "Imagen creada ... :D" << endl;
    }catch(exception& e) {
      cerr << "Error al crear imagen ... :(" << e.what() << endl;
    }
    return img;
  }else {
    cout << "Opcion desconocida" << endl;
    Image error;
    return error;
  }
}