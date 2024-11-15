#ifndef FILEDATA_H
#define FILEDATA_H
#include "mainmv.h"

class fileData
{
private:
    QString _directory;
    QString _filename;
    int _exitstatus;
public:
    fileData();
    fileData(QString directory,QString filename);
    ~fileData();

    void setDirectory(QString directory);
    void setFileName(QString filename);
    void setExitStatus(int exit);
    QString getDirectory();
    QString getFileName();
    int getExitStatus();

};

#endif // FILEDATA_H
