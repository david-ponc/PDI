#include "WinSlider.h"
#include "ui_WinSlider.h"

WinSlider::WinSlider(QWidget *parent) : QDialog(parent), ui(new Ui::WinSlider) {
    ui->setupUi(this);
    QString buttonStyle = "QPushButton {background: #26262c; color: #f2f4f5; border-radius: 4px; font-size: 15px;}";
    QString labelStyle = "QLabel {color: #f2f4f5; font-size: 16px;}";
    QString sliderStyle = "QSlider::groove:horizontal {border: 1px solid #606770; height: 10px; margin: 0px; border-radius: 4px;}"
                          "QSlider::handle:horizontal {background: #01E0A5; width: 10px; height: 4px; border-radius: 4px;}";
    QString checkStyle = "QCheckBox {color: #f2f4f5; font-size: 15px;}";

    ui->horizontalSlider->setCursor(Qt::OpenHandCursor);
    ui->pushButton->setStyleSheet(buttonStyle);
    ui->pushButton->setCursor(Qt::PointingHandCursor);
    this->setStyleSheet("QDialog {background: #18181b;}"+labelStyle+sliderStyle+checkStyle);

    confirm = false;
    this->statePreview = false;
    ui->preview->setGeometry(5,226, 0, 0);
    this->setFixedSize(312, 168);
}

WinSlider::~WinSlider() {
    delete ui;
}

void WinSlider::Draw(Image img) {
    QImage qImage;
    qImage.load(img.path);
    for(int i = 0; i < img.height; i++) {
        for(int j = 0; j < img.width; j++) {
            qImage.setPixel(j, i, qRgb(img.pixels[i][j].R, img.pixels[i][j].G, img.pixels[i][j].B));
        }
    }
    qImage = qImage.scaledToWidth(312, Qt::SmoothTransformation);
    ui->preview->setGeometry(5,226, 300, 160);
    ui->preview->setPixmap(QPixmap::fromImage(qImage));
}


void WinSlider::updateData(int min, int max, QString title, QString text, Image img, QString filter, int actual) {
    ui->lbl_rini->setText(QString::number(min));
    ui->lbl_rend->setText(QString::number(max / 100));
    ui->horizontalSlider->setMinimum(min);
    ui->horizontalSlider->setMaximum(max);
    ui->horizontalSlider->setValue(actual);
    ui->lbl_title->setText(text);
    this->img = img;
    this->filter = filter;
    this->setWindowTitle(title);
    Draw(img);
}

void WinSlider::on_pushButton_clicked() {
    this->confirm = true;
    this->close();
}

void WinSlider::on_horizontalSlider_valueChanged(int value) {
    ui->lbl_actualValue->setText(QString::number((double)value / 100));
    this->value = (double)value / 100;
    if(this->statePreview) {
        ApplyFilterToPreview();
    }
}

void WinSlider::on_checkBox_clicked(bool checked)
{
    this->statePreview = checked;
    if(checked) {
        ui->preview->setGeometry(5,226, 300, 160);
        this->setFixedSize(312, 394);
        ApplyFilterToPreview();
    }else {
        ui->preview->setGeometry(5,226, 0, 0);
        this->setFixedSize(312, 168);
    }
}

void WinSlider::on_horizontalSlider_sliderPressed() {
    ui->horizontalSlider->setCursor(Qt::ClosedHandCursor);
}

void WinSlider::on_horizontalSlider_sliderReleased()
{
    ui->horizontalSlider->setCursor(Qt::OpenHandCursor);
}

void WinSlider::ApplyFilterToPreview() {
    Image preview = Operations::Copy(this->img);
    if(this->filter == "power") {
        preview = Filters::Power(preview,this->value);
    }
    if(this->filter == "logarithmicRinse") {
        preview = Filters::LogarithmicRinse(preview,this->value);
    }
    if(this->filter == "exrinse") {
        preview = Filters::Exponential(preview,this->value);
    }
    if(this->filter == "exdark") {
        preview = Filters::ExponentialDarkening(preview,this->value);
    }
    if(this->filter == "bingray") {
        preview = Filters::Binarize(preview,this->value);
    }
    if(this->filter == "bincnhnl") {
        preview = Filters::BinarizeByChannel(preview,this->value);
    }
    Draw(preview);
}
