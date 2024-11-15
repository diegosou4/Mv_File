/********************************************************************************
** Form generated from reading UI file 'mainmv.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINMV_H
#define UI_MAINMV_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainMV
{
public:
    QWidget *centralwidget;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainMV)
    {
        if (MainMV->objectName().isEmpty())
            MainMV->setObjectName("MainMV");
        MainMV->resize(800, 600);
        centralwidget = new QWidget(MainMV);
        centralwidget->setObjectName("centralwidget");
        MainMV->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainMV);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 21));
        MainMV->setMenuBar(menubar);
        statusbar = new QStatusBar(MainMV);
        statusbar->setObjectName("statusbar");
        MainMV->setStatusBar(statusbar);

        retranslateUi(MainMV);

        QMetaObject::connectSlotsByName(MainMV);
    } // setupUi

    void retranslateUi(QMainWindow *MainMV)
    {
        MainMV->setWindowTitle(QCoreApplication::translate("MainMV", "MainMV", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainMV: public Ui_MainMV {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINMV_H
