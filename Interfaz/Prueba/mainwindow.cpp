#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent): QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);
    ui->menuFiltros->setDisabled(true);

    QString menubarStyle= "QMenuBar {spacing: 3px; background: #0e0e10; color: #f2f4f5;}"
                          "QMenuBar::item {font-size: 16px;}"
                          "QMenuBar::item:selected {background: #26262c;}"
                          "QMenuBar::item:pressed {background: #26262c;}"
                          "QMenu {background: #0e0e10; color: #f2f4f5; padding: 0;}"
                          "QMenu::item:selected {background: #26262c;}"
                          "QMenu::item:pressed {background: #26262c;}";

    QString asd = "QLabel { }";

    ui->menubar->setStyleSheet(menubarStyle);
    this->setStyleSheet("QMainWindow {background: #18181b;font-size: 1rem;}"+asd);
    new QShortcut(QKeySequence(Qt::CTRL + Qt::Key_Z), this, SLOT(backStep()));
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::backStep() {
    if(!this->imagesList.isEmpty() && currentImg.name != "original") {
        this->imagesList.pop();
        currentImg = this->imagesList.top();
        Draw(currentImg);
        showHistogram(currentImg);
    }else {
        qDebug() << "Nada que hacer";
    }
}

void MainWindow::Draw(Image img) {
    qDebug() << currentImg.name;
    int widthScreen = QApplication::desktop()->width();
    int heightSreen = QApplication::desktop()->height();
    QImage qImage;
    qImage.load(img.path);
    for(int i = 0; i < img.height; i++) {
        for(int j = 0; j < img.width; j++) {
            qImage.setPixel(j, i, qRgb(img.pixels[i][j].R, img.pixels[i][j].G, img.pixels[i][j].B));
        }
    }
    qImage = qImage.scaledToWidth(widthScreen*.8, Qt::SmoothTransformation);
    ui->lbl_image->setGeometry(32,32, widthScreen*.8, heightSreen*.8);
    ui->lbl_image->setPixmap(QPixmap::fromImage(qImage));
}

void MainWindow::showHistogram(Image img) {
    Image histo = Tools::HistogramRGB(img);
    QString tempPath = QDir::tempPath();
    QDir dir;
    QFile tempFile(tempPath+"/histo.ppm");
    if(!dir.exists())
        dir.mkpath(tempPath);
    if(tempFile.open(QIODevice::ReadWrite)) {
        QString str = "P3\n#Histo\n256 256\n255\n";
        QTextStream outStream(&tempFile);
        outStream << str;
        tempFile.close();
    }
    QImage qImage;
    qImage.load(tempPath+"/histo.ppm");
    for(int i = 0; i < histo.height; i++) {
        for(int j = 0; j < histo.width; j++) {
            qImage.setPixel(j, i, qRgb(histo.pixels[i][j].R, histo.pixels[i][j].G, histo.pixels[i][j].B));
        }
    }
    qImage = qImage.scaledToWidth(256, Qt::SmoothTransformation);
    ui->lbl_histo->setGeometry(1616,32, 256, 256);
    ui->lbl_histo->setPixmap(QPixmap::fromImage(qImage));
}

double MainWindow::showWindow(int min, int max, QString title, QString text, Image img, QString filter) {
    WinSlider *window = new WinSlider();
    window->updateData(min, max, title, text, img, filter);
    //connect(window, SIGNAL(valueChanged(int value)), ui->lbl_image, SLOT(on_horizontalSlider_valueChanged(int value)));
    window->exec();
    if(window->confirm)
        return  window->value;
    else
        return -1;
}


void MainWindow::on_menubarOptionOpen_triggered() {
    //qDebug() << "tempPath: " << QDir::tempPath();
    try {
        QString imagePath = QFileDialog::getOpenFileName(this, tr("Cargar imagen"), QDir::homePath(), tr("Images (*.ppm)"));
        if(!imagePath.isEmpty()) {
            currentImg = Operations::Load(imagePath, "original");
            ui->menuFiltros->setDisabled(false);
            imagesList.push(currentImg);
            Draw(currentImg);
            showHistogram(currentImg);
        }
    } catch (_exception e) {
        QMessageBox messageBox;
        messageBox.critical(0,"Error", "Aiudaaaaaaaa!");
        messageBox.setFixedSize(500,200);
    }
}

