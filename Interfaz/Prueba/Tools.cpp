#include "Tools.h"

Image Tools::HistogramRGB(Image img) {
    Image histo;
    histo.Create(256,256,255, "", "histogramaRGB");

    int histoR[256] = {0}, histoG[256] = {0}, histoB[256] = {0};
    int maxR = 0, maxG = 0, maxB = 0, max = 0;

    for(int i = 0; i < img.height; i++) {
        for(int j = 0; j < img.width; j++) {
            histoR[img.pixels[i][j].R]++;
            histoG[img.pixels[i][j].G]++;
            histoB[img.pixels[i][j].B]++;
        }
    }

    for(int i = 0; i < 256; i++) {
        if(histoR[i] > maxR) {
            maxR = histoR[i];
        }
        if(histoG[i] > maxG) {
            maxG = histoG[i];
        }
        if(histoB[i] > maxB) {
            maxB = histoB[i];
        }
    }

    max = maxR;
    if(max < maxG)
        max = maxG;
    if(max < maxB)
        max = maxB;

    for(int j = 0; j < histo.width; j++) {
        int normalR = (histoR[j] * 100) / max;
        normalR = histo.height - ((normalR * histo.height) / 100);
        int normalG = (histoG[j] * 100) / max;
        normalG = histo.height - ((normalG * histo.height) / 100);
        int normalB = (histoB[j] * 100) / max;
        normalB = histo.height - ((normalB * histo.height) / 100);
        SolidGraph(normalR, histo, "R", j);
        SolidGraph(normalG, histo, "G", j);
        SolidGraph(normalB, histo, "B", j);
    }
    return histo;
}

void Tools::SolidGraph(int normal, Image histo, QString channel, int j) {
    for(int i = normal; i < histo.height; i++) {
        if(channel == "R") {
            histo.pixels[i][j].R = 255;
        }else if(channel == "G") {
            histo.pixels[i][j].G = 255;
        }else if(channel == "B") {
            histo.pixels[i][j].B = 255;
        }
    }
}
