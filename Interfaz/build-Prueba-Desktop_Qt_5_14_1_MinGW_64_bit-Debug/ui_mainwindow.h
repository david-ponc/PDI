/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.14.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionNuevo;
    QAction *menubarOptionOpen;
    QAction *actionHisograma;
    QAction *menubarOptionNegative;
    QAction *menubarOptionGrayscale;
    QAction *menubarOptionPower;
    QAction *menubarOptionAclarado_logar_tmico;
    QAction *menubarOptionSeno;
    QAction *menubarOptionCosenoidal;
    QAction *menubarOptionEscala_de_grises;
    QAction *menubarOptionPor_canal;
    QAction *menubarOptionAclarado;
    QAction *menubarOptionOscurecimiento;
    QWidget *centralwidget;
    QLabel *lbl_image;
    QLabel *lbl_histo;
    QMenuBar *menubar;
    QMenu *menuArchivo;
    QMenu *menuFiltros;
    QMenu *menuBinarizaci_n;
    QMenu *menuExponencial_2;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(775, 486);
        QFont font;
        font.setFamily(QString::fromUtf8("Nunito"));
        font.setPointSize(10);
        font.setBold(false);
        font.setItalic(false);
        font.setUnderline(false);
        font.setWeight(50);
        MainWindow->setFont(font);
        actionNuevo = new QAction(MainWindow);
        actionNuevo->setObjectName(QString::fromUtf8("actionNuevo"));
        menubarOptionOpen = new QAction(MainWindow);
        menubarOptionOpen->setObjectName(QString::fromUtf8("menubarOptionOpen"));
        actionHisograma = new QAction(MainWindow);
        actionHisograma->setObjectName(QString::fromUtf8("actionHisograma"));
        menubarOptionNegative = new QAction(MainWindow);
        menubarOptionNegative->setObjectName(QString::fromUtf8("menubarOptionNegative"));
        menubarOptionGrayscale = new QAction(MainWindow);
        menubarOptionGrayscale->setObjectName(QString::fromUtf8("menubarOptionGrayscale"));
        menubarOptionPower = new QAction(MainWindow);
        menubarOptionPower->setObjectName(QString::fromUtf8("menubarOptionPower"));
        menubarOptionAclarado_logar_tmico = new QAction(MainWindow);
        menubarOptionAclarado_logar_tmico->setObjectName(QString::fromUtf8("menubarOptionAclarado_logar_tmico"));
        menubarOptionSeno = new QAction(MainWindow);
        menubarOptionSeno->setObjectName(QString::fromUtf8("menubarOptionSeno"));
        menubarOptionCosenoidal = new QAction(MainWindow);
        menubarOptionCosenoidal->setObjectName(QString::fromUtf8("menubarOptionCosenoidal"));
        menubarOptionEscala_de_grises = new QAction(MainWindow);
        menubarOptionEscala_de_grises->setObjectName(QString::fromUtf8("menubarOptionEscala_de_grises"));
        menubarOptionPor_canal = new QAction(MainWindow);
        menubarOptionPor_canal->setObjectName(QString::fromUtf8("menubarOptionPor_canal"));
        menubarOptionAclarado = new QAction(MainWindow);
        menubarOptionAclarado->setObjectName(QString::fromUtf8("menubarOptionAclarado"));
        menubarOptionOscurecimiento = new QAction(MainWindow);
        menubarOptionOscurecimiento->setObjectName(QString::fromUtf8("menubarOptionOscurecimiento"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        lbl_image = new QLabel(centralwidget);
        lbl_image->setObjectName(QString::fromUtf8("lbl_image"));
        lbl_image->setGeometry(QRect(0, 0, 600, 400));
        lbl_image->setAlignment(Qt::AlignCenter);
        lbl_histo = new QLabel(centralwidget);
        lbl_histo->setObjectName(QString::fromUtf8("lbl_histo"));
        lbl_histo->setGeometry(QRect(730, 10, 47, 13));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 775, 21));
        menuArchivo = new QMenu(menubar);
        menuArchivo->setObjectName(QString::fromUtf8("menuArchivo"));
        menuFiltros = new QMenu(menubar);
        menuFiltros->setObjectName(QString::fromUtf8("menuFiltros"));
        menuBinarizaci_n = new QMenu(menuFiltros);
        menuBinarizaci_n->setObjectName(QString::fromUtf8("menuBinarizaci_n"));
        menuExponencial_2 = new QMenu(menuFiltros);
        menuExponencial_2->setObjectName(QString::fromUtf8("menuExponencial_2"));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        menubar->addAction(menuArchivo->menuAction());
        menubar->addAction(menuFiltros->menuAction());
        menuArchivo->addAction(actionNuevo);
        menuArchivo->addAction(menubarOptionOpen);
        menuFiltros->addAction(menubarOptionNegative);
        menuFiltros->addAction(menubarOptionGrayscale);
        menuFiltros->addAction(menubarOptionPower);
        menuFiltros->addAction(menubarOptionAclarado_logar_tmico);
        menuFiltros->addAction(menubarOptionSeno);
        menuFiltros->addAction(menuExponencial_2->menuAction());
        menuFiltros->addAction(menubarOptionCosenoidal);
        menuFiltros->addAction(menuBinarizaci_n->menuAction());
        menuBinarizaci_n->addAction(menubarOptionEscala_de_grises);
        menuBinarizaci_n->addAction(menubarOptionPor_canal);
        menuExponencial_2->addAction(menubarOptionAclarado);
        menuExponencial_2->addAction(menubarOptionOscurecimiento);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        actionNuevo->setText(QCoreApplication::translate("MainWindow", "Nuevo", nullptr));
        menubarOptionOpen->setText(QCoreApplication::translate("MainWindow", "Abrir", nullptr));
