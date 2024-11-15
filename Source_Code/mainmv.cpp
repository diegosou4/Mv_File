#include "mainmv.h"
#include "ui_mainmv.h"
#include <QFileDialog>
#include <QMessageBox>
#include <QDebug>
#include <QCoreApplication>
#include <QString>
#include <QStringList>
#include <QDebug>
#include <QRegularExpression>
#include <QDir>
#include <QFileInfo>
#include <QFile>
#include <QDateTime>
#include <QProcess>


MainMV::MainMV(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainMV)
{

    ui->setupUi(this);

    ready = false;
}

MainMV::~MainMV()
{
    delete ui;
}

void MainMV::alloc_mydata(int size,QStringList myList)
{
    int i = 0,j= 0;


    this->myData = (fileData **)malloc(sizeof(fileData *) * size);
    while(i != size)
    {
        this->myData[i] = new fileData(myList[j + 1],myList[j]);

        i++;
        j += 2;
    }

    QMessageBox::information(this, "Ficheiro Lido", "O ficheiro foi lido com sucesso");
    this->ready = true;
}

QStringList splitMultipleDelimiters(const QString& text, const QString& delimiters) {
    QRegularExpression  regex("[" + delimiters + "]");
    return text.split(regex, Qt::SkipEmptyParts);
}

void MainMV::DestoyMydata()
{
    int i = 0;

    while(i != this->sizeFiles)
    {
        delete this->myData[i];
        i++;
    }

    this->ready = false;
    this->finish = false;
}
void MainMV::count_line(QString fileData)
{
    int sizemyData;
    QString delimiters = "\r\n;";
    QStringList result = splitMultipleDelimiters(fileData,delimiters);


    sizemyData = result.size();

    if(sizemyData % 2 == 1)
    {
        QMessageBox::warning(this,"Aviso", "Existe algum campo invalido, por favor verifique o ficheiro");
        return;
    }
    sizeFiles = sizemyData / 2;
    alloc_mydata((sizemyData / 2),result);
    ShowInfoUi((sizemyData / 2));
}

void MainMV::ShowInfoUi(int size)
{

    int i = 0;
    this->ui->tableWidget->setStyleSheet("QTableWidget { color: black; }");
    this->ui->tableWidget->setRowCount(size);
    this->ui->tableWidget->setColumnCount(2);
    while(i < this->sizeFiles)
    {
        ui->tableWidget->setItem(i, 0, new QTableWidgetItem(this->myData[i]->getFileName()));
        ui->tableWidget->setItem(i, 1, new QTableWidgetItem(this->myData[i]->getDirectory()));
        i++;
    }
    this->ready = true;
}

void MainMV::on_pushButton_clicked()
{
    QString filename = QFileDialog::getOpenFileName(
        this,
        tr("Open File"),
        "C://",
        "Csv Separado por Virgula (*.csv*)"
        );
    this->finish = false;
    if(filename == nullptr)
        QMessageBox::warning(this,"Aviso","Nao foi encontrado nenhum arquivo");
    else
        QMessageBox::information(this,tr("Arquivo carregado com sucesso"),filename);
    qDebug() << filename;

    QFile filecsv(filename);

    if(!filecsv.open(QIODevice::ReadOnly))
    {
        QMessageBox::warning(this,"Aviso", "Ocorreu um erro ao tentar abrir o ficheiro");
        return;
    }
    QString contentStr;
    while(!filecsv.atEnd())
    {
        QByteArray line = filecsv.readAll();
        contentStr = QString::fromUtf8(line);
    }
    filecsv.close();
    count_line(contentStr);

}

void MainMV::createDirectories()
{
    QDir dir;
    for(int i =0;i != this->sizeFiles;i++)
    {
        QString directory = main_directory + "/" + this->myData[i]->getDirectory();
        if(!dir.exists(directory))
            dir.mkpath(directory);
    }
    qDebug() << "Diretorios criado com sucesso";
}



