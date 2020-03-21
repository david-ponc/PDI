/********************************************************************************
** Form generated from reading UI file 'WinSlider.ui'
**
** Created by: Qt User Interface Compiler version 5.14.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WINSLIDER_H
#define UI_WINSLIDER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>

QT_BEGIN_NAMESPACE

class Ui_WinSlider
{
public:
    QPushButton *pushButton;
    QSlider *horizontalSlider;
    QLabel *lbl_title;
    QLabel *lbl_rini;
    QLabel *lbl_rend;
    QLabel *label_4;
    QLabel *lbl_actualValue;
    QLabel *preview;
    QCheckBox *checkBox;

    void setupUi(QDialog *WinSlider)
    {
        if (WinSlider->objectName().isEmpty())
            WinSlider->setObjectName(QString::fromUtf8("WinSlider"));
        WinSlider->resize(312, 394);
        QFont font;
        font.setFamily(QString::fromUtf8("Nunito"));
        WinSlider->setFont(font);
        pushButton = new QPushButton(WinSlider);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(200, 125, 89, 25));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Nunito"));
        font1.setPointSize(10);
        font1.setBold(true);
        font1.setWeight(75);
        pushButton->setFont(font1);
        horizontalSlider = new QSlider(WinSlider);
        horizontalSlider->setObjectName(QString::fromUtf8("horizontalSlider"));
        horizontalSlider->setGeometry(QRect(70, 50, 160, 16));
        horizontalSlider->setValue(0);
        horizontalSlider->setSliderPosition(0);
        horizontalSlider->setOrientation(Qt::Horizontal);
        lbl_title = new QLabel(WinSlider);
        lbl_title->setObjectName(QString::fromUtf8("lbl_title"));
        lbl_title->setGeometry(QRect(30, 20, 67, 17));
        lbl_rini = new QLabel(WinSlider);
        lbl_rini->setObjectName(QString::fromUtf8("lbl_rini"));
        lbl_rini->setGeometry(QRect(40, 50, 21, 17));
        lbl_rend = new QLabel(WinSlider);
        lbl_rend->setObjectName(QString::fromUtf8("lbl_rend"));
        lbl_rend->setGeometry(QRect(260, 50, 51, 17));
        label_4 = new QLabel(WinSlider);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(20, 100, 81, 17));
        lbl_actualValue = new QLabel(WinSlider);
        lbl_actualValue->setObjectName(QString::fromUtf8("lbl_actualValue"));
        lbl_actualValue->setGeometry(QRect(120, 100, 67, 17));
        preview = new QLabel(WinSlider);
        preview->setObjectName(QString::fromUtf8("preview"));
        preview->setGeometry(QRect(10, 240, 291, 141));
        checkBox = new QCheckBox(WinSlider);
        checkBox->setObjectName(QString::fromUtf8("checkBox"));
        checkBox->setGeometry(QRect(20, 130, 111, 17));

        retranslateUi(WinSlider);

        QMetaObject::connectSlotsByName(WinSlider);
    } // setupUi

    void retranslateUi(QDialog *WinSlider)
    {
        WinSlider->setWindowTitle(QCoreApplication::translate("WinSlider", "Dialog", nullptr));
        pushButton->setText(QCoreApplication::translate("WinSlider", "Confirmar", nullptr));
        lbl_title->setText(QCoreApplication::translate("WinSlider", "Alfa:", nullptr));
        lbl_rini->setText(QCoreApplication::translate("WinSlider", "0", nullptr));
        lbl_rend->setText(QCoreApplication::translate("WinSlider", "10", nullptr));
        label_4->setText(QCoreApplication::translate("WinSlider", "Valor actual:", nullptr));
        lbl_actualValue->setText(QString());
        preview->setText(QString());
        checkBox->setText(QCoreApplication::translate("WinSlider", "Previsualizar", nullptr));
    } // retranslateUi

};

namespace Ui {
    class WinSlider: public Ui_WinSlider {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WINSLIDER_H
