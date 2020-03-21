#include "Image.h"
#include <QString>
#include <QImage>
#include <QtMath>
#ifndef TOOLS_H
#define TOOLS_H


class Tools {
    public:
        Image static HistogramRGB(Image img);
        void static HistogramR(Image img);
        void static HistogramG(Image img);
        void static HistogramB(Image img);
        void static HistogramGray(Image img);
        void static SolidGraph(int normal, Image histo, QString channel, int j);
};

#endif // TOOLS_H