void MainWindow::on_menubarOptionNegative_triggered() {
    Image negative = Operations::Copy(currentImg, "negative");
    negative = Filters::Negative(negative);
    imagesList.push(negative);
    currentImg = negative;
    Draw(currentImg);
    showHistogram(currentImg);
}

void MainWindow::on_menubarOptionGrayscale_triggered() {
    Image grayscale = Operations::Copy(currentImg, "grayscale");
    grayscale = Filters::Grayscale(grayscale);
    imagesList.push(grayscale);
    currentImg = grayscale;
    Draw(currentImg);
    showHistogram(currentImg);
}

void MainWindow::on_menubarOptionPower_triggered() {
    Image power = Operations::Copy(currentImg, "power");
    double alpha = showWindow(1, 1000, "Potencia", "Alfa: ", power, "power");
    if(alpha > 0) {
        power = Filters::Power(power, alpha);
        imagesList.push(power);
        currentImg = power;
        Draw(power);
        showHistogram(currentImg);
    }
}

void MainWindow::on_menubarOptionAclarado_logar_tmico_triggered() {
    Image logarithm = Operations::Copy(currentImg, "logarithmicRinse");
    double alpha = showWindow(1, 10000, "Aclarado logarítmico", "Alfa: ", logarithm, "logarithmicRinse");
    if(alpha > 0) {
        logarithm = Filters::LogarithmicRinse(logarithm, alpha);
        imagesList.push(logarithm);
        currentImg = logarithm;
        Draw(logarithm);
        showHistogram(currentImg);
    }
}

void MainWindow::on_menubarOptionSeno_triggered() {
    Image sine = Operations::Copy(currentImg, "sine");
    sine = Filters::Sine(sine);
    imagesList.push(sine);
    currentImg = sine;
    Draw(currentImg);
    showHistogram(currentImg);
}

void MainWindow::on_menubarOptionAclarado_triggered() {
    Image exrinse = Operations::Copy(currentImg, "exponentialRinse");
    double alpha = showWindow(1, 10000, "Aclarado", "Alfa: ", exrinse, "exrinse");
    if(alpha > 0) {
        exrinse = Filters::Exponential(exrinse, alpha);
        imagesList.push(exrinse);
        currentImg = exrinse;
        Draw(exrinse);
        showHistogram(currentImg);
    }
}

void MainWindow::on_menubarOptionCosenoidal_triggered() {
    Image cosenoidal = Operations::Copy(currentImg, "cosenoidal");
    cosenoidal = Filters::Cosenoidal(cosenoidal);
    imagesList.push(cosenoidal);
    currentImg = cosenoidal;
    Draw(currentImg);
    showHistogram(currentImg);
}

void MainWindow::on_menubarOptionOscurecimiento_triggered() {
    Image exdark = Operations::Copy(currentImg, "exponentialDark");
    double alpha = showWindow(1, 10000, "Oscurecimiento", "Alfa: ", exdark, "exdark");
    if(alpha > 0) {
        exdark = Filters::ExponentialDarkening(exdark, alpha);
        imagesList.push(exdark);
        currentImg = exdark;
        Draw(exdark);
        showHistogram(currentImg);
    }
}

void MainWindow::on_menubarOptionEscala_de_grises_triggered() {
    Image bingray = Operations::Copy(currentImg, "binarizeGray");
    double alpha = showWindow(1, 10000, "Binarización", "Treshold: ", bingray, "bingray");
    if(alpha > 0) {
        bingray = Filters::Binarize(bingray, alpha);
        imagesList.push(bingray);
        currentImg = bingray;
        Draw(bingray);
        showHistogram(currentImg);
    }
}

void MainWindow::on_menubarOptionPor_canal_triggered() {
    Image bincnhnl = Operations::Copy(currentImg, "binarizeChannel");
    double alpha = showWindow(1, 10000, "Binarización por canal", "Treshold: ", bincnhnl, "bincnhnl");
    if(alpha > 0) {
        bincnhnl = Filters::Binarize(bincnhnl, alpha);
        imagesList.push(bincnhnl);
        currentImg = bincnhnl;
        Draw(bincnhnl);
        showHistogram(currentImg);
    }
}
