#include "Filters.h"

Image Filters::Negative(Image img) {
    for(int i = 0; i < img.height; i++) {
        for(int j = 0; j < img.width; j++) {
            img.pixels[i][j].R = img.bpp - img.pixels[i][j].R;
            img.pixels[i][j].G = img.bpp - img.pixels[i][j].G;
            img.pixels[i][j].B = img.bpp - img.pixels[i][j].B;
        }
    }
    return img;
}

Image Filters::Grayscale(Image img) {
    int gray;
    for(int i = 0; i < img.height; i++) {
        for(int j = 0; j < img.width; j++) {
            gray = (img.pixels[i][j].R + img.pixels[i][j].G + img.pixels[i][j].B) / 3;
            img.pixels[i][j].R = gray;
            img.pixels[i][j].G = gray;
            img.pixels[i][j].B = gray;
        }
    }
    return img;
}

Image Filters::Power(Image img, double alpha) {
    for(int i = 0; i < img.height; i++) {
        for(int j = 0; j < img.width; j++) {
            img.pixels[i][j].R = img.bpp * (qPow(((double)img.pixels[i][j].R / img.bpp), alpha));
            img.pixels[i][j].G = img.bpp * (qPow(((double)img.pixels[i][j].G / img.bpp), alpha));
            img.pixels[i][j].B = img.bpp * (qPow(((double)img.pixels[i][j].B / img.bpp), alpha));
        }
    }
    return img;
}

Image Filters::LogarithmicRinse(Image img, double alpha) {
    for(int i = 0; i < img.height; i++) {
        for(int j = 0; j < img.width; j++) {
            img.pixels[i][j].R = log(alpha * (img.pixels[i][j].R + 1)) * (img.bpp / log(alpha*(img.bpp + 1)));
            img.pixels[i][j].G = log(alpha * (img.pixels[i][j].G + 1)) * (img.bpp / log(alpha*(img.bpp + 1)));
            img.pixels[i][j].B = log(alpha * (img.pixels[i][j].B + 1)) * (img.bpp / log(alpha*(img.bpp + 1)));
        }
    }
    return img;
}

Image Filters::Sine(Image img) {
    for(int i = 0; i < img.height; i++) {
        for(int j = 0; j < img.width; j++) {
            img.pixels[i][j].R = img.bpp * sin((M_PI * img.pixels[i][j].R) / (2 * img.bpp));
            img.pixels[i][j].G = img.bpp * sin((M_PI * img.pixels[i][j].G) / (2 * img.bpp));
            img.pixels[i][j].B = img.bpp * sin((M_PI * img.pixels[i][j].B) / (2 * img.bpp));
        }
    }
    return img;
}


Image Filters::Exponential(Image img, double alpha) {
    for(int i = 0; i < img.height; i++) {
        for(int j = 0; j < img.width; j++) {
            img.pixels[i][j].R = ((img.bpp)/(1 - exp(-1 * alpha))) * (1 - exp((-1 * alpha * img.pixels[i][j].R) / img.bpp));
            img.pixels[i][j].G = ((img.bpp)/(1 - exp(-1 * alpha))) * (1 - exp((-1 * alpha * img.pixels[i][j].G) / img.bpp));
            img.pixels[i][j].B = ((img.bpp)/(1 - exp(-1 * alpha))) * (1 - exp((-1 * alpha * img.pixels[i][j].B) / img.bpp));
        }
    }
    return img;
}

Image Filters::Cosenoidal(Image img) {
    for(int i = 0; i < img.height; i++) {
        for(int j = 0; j < img.width; j++) {
            img.pixels[i][j].R = img.bpp * (1 - cos((M_PI * img.pixels[i][j].R) / (2 * img.bpp)));
            img.pixels[i][j].G = img.bpp * (1 - cos((M_PI * img.pixels[i][j].G) / (2 * img.bpp)));
            img.pixels[i][j].B = img.bpp * (1 - cos((M_PI * img.pixels[i][j].B) / (2 * img.bpp)));
        }
    }
    return img;
}