void MainMV::move_files()
{
    int i = 0;
    qDebug() << this->sizeFiles;
    createDirectories();
    while(i != this->sizeFiles)
    {
        QString destino = main_directory + "/" + this->myData[i]->getDirectory() + "/" + this->myData[i]->getFileName();
        QString origem = main_directory + "/" + this->myData[i]->getFileName();
        QFile myf(origem);
        QFileInfo check(origem);


        if(!myf.exists())
        {
            qDebug() << "Arquivo nao existe " << origem << "\n";
            this->myData[i]->setExitStatus(0);
        }else if(check.isFile() == false)
        {
            qDebug() << "E um diretorio " << origem << "\n";
            this->myData[i]->setExitStatus(0);
        }

        if (this->myData[i]->getExitStatus() == -1 && myf.copy(destino))
        {
            qDebug() << "O Arquivo foi copiado " << origem << "\n";
            this->myData[i]->setExitStatus(1);
            myf.remove();
        } else if(this->myData[i]->getExitStatus() == -1){
            qDebug() << "O Arquivo nao foi copiado " << origem << "\n";
            this->myData[i]->setExitStatus(2);
        }
        i++;
    }

    for(int j = 0; j != sizeFiles;j++)
    {
        qDebug() << "File Name" << this->myData[j]->getFileName() << "Directory" << this->myData[j]->getDirectory() << " Exit Status " << this->myData[j]->getExitStatus();
    }
    this->finish = true;
    qDebug() << "Sucesso";
}

void MainMV::on_pushButton_2_clicked()
{

    bool ok = false;
    if(this->ready == false)
    {
        QMessageBox::critical(this,"Alerta", "Nenhum ficheiro foi carregado ainda");
        return;
    }
    QMessageBox::information(this,"Informar Caminho","Por favor informe o caminho do Diretorio");
    main_directory = QFileDialog::getExistingDirectory(this,tr("Selecionar Diretorio"));
    ok = true;
    if(ok == true)
    {
         move_files();
    }

}

void MainMV::generateReport()
{
    QString result_directory;
    QString report_directory;
    QMessageBox::information(this, "Informar Caminho", "Por favor informe o caminho aonde quer Salvar o Relatório");
    report_directory = QFileDialog::getExistingDirectory(this, tr("Selecionar Diretório"));

    QDateTime UTC = QDateTime::currentDateTimeUtc();
    QString formattedDate = UTC.toString("dd-MM-yyyy_HH-mm");

    result_directory = report_directory + "/" + "report_" + formattedDate + ".csv";

    QFile CSVFile(result_directory);
    int size = 0;
    if (!CSVFile.open(QIODevice::Append))
    {
        QMessageBox::warning(this, "Aviso", "Ocorreu um erro ao tentar salvar o ficheiro");
        return;
    }
    QTextStream Stream(&CSVFile);

    Stream << "Ficheiro"
           << ";" << "Diretorio"
           << ";" << "Resultado" <<  "\n";
       qDebug() << "Quebra aqui";

    while (size < this->sizeFiles)
    {
        int index = 0;
        index = this->myData[size]->getExitStatus();
        QStringList myList = { "Ficheiro nao Existe", this->myData[size]->getDirectory(), "Error" };

        Stream <<  this->myData[size]->getFileName()
               << ";" << this->myData[size]->getDirectory()
               << ";" << myList[index] << "\n";
        size++;
    }

    CSVFile.close();
    QMessageBox::information(this,tr("Arquivo salvo com sucesso"),result_directory);
}


void MainMV::on_pushButton_3_clicked()
{
    if(this->ready == false || this->finish == false)
    {
        QMessageBox::critical(this,"Alerta", "Nenhum ficheiro foi carregando ainda, ou houve um problema na execucao do progama por favor tente novamente!");
        return;
    }
    generateReport();
    DestoyMydata();

}

