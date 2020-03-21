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
    QWidget *centralwidget;
    QLabel *lbl_image;
    QMenuBar *menubar;
    QMenu *menuArchivo;
    QMenu *menuFiltros;
    QMenu *menuHerramientas;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(775, 486);
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
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        lbl_image = new QLabel(centralwidget);
        lbl_image->setObjectName(QString::fromUtf8("lbl_image"));
        lbl_image->setGeometry(QRect(0, 0, 600, 400));
        lbl_image->setAlignment(Qt::AlignCenter);
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 775, 22));
        menuArchivo = new QMenu(menubar);
        menuArchivo->setObjectName(QString::fromUtf8("menuArchivo"));
        menuFiltros = new QMenu(menubar);
        menuFiltros->setObjectName(QString::fromUtf8("menuFiltros"));
        menuHerramientas = new QMenu(menubar);
        menuHerramientas->setObjectName(QString::fromUtf8("menuHerramientas"));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        menubar->addAction(menuArchivo->menuAction());
        menubar->addAction(menuFiltros->menuAction());
        menubar->addAction(menuHerramientas->menuAction());
        menuArchivo->addAction(actionNuevo);
        menuArchivo->addAction(menubarOptionOpen);
        menuFiltros->addAction(menubarOptionNegative);
        menuFiltros->addAction(menubarOptionGrayscale);
        menuFiltros->addAction(menubarOptionPower);
        menuHerramientas->addAction(actionHisograma);

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
        lbl_image->setText(QString());
        menuArchivo->setTitle(QCoreApplication::translate("MainWindow", "Archivo", nullptr));
        menuFiltros->setTitle(QCoreApplication::translate("MainWindow", "Filtros", nullptr));
        menuHerramientas->setTitle(QCoreApplication::translate("MainWindow", "Herramientas", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
