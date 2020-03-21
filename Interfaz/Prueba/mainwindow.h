#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFileDialog>
#include <QDir>
#include <QDebug>
#include <QPixmap>
#include <QStack>
#include <QDesktopWidget>
#include <QInputDialog>
#include "Image.h"
#include "Operations.h"
#include "Filters.h"
#include "Tools.h"
#include "WinSlider.h"
#include <QShortcut>
#include <QMessageBox>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    Image currentImg;
    QStack<Image> imagesList;
    void Draw(Image img);
    void showHistogram(Image img);
    double showWindow(int min, int max, QString title, QString text, Image img, QString filter);
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_menubarOptionOpen_triggered();

    void on_menubarOptionNegative_triggered();

    void on_menubarOptionGrayscale_triggered();

    void on_menubarOptionPower_triggered();

    void on_menubarOptionAclarado_logar_tmico_triggered();

    void on_menubarOptionSeno_triggered();

    void on_menubarOptionAclarado_triggered();

    void on_menubarOptionCosenoidal_triggered();

    void on_menubarOptionOscurecimiento_triggered();

    void on_menubarOptionEscala_de_grises_triggered();

    void on_menubarOptionPor_canal_triggered();

    void backStep();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
