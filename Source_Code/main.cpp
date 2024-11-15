#include "mainmv.h"

#include <QApplication>
#include <QLocale>
#include <QTranslator>
#include <iostream>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QTranslator translator;
    const QStringList uiLanguages = QLocale::system().uiLanguages();
    for (const QString &locale : uiLanguages) {
        const QString baseName = "mv_file_" + QLocale(locale).name();
        if (translator.load(":/i18n/" + baseName)) {
            a.installTranslator(&translator);
            break;
        }
    }
    MainMV w;
    w.show();

    return a.exec();
}
