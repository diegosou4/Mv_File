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
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainMV
{
public:
    QWidget *centralwidget;
    QPushButton *pushButton;
    QLabel *label;
    QTableWidget *tableWidget;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainMV)
    {
        if (MainMV->objectName().isEmpty())
            MainMV->setObjectName("MainMV");
        MainMV->resize(800, 600);
        QFont font;
        font.setFamilies({QString::fromUtf8("Segoe UI Black")});
        MainMV->setFont(font);
        MainMV->setAutoFillBackground(false);
        MainMV->setStyleSheet(QString::fromUtf8("QWidget centralwidget{\n"
"	color: rgb(94, 33, 41);\n"
"}"));
        centralwidget = new QWidget(MainMV);
        centralwidget->setObjectName("centralwidget");
        centralwidget->setAutoFillBackground(false);
        centralwidget->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(280, 480, 131, 21));
        pushButton->setMinimumSize(QSize(131, 0));
        pushButton->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 0, 0);\n"
""));
        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setGeometry(QRect(230, 0, 311, 71));
        QFont font1;
        font1.setPointSize(22);
        font1.setWeight(QFont::Medium);
        font1.setHintingPreference(QFont::PreferDefaultHinting);
        label->setFont(font1);
        label->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));
        tableWidget = new QTableWidget(centralwidget);
        tableWidget->setObjectName("tableWidget");
        tableWidget->setGeometry(QRect(70, 100, 651, 311));
        QFont font2;
        font2.setPointSize(12);
        tableWidget->setFont(font2);
        tableWidget->setStyleSheet(QString::fromUtf8(""));
        tableWidget->horizontalHeader()->setDefaultSectionSize(150);
        tableWidget->verticalHeader()->setDefaultSectionSize(30);
        pushButton_2 = new QPushButton(centralwidget);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setGeometry(QRect(440, 480, 131, 21));
        pushButton_2->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 0, 0);"));
        pushButton_3 = new QPushButton(centralwidget);
        pushButton_3->setObjectName("pushButton_3");
        pushButton_3->setGeometry(QRect(590, 480, 131, 21));
        pushButton_3->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 0, 0);"));
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
        MainMV->setWindowTitle(QCoreApplication::translate("MainMV", "Move Files", nullptr));
        pushButton->setText(QCoreApplication::translate("MainMV", "Selecionar Arquivo", nullptr));
        label->setText(QCoreApplication::translate("MainMV", "      Move Files Progam", nullptr));
        pushButton_2->setText(QCoreApplication::translate("MainMV", "Mover Arquivos", nullptr));
        pushButton_3->setText(QCoreApplication::translate("MainMV", "Salvar Relatorio", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainMV: public Ui_MainMV {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINMV_H