Image Filters::ExponentialDarkening(Image img, double alpha) {
    for(int i = 0; i < img.height; i++) {
        for(int j = 0; j < img.width; j++) {
            img.pixels[i][j].R = (img.bpp / (exp(alpha) - 1)) * (exp((alpha * img.pixels[i][j].R) / img.bpp) -1);
            img.pixels[i][j].G = (img.bpp / (exp(alpha) - 1)) * (exp((alpha * img.pixels[i][j].G) / img.bpp) -1);
            img.pixels[i][j].B = (img.bpp / (exp(alpha) - 1)) * (exp((alpha * img.pixels[i][j].B) / img.bpp) -1);
        }
    }
    return img;
}

Image Filters::Binarize(Image img, int threshold) {
    for(int i = 0; i < img.height; i++) {
        for(int j = 0; j < img.width; j++) {
            if(img.pixels[i][j].R < threshold) {
                img.pixels[i][j].R = 255;
                img.pixels[i][j].G = 255;
                img.pixels[i][j].B = 255;
            }else {
                img.pixels[i][j].R = 0;
                img.pixels[i][j].G = 0;
                img.pixels[i][j].B = 0;
            }
        }
    }
    return img;
}

Image Filters::BinarizeByChannel(Image img, int threshold) {
    for(int i = 0; i < img.height; i++) {
        for(int j = 0; j < img.width; j++) {
            if(img.pixels[i][j].R < threshold) {
                img.pixels[i][j].R = 255;
                img.pixels[i][j].G = 255;
                img.pixels[i][j].B = 255;
            }else {
                img.pixels[i][j].R = 0;
                img.pixels[i][j].G = 0;
                img.pixels[i][j].B = 0;
            }
        }
    }
    return img;
}

Image Filters::BorderHorizontal(Image img) {
    for(int i = 0; i < img.height; i++) {
        for(int j = 0; j < img.width; j++) {
            if(i+1 < img.height) {
                img.pixels[i][j].R = abs(img.pixels[i+1][j].R - img.pixels[i][j].R);
                img.pixels[i][j].G = abs(img.pixels[i+1][j].G - img.pixels[i][j].G);
                img.pixels[i][j].B = abs(img.pixels[i+1][j].B - img.pixels[i][j].B);
            }else {
                img.pixels[i][j].R = 0;
                img.pixels[i][j].G = 0;
                img.pixels[i][j].B = 0;
            }
        }
    }
    return img;
}

Image Filters::BorderVertical(Image img) {
    for(int i = 0; i < img.height; i++) {
        for(int j = 0; j < img.width; j++) {
            if(j+1 < img.width) {
                img.pixels[i][j].R = abs(img.pixels[i][j+1].R - img.pixels[i][j].R);
                img.pixels[i][j].G = abs(img.pixels[i][j+1].G - img.pixels[i][j].G);
                img.pixels[i][j].B = abs(img.pixels[i][j+1].B - img.pixels[i][j].B);
            }else {
                img.pixels[i][j].R = 0;
                img.pixels[i][j].G = 0;
                img.pixels[i][j].B = 0;
            }
        }
    }
    return img;
}

Image Filters::gradientL1(Image img) {
    for(int i = 0; i < img.height; i++) {
        for(int j = 0; j < img.width; j++) {
            if(i+1 < img.height && j+1 < img.width) {
                img.pixels[i][j].R = 0.5*(sqrt(pow(img.pixels[i+1][j].R - img.pixels[i][j].R, 2) + pow(img.pixels[i][j+1].R - img.pixels[i][j].R, 2)));
                img.pixels[i][j].G = 0.5*(sqrt(pow(img.pixels[i+1][j].G - img.pixels[i][j].G, 2) + pow(img.pixels[i][j+1].G - img.pixels[i][j].G, 2)));
                img.pixels[i][j].B = 0.5*(sqrt(pow(img.pixels[i+1][j].B - img.pixels[i][j].B, 2) + pow(img.pixels[i][j+1].B - img.pixels[i][j].B, 2)));
            }else {
                img.pixels[i][j].R = 0;
                img.pixels[i][j].G = 0;
                img.pixels[i][j].B = 0;
            }
        }
    }
    return img;
}
