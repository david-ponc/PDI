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

    void setupUi(QDialog *WinSlider)
    {
        if (WinSlider->objectName().isEmpty())
            WinSlider->setObjectName(QString::fromUtf8("WinSlider"));
        WinSlider->resize(312, 163);
        pushButton = new QPushButton(WinSlider);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(190, 120, 89, 25));
        horizontalSlider = new QSlider(WinSlider);
        horizontalSlider->setObjectName(QString::fromUtf8("horizontalSlider"));
        horizontalSlider->setGeometry(QRect(60, 70, 160, 16));
        horizontalSlider->setValue(0);
        horizontalSlider->setSliderPosition(0);
        horizontalSlider->setOrientation(Qt::Horizontal);
        lbl_title = new QLabel(WinSlider);
        lbl_title->setObjectName(QString::fromUtf8("lbl_title"));
        lbl_title->setGeometry(QRect(40, 30, 67, 17));
        lbl_rini = new QLabel(WinSlider);
        lbl_rini->setObjectName(QString::fromUtf8("lbl_rini"));
        lbl_rini->setGeometry(QRect(30, 70, 21, 17));
        lbl_rend = new QLabel(WinSlider);
        lbl_rend->setObjectName(QString::fromUtf8("lbl_rend"));
        lbl_rend->setGeometry(QRect(250, 70, 51, 17));
        label_4 = new QLabel(WinSlider);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(20, 120, 81, 17));
        lbl_actualValue = new QLabel(WinSlider);
        lbl_actualValue->setObjectName(QString::fromUtf8("lbl_actualValue"));
        lbl_actualValue->setGeometry(QRect(110, 120, 67, 17));

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
        label_4->setText(QCoreApplication::translate("WinSlider", "Alfa actual:", nullptr));
        lbl_actualValue->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class WinSlider: public Ui_WinSlider {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WINSLIDER_H