#if QT_CONFIG(shortcut)
        menubarOptionOpen->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+O", nullptr));
#endif // QT_CONFIG(shortcut)
        actionHisograma->setText(QCoreApplication::translate("MainWindow", "Hisograma", nullptr));
        menubarOptionNegative->setText(QCoreApplication::translate("MainWindow", "Negativo", nullptr));
#if QT_CONFIG(shortcut)
        menubarOptionNegative->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+Alt+Shift+N", nullptr));
#endif // QT_CONFIG(shortcut)
        menubarOptionGrayscale->setText(QCoreApplication::translate("MainWindow", "Escala de grises", nullptr));
        menubarOptionPower->setText(QCoreApplication::translate("MainWindow", "Potencia", nullptr));
        menubarOptionAclarado_logar_tmico->setText(QCoreApplication::translate("MainWindow", "Aclarado logar\303\255tmico", nullptr));
        menubarOptionSeno->setText(QCoreApplication::translate("MainWindow", "Seno", nullptr));
        menubarOptionCosenoidal->setText(QCoreApplication::translate("MainWindow", "Cosenoidal", nullptr));
        menubarOptionEscala_de_grises->setText(QCoreApplication::translate("MainWindow", "Escala de grises", nullptr));
        menubarOptionPor_canal->setText(QCoreApplication::translate("MainWindow", "Por canal", nullptr));
        menubarOptionAclarado->setText(QCoreApplication::translate("MainWindow", "Aclarado", nullptr));
        menubarOptionOscurecimiento->setText(QCoreApplication::translate("MainWindow", "Oscurecimiento", nullptr));
        lbl_image->setText(QString());
        lbl_histo->setText(QString());
        menuArchivo->setTitle(QCoreApplication::translate("MainWindow", "Archivo", nullptr));
        menuFiltros->setTitle(QCoreApplication::translate("MainWindow", "Filtros", nullptr));
        menuBinarizaci_n->setTitle(QCoreApplication::translate("MainWindow", "Binarizaci\303\263n", nullptr));
        menuExponencial_2->setTitle(QCoreApplication::translate("MainWindow", "Exponencial", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
