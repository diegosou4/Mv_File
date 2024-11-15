#ifndef MAINMV_H
#define MAINMV_H

#include <QMainWindow>
#include <QCoreApplication>
#include <QSqlDatabase>
#include <QSqlError>
#include <QDebug>
#include <QFile>
#include <QTextStream>
#include <QStringList>
#include <QDebug>
#include <QFileDialog>
#include "filedata.h"

class fileData;

QT_BEGIN_NAMESPACE
namespace Ui {
class MainMV;
}
QT_END_NAMESPACE

class MainMV : public QMainWindow
{
    Q_OBJECT

public:
    MainMV(QWidget *parent = nullptr);
    void count_line(QString fileData);
    void alloc_mydata(int size,QStringList myList);
    void ShowInfoUi(int size);
    void move_files();
    void  generateReport();
    void createDirectories();
    void DestoyMydata();
    ~MainMV();

private slots:
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();
    void on_pushButton_3_clicked();

private:
    Ui::MainMV *ui;
    fileData **myData;
    bool ready;
    bool finish;
    int sizeFiles;
    QString main_directory;
};
#endif // MAINMV_H
