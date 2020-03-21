#ifndef WINSLIDER_H
#define WINSLIDER_H

#include <QDialog>
#include <QDebug>
#include "Image.h"
#include "Filters.h"
#include "Operations.h"

namespace Ui {
class WinSlider;
}

class WinSlider : public QDialog
{
    Q_OBJECT

public:
    double value;
    bool confirm;
    bool statePreview;
    Image img;
    QString filter;
    explicit WinSlider(QWidget *parent = nullptr);
    void Draw(Image img);
    void ApplyFilterToPreview();
    void updateData(int min, int max, QString title, QString text, Image img, QString filter, int actual = 1);
    ~WinSlider();

private slots:
    void on_pushButton_clicked();

    void on_horizontalSlider_valueChanged(int value);

    void on_checkBox_clicked(bool checked);

    void on_horizontalSlider_sliderPressed();

    void on_horizontalSlider_sliderReleased();

private:
    Ui::WinSlider *ui;
};

#endif // WINSLIDER_H
