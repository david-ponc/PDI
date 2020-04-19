#include "Image.h"
#include <QString>
#include <QFile>
#include <QTextStream>
#include <QImage>
#include <QtMath>

#ifndef FILTERS_H
#define FILTERS_H


class Filters {
    public:
        static Image Negative(Image img);
        static Image Grayscale(Image img);
        static Image Power(Image img, double alpha);
        static Image LogarithmicRinse(Image img, double alpha);
        static Image Sine(Image img);
        static Image Exponential(Image img, double alpha);
        static Image Cosenoidal(Image img);
        static Image ExponentialDarkening(Image img, double alpha);
        static Image Binarize(Image img, int threshold);
        static Image BinarizeByChannel(Image img, int threshold);
        static Image BorderHorizontal(Image img);
        static Image BorderVertical(Image img);
        static Image gradientL1(Image img);
        static Image gradientL2(Image img);
};

#endif // FILTERS_H
